/* 
 * File:   Control2.cpp
 * Author: cottin_j
 * 
 * Creuted on February 11, 2012, 3:24 PM
 */


#include "Control.hpp"

Control::Control(std::string & data)
{

  this->entry = new Input();
  this->process = new Processor;
  lexem_list = this->entry->lexing(data);
  ut = this->lexem_list.begin();
  fill_vector_comp();
  fill_map();
  fill_vector_type();
}

Control::~Control()
{
  delete process;
  delete entry;
}

void Control::new_data(std::string & data)
{
  try
    {
      lexem_list.clear();
      lexem_list = this->entry->lexing(data);
    }
  catch (const bad_argument & err)
    {
      //std::cerr << err.getWord() << std::endl;
      throw;
    }
}

void Control::parsing()
{
  try
  {
    for (ut = this->lexem_list.begin(); ut != this->lexem_list.end();)
    {
      if (!(dispatch_clean()))
      {
        lexem_list.clear();
        return;
      }
    }
    throw bad_argument("No Exit Instruction ", " : fail");
  }
  catch (const bad_argument & err)
  {
    //std::cerr << err.getWord() << std::endl;
    throw;
  }
}

bool Control::dispatch_clean()
{
  std::string one_arg("pop>dump>add>sub>mul>div>mod>exit>print");
  std::string more_arg("push>assert");

  if ((one_arg.find(*ut) != std::string::npos))
  {
    one_arg_func();
    return true;
  }
  else
  {
    if (more_arg_func())
    {
      return true;
    }
    return false;
  }
}

bool Control::one_arg_func()
{
  std::string casing(*ut);
  int total = 0;

  for (std::string::iterator lg = casing.begin(); lg != casing.end(); lg++)
    total += *lg;
  try
  {
    switch (total) {
    case 335: process->pop();
      break;
    case 438: process->dump();
      break;
    case 297: process->add();
      break;
    case 330: process->sub();
      break;
    case 334: process->mul();
      break;
    case 323: process->div();
      break;
    case 320: process->mod();
      break;
    case 442: endOfProgram();
      break;
    case 557: process->print();
    }
  }
  catch (const error & err)
  {
    //std::cerr << "ERROR : " << err.getMessage() << std::endl;
    throw;
  }
  ut++;
  return true;
}

bool Control::more_arg_func()
{
  std::string lex;

  if (*ut == "push")
  {
    lex = *ut;
    ut++;
    if (ut != lexem_list.end() && scan_type())
    {
      process->push((eOperandType) e_val, *ut);
      ut++;
      return true;
    }
  }
  else if (*ut == "assert")
  {
    lex = *ut;
    ut++;
    if (ut != lexem_list.end() && scan_type())
    {
      process->assert((eOperandType) e_val, *ut);
      ut++;
      return true;
    }
  }
  throw bad_argument("Argument incorrect : ", *ut);
  return false;
}

bool Control::scan_type()
{
  std::map<std::string, eOperandType>::iterator itmap;


  itmap = enum_map.find(*ut);
  if (itmap != enum_map.end())
  {
    e_val = (*itmap).second;
    ut++;
    if (!(scan_value()))
    {
      throw bad_argument("Incorrect or Absent value ", *ut);
      return false;
    }
    return true;
  }
  throw bad_argument("Incorrect or Absent type ", *ut);
  return false;
}

void Control::endOfProgram()
{
  throw good_exit("exit");
}

bool Control::scan_value()
{
  if (find(to_type.begin(), to_type.end(), (*ut)) != to_type.end() ||
      find(to_comp.begin(), to_comp.end(), (*ut)) != to_comp.end())
    return false;

  std::vector<std::string>::iterator olol;

  if (find(to_type.begin(), to_type.end(), (*--ut)) != to_type.end())
  olol = find(to_type.begin(), to_type.end(), *ut);

  if (*olol == to_type[0] || *olol == to_type[1] || *olol == to_type[2])
  {
    if ((*++ut).find_first_of(".") != std::string::npos)
    {
      throw bad_argument("Incorrect format for Int* Value ", *ut);
      return false;
    }
    else
    {
      //if ((test_over_under_flow()))
      return true;
      //return false;
    }
  }
  else if (*olol == to_type[3] || *olol == to_type[4])
  {
    ut++;
    //if ((test_over_under_flow()))
    return true;
  }
  return false;
}

void Control::fill_vector_type()
{

  to_type.push_back("int8");
  to_type.push_back("int16");
  to_type.push_back("int32");
  to_type.push_back("float");
  to_type.push_back("double");
}

void Control::fill_vector_comp()
{
  to_comp.push_back("push");
  to_comp.push_back("pop");
  to_comp.push_back("dump");
  to_comp.push_back("assert");
  to_comp.push_back("add");
  to_comp.push_back("sub");
  to_comp.push_back("mul");
  to_comp.push_back("div");
  to_comp.push_back("mod");
  to_comp.push_back("print");
  to_comp.push_back("exit");
}

bool Control::test_over_under_flow()
{
  std::map<std::string, eOperandType>::iterator itmap;

  std::istringstream big_stream(*ut);
  long double big;
  big_stream >> big;

  itmap = enum_map.find(*--ut);
  ut++;
  if (itmap != enum_map.end())
  {
    switch ((*itmap).second) {
    case 0: return (big <= CHAR_MAX && big >= CHAR_MIN) ? true: false;
      break;
    case 1: return (big <= SHRT_MAX && big >= SHRT_MIN) ? true: false;
      break;
    case 2: return (big <= INT_MAX && big >= INT_MIN) ? true: false;
      break;
    case 3: return (big <= FLT_MAX && big >= FLT_MIN) ? true: false;
      break;
    case 4: return (big <= LDBL_MAX && big >= DBL_MIN) ? true: false;
      break;
    }
  }
  return true;
}

void Control::fill_map()
{
  enum_map["int8"] = INT8;
  enum_map["int16"] = INT16;
  enum_map["int32"] = INT32;
  enum_map["float"] = FLOAT;
  enum_map["double"] = DOUBLE;
}

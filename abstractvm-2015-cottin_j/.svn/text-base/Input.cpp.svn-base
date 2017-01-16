#include "Input.hpp"

Input::Input()
{
  fill_vector_comp();
  fill_vector_type();
}

Input::~Input()
{
}

std::list<std::string> Input::lexing(std::string & data)
{
  std::string::iterator it;
  std::string lexem;
  std::string data_clean;

  lexem_list.clear();
  clean_it(data, data_clean);

  for (it = data_clean.begin(); it < data_clean.end(); it++)
  {
    for (; it < data_clean.end() && *it == ' ' || *it == ' '; it++);
    while (it < data_clean.end() && *it != ' ' && *it != '\n' && *it != '(')
    {
      lexem += *it;
      it++;
    }
    if (compare(lexem))
    {
      lexem_list.push_back(lexem);
      lexem.clear();
    }
    if (*it == '(')
    {
      it++;
      while (*it != ')' && *it >= '0' && *it <= '9' || *it == '.' || *it == '-')
        lexem += *it++;
      if (*it == ')')
      {        
        if (scan_value(lexem))
        {
          lexem_list.push_back(lexem);
        }
        else
          throw bad_argument("Argument incorrect ", lexem);
        lexem.clear();
      }
    }
  }
  return lexem_list;
}

void Input::clean_it(std::string & data, std::string & data_clean)
{
  std::string::iterator it;
  for (it = data.begin(); it != data.end(); it++)
  {
    if (*it == ';' && *++it != ';')
    {
      while (it != data.end() && *it != '\n')
        it++;
    }
    else if (*it == '\n')
      data_clean += ' ';
    else
      data_clean += *it;
  }
}

int Input::compare(std::string & lexem)
{
  if (find(to_comp.begin(), to_comp.end(), lexem) != to_comp.end())
  {
    return (1);
  }
  if (find(to_type.begin(), to_type.end(), lexem) != to_type.end())
  {
    return (1);
  }
  if (lexem.size() > 0)
  {
    throw bad_argument("Argument incorrect ", lexem);
    lexem.clear();
    return (0);
  }
  return (1);
}

void Input::i_print_elem() const
{
  for_each(lexem_list.begin(), lexem_list.end(), *this);
}

void Input::operator()(std::string const & elem) const
{
  std::cout << elem << std::endl;
}

bool Input::scan_value(std::string & lexem)
{
  if ((lexem).find_first_of('-') != 0 && (lexem).find_first_of('-') != std::string::npos)
    return false;
  if ((lexem).find_first_of('-') == (lexem).find_first_of('.') ||
      (lexem).find_first_of('-') == (lexem).find_last_of('-') &&
      (lexem).find_first_of('.') == (lexem).find_last_of('.'))
    return true;
  return false;
}

void Input::fill_vector_type()
{
  to_type.push_back("int8");
  to_type.push_back("int16");
  to_type.push_back("int32");
  to_type.push_back("float");
  to_type.push_back("double");
}

void Input::fill_vector_comp()
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

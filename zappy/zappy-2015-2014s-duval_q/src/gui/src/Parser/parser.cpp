#include <iostream>
#include <sstream>
#include <string>
#include <list>
#include "parser.hpp"
#include "color.hpp"

parser::parser()
{
  this->_func["msz"] = &pfunc::fpmsz;
  this->_func["bct"] = &pfunc::fpbct;
  this->_func["tna"] = &pfunc::fptna;
  this->_func["pnw"] = &pfunc::fppnw;
  this->_func["ppo"] = &pfunc::fpppo;
  this->_func["plv"] = &pfunc::fpplv;
  this->_func["pin"] = &pfunc::fppin;
  this->_func["pex"] = &pfunc::fppex;
  this->_func["pbc"] = &pfunc::fppbc;
  this->_func["pic"] = &pfunc::fppic;
  this->_func["pie"] = &pfunc::fppie;
  this->_func["pfk"] = &pfunc::fppfk;
  this->_func["pdr"] = &pfunc::fppdr;
  this->_func["pgt"] = &pfunc::fppgt;
  this->_func["pdi"] = &pfunc::fppdi;
  this->_func["enw"] = &pfunc::fpenw;
  this->_func["eht"] = &pfunc::fpeht;
  this->_func["ebo"] = &pfunc::fpebo;
  this->_func["edi"] = &pfunc::fpedi;
  this->_func["sgt"] = &pfunc::fpsgt;
  this->_func["seg"] = &pfunc::fpseg;
  this->_func["smg"] = &pfunc::fpsmg;
  this->_func["suc"] = &pfunc::fpsuc;
  this->_func["sbp"] = &pfunc::fpsbp;
}

parser::~parser()
{ }

void	parser::parse(std::string &str)
{
  std::istringstream    input(str);
  std::string           buffer;

  while (input)
    {
      buffer.clear();
      getline(input, buffer);
      if (buffer.size() > 0)
        {
          this->_list.push_back(buffer);
	  std::cout << "Receive : " << buffer << std::endl;
        }
    }
}

bool    parser::interpret(game::data &data)
{
  std::list<std::string>::iterator      it;
  std::string				fname;

  if (this->_list.size() == 0)
    return (true);
  for (it = _list.begin(); it != _list.end(); it++)
  {
    fname = it->substr(0, 3);

    if (this->_func.count(fname) > 0)
      this->_func[fname](data, *it);
    else
      std::cerr << color::red << "Parser : Commande invalide - " << color::white << *it << std::endl;
  }
  _list.clear();
  return (true);
}

const std::string       parser::getFirstString() const
{
  if (this->_list.size() == 0)
    return ("");
  return (this->_list.front());
}

void parser::delFirstString()
{
  if (this->_list.size() > 0)
    this->_list.pop_front();
}

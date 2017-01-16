//
// State.cpp for  in /home/pincho_m//projet/rush/purgatory/etape3
// 
// Made by mathieu pinchon
// Login   <pincho_m@epitech.net>
// 
// Started on  Sat Dec 15 17:25:45 2012 mathieu pinchon
// Last update Sun Dec 16 01:19:14 2012 mathieu pinchon
//

#ifndef		STATE_HPP
#define		STATE_HPP

#include	<string>
#include	<iostream>
#include	<map>
#include	<list>
#include	"Edge.hpp"

class State
{
  std::map<std::string*, Edge*>	other;
  std::list<std::string*>	mist;
  std::string			name;
  bool				final;
  State()
  {
  }

  State(const std::string& enter)
  {
    final = false;
    name = enter;
    std::cout << name << " is create" <<std::endl;
  }

  ~State()
  {
    delete this;
  }

public	:
  Edge				 *val;
  static State*	create()
  {
    static int	i = 48;
    if (i > 57 )
      return NULL;
    std::string	name = "S";
    return new State(name += i++);
  }

  void	setFinal(const bool enter)
  {
    final = enter;
  }

  std::string&	getName()
  {
    return(name);
  }

  const bool	isFinal() const
  {
    return (final);
  }

  void		addCollect(std::list<std::string*>& collect)
  {
    collect.push_back(&name);
  }

  void	addState(std::string* enter)
  {
    mist.push_back(enter);
  }

 const std::string*	getLink()
  {
    std::map<std::string*, Edge*>::iterator it = other.begin();

    return ((*it).first);
  }

  void	addMap(Edge* const edge, std::string* const enter)
  {
    other.insert(std::pair<std::string*, Edge*>(enter, edge));
  }
};

#endif

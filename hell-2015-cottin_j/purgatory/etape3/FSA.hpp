//
// FSA.cpp for  in /home/pincho_m//projet/rush/purgatory/etape3
// 
// Made by mathieu pinchon
// Login   <pincho_m@epitech.net>
// 
// Started on  Sat Dec 15 22:34:15 2012 mathieu pinchon
// Last update Sun Dec 16 01:04:58 2012 mathieu pinchon
//

#ifndef	FSA_HPP
#define FSA_HPP

#include	<list>
#include	<string>
#include	"State.hpp"

 class FSA
{
  std::list<State*>	all;
  State			*start;
public:
  FSA()
  {
  }
  ~FSA()
  {
  }

  /*set configuration for match*/

  bool addState(const char val)
  {
    State	*state = State::create();

    if (state == NULL)
      return false;
    all.push_back(state);
    state->val = new Edge(val);
    return true;
  }

  bool	setStart(const std::string& enter)
  {
    std::list<State*>::iterator	it = all.begin();
    while (it != all.end())
      {
	if (enter == (*it)->getName())
	  {
	    std::cout << "set start ok" << std::endl;
	    start = (*it);
	    return true;
	  }
	it++;
      }
    return false;
  }

  void	setLink()
  {
    std::list<State*>::iterator	it = all.begin();
    std::list<State*>::iterator	prec = all.begin();

    it++;
    while (it != all.end())
      {
	(*prec)->addMap((*it)->val, &(*it)->getName());
	it++;
	prec++;
      }
  }

  State*	getStart()
  {
    return (start);
  }

  bool	setEnd(const std::string& enter)
  {
    std::list<State*>::iterator	it = all.begin();
    while (it != all.end())
      {
	if (enter == (*it)->getName())
	  {
	    std::cout << "End set" << std::endl;
	    (*it)->setFinal(true);
	    return true;
	  }
	it++;
      }
    return false;
  }

  bool	unsetEnd()
  {
    std::list<State*>::iterator	it = all.begin();
    while (it != all.end())
      {
	if ((*it)->isFinal() == false)
	  {
	    (*it)->setFinal(false);
	    return true;
	  }
	it++;
      }
    return false;
  }

  State*	operator[](const std::string& enter)
  {
    std::list<State*>::iterator	it = all.begin();
    while (it != all.end())
      {
	if (enter == (*it)->getName())
	  {
	    return (*it);
	  }
	it++;
      }
    return NULL;
  }
};
#endif

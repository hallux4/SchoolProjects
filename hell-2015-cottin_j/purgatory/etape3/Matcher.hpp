//
// Matcher.hpp for  in /home/pincho_m//projet/rush/purgatory/etape3
// 
// Made by mathieu pinchon
// Login   <pincho_m@epitech.net>
// 
// Started on  Sun Dec 16 00:07:59 2012 mathieu pinchon
// Last update Sun Dec 16 02:34:58 2012 mathieu pinchon
//

#ifndef	MATCHER_HPP
#define	MATCHER_HPP

#include "FSA.hpp"

class Matcher
{
  FSA	mach;

public:
  Matcher(const FSA& machine)
  {
    mach = machine;
    mach.addState('m');
    mach.addState('e');
    mach.addState('c');
    mach.addState('h');
    mach.addState('a');
    mach.addState('n');
    mach.addState('t');
    mach.setStart("S0");
    mach.setEnd("S6");
    mach.setLink();
  }

  ~Matcher()
  {
  }

  bool	find(const char* str)
  {
    State	*current;
    int		i = 0;
    bool	o = false;

    current = mach.getStart();
    while(str[i])
      {
	if (current->val->compare(str[i]) == true)
	  {
	    if (current->isFinal() == false)
	      current = mach[*(current->getLink())];
	    else
	      {
		o = true;
		std::cout << "mechant trouver" << std::endl;	    
	      }
	  }
	else
	  current = mach.getStart();
	if (current->isFinal() == true || current->val->compare(str[i]) == false)
	  i++;
      }
    return (o);
  }

  bool	find(const char* str, int & nbr)
  {
    State	*current;
    int		i = 0;
    bool	o = false;
    nbr = 0;
    current = mach.getStart();
    while(str[i])
      {
	if (current->val->compare(str[i]) == true)
	  {
	    if (current->isFinal() == false)
	      current = mach[*(current->getLink())];
	    else
	      {
		nbr++;
		o = true;
		std::cout << "mechant trouver" << std::endl;
	      }
	  }
	else
	  current = mach.getStart();
	if (current->isFinal() == true || current->val->compare(str[i]) == false)
	  i++;
      }
    return (o);
  }
};

#endif

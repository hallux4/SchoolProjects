//
// main.cpp for  in /home/pincho_m//projet/rush/purgatory/etape1
// 
// Made by mathieu pinchon
// Login   <pincho_m@epitech.net>
// 
// Started on  Sat Dec 15 14:41:31 2012 mathieu pinchon
// Last update Sat Dec 15 18:02:00 2012 mathieu pinchon
//

#include	"Machine.hpp"
#include	<iostream>
#include	<string>

class StateMachine
{
public:
  StateMachine(const char *arg)
  {
    int	i = 0;
    int	pos = 0;
    std::string	name = "mechant";
    enum eState	current;

    while (arg[i])
      {
	if (name[pos] == arg[i])
	  {
	    if (gActionTable[current][pos] == MA)
	      {
		std::cout << arg[i] << std::endl;
		std::cout << "On avance" << std::endl;
		current = gStateTable[current][pos];
		i++;
		pos++;
	      }
	    if (gActionTable[current][pos] == HR)
	      {
		std::cout << "mechant trouve(e)" << std::endl;
		current = S0;
		pos = 0;
	      }
	  }
	else if (pos == 2 && arg[i] == 'e')
	  {
	    std::cout << arg[i] << std::endl;
	    std::cout << "On avance" << std::endl;
	    i++;
	  }
	else if (pos == 0)
	  i++;
	else
	  pos = 0;
      }
  }
  ~StateMachine(){}
};




int	main(int ac, char **av)
{
  if (ac < 2)
    return(0);
  StateMachine	enter(av[1]);
}

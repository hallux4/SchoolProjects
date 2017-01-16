#ifndef		STATELEARNWORLDSIZE_HPP_
# define	STATELEARNWORLDSIZE_HPP_

#include	<iostream>

#include	"State.hh"
#include	"Player.hh"

class StateLearnWorldSize : public State<Player>
{
public:
  StateLearnWorldSize()
    :State<Player>("world size")
  {
  }

  ~StateLearnWorldSize(){}

  virtual void begin(Player *target)
  {
    (void)target;
    std::cout << "gettin world size" << std::endl;
  }

  virtual void execute(Player *target)
  {
    std::list<std::string> worldSize = target->getLastRequest().getNumericList();
    std::list<std::string>::iterator it = worldSize.begin();
    std::cout << "world size ["
              << (*it)
              << "x";
    it++;
    std::cout << (*it)
              << "]"
              << std::endl;
  }

  virtual void end(Player *target)
  {
    (void)target;
  }
};

#endif	/*	STATEAVANCE_HPP_	*/

#ifndef		STATECHOOSECAMP_HPP_
# define	STATECHOOSECAMP_HPP_

#include	<iostream>

#include	"State.hh"
#include	"Player.hh"

class StateChooseCamp : public State<Player>
{
public:
  StateChooseCamp()
    :State<Player>("team choice")
  {
  }

  ~StateChooseCamp(){}

  virtual void begin(Player *target)
  {
    (void)target;
  }

  virtual void execute(Player *target)
  {
    (void)target;
    std::cout << "I am the player : " << target->getLastRequest().getNumericList().front() << std::endl;
  }

  virtual void end(Player *target)
  {
    (void)target;
  }
};

#endif	/*	STATEAVANCE_HPP_	*/

#ifndef		STATEIMMOBILE_HPP_
# define	STATEIMMOBILE_HPP_

#include	<iostream>

#include	"State.hh"
#include	"Player.hh"

class StateImmobile : public State<Player>
{
public:
  StateImmobile()
    :State<Player>("immobile")
  {
  }

  ~StateImmobile(){}

  virtual void begin(Player *target)
  {
    (void)target;
    std::cout << "begin immobile" << std::endl;
  }

  virtual void execute(Player *target)
  {
    (void)target;
    std::cout << "execute immobile" << std::endl;
  }

  virtual void end(Player *target)
  {
    (void)target;
    std::cout << "end immobile" << std::endl;
  }
};

#endif	/*	STATEIMMOBILE_HPP_	*/

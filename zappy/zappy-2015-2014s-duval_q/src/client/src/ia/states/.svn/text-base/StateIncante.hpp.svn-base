#ifndef		STATEINCANTE_HPP_
# define	STATEINCANTE_HPP_

#include	<iostream>

#include	"State.hh"
#include	"Player.hh"

class StateIncante : public State<Player>
{
public:
  StateIncante()
    :State<Player>("incante")
  {
  }

  ~StateIncante(){}

  virtual void begin(Player *target)
  {
    std::string tmp = this->getName();
    target->request(tmp);
  }

  virtual void execute(Player *target)
  {
    (void)target;
    std::cout << "execute incante" << std::endl;
  }

  virtual void end(Player *target)
  {
    (void)target;
    std::cout << "end incante" << std::endl;
  }
};

#endif	/*	STATEAVANCE_HPP_	*/

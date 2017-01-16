#ifndef		STATEAVANCE_HPP_
# define	STATEAVANCE_HPP_

#include	<iostream>

#include	"State.hh"
#include	"Player.hh"

class StateAvance : public State<Player>
{
public:
  StateAvance()
    :State<Player>("avance")
  {
  }

  ~StateAvance(){}

  virtual void begin(Player *target)
  {
    std::string tmp = this->getName();
    target->request(tmp);
  }

  virtual void execute(Player *target)
  {
    (void)target;
  }

  virtual void end(Player *target)
  {
    (void)target;
    std::cout << "end avance" << std::endl;
  }
};

#endif	/*	STATEAVANCE_HPP_	*/

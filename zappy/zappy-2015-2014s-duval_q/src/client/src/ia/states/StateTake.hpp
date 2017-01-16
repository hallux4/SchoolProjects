#ifndef		STATETAKE_HPP_
# define	STATETAKE_HPP_

#include	<iostream>

#include	"State.hh"
#include	"Player.hh"

class StateTake : public State<Player>
{
public:
  StateTake()
    :State<Player>("take")
  {
  }

  ~StateTake(){}

  virtual void begin(Player *target)
  {
    (void)target;
    std::cout << "begin take" << std::endl;
  }

  virtual void execute(Player *target)
  {
    (void)target;
    std::cout << "execute take" << std::endl;
  }

  virtual void end(Player *target)
  {
    (void)target;
    std::cout << "end take" << std::endl;
  }
};

#endif	/*	STATEAVANCE_HPP_	*/

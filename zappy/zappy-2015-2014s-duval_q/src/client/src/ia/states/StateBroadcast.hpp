#ifndef		STATEBROADCAST_HPP_
# define	STATEBROADCAST_HPP_

#include	<iostream>

#include	"State.hh"
#include	"Player.hh"

class StateBroadcast : public State<Player>
{
public:
  StateBroadcast()
    :State<Player>("broadcast")
  {
  }

  ~StateBroadcast(){}

  virtual void begin(Player *target)
  {
    (void)target;
    std::cout << "begin broadcast" << std::endl;
  }

  virtual void execute(Player *target)
  {
    (void)target;
    std::cout << "execute broadcast" << std::endl;
  }

  virtual void end(Player *target)
  {
    (void)target;
    std::cout << "end broadcast" << std::endl;
  }
};

#endif	/*	STATEBROADCAST_HPP_	*/

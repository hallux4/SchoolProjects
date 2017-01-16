#ifndef		STATEDROP_HPP_
# define	STATEDROP_HPP_

#include	<iostream>

#include	"State.hh"
#include	"Player.hh"

class StateDrop : public State<Player>
{
public:
  StateDrop()
    :State<Player>("drop")
  {
  }

  ~StateDrop(){}

  virtual void begin(Player *target)
  {
    (void)target;
    std::cout << "begin drop" << std::endl;
  }

  virtual void execute(Player *target)
  {
    (void)target;
    std::cout << "execute drop" << std::endl;
  }

  virtual void end(Player *target)
  {
    (void)target;
    std::cout << "end drop" << std::endl;
  }
};

#endif	/*	STATEDROP_HPP_	*/

#ifndef		STATELOOK_HPP_
# define	STATELOOK_HPP_

#include	<iostream>

#include	"State.hh"
#include	"Player.hh"

class StateLook : public State<Player>
{
public:
  StateLook()
    :State<Player>("voir")
  {
  }

  ~StateLook(){}

  virtual void begin(Player *target)
  {
    std::string tmp = this->getName();
    target->request(tmp);
  }

  virtual void execute(Player *target)
  {
    (void)target;
    std::cout << "execute look" << std::endl;
  }

  virtual void end(Player *target)
  {
    (void)target;
    std::cout << "end look" << std::endl;
  }
};

#endif	/*	STATEAVANCE_HPP_	*/

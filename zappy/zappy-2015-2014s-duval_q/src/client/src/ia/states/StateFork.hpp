#ifndef		STATEFORK_HPP_
# define	STATEFORK_HPP_

#include	<iostream>

#include	"State.hh"
#include	"Player.hh"

class StateFork : public State<Player>
{
public:
  StateFork()
    :State<Player>("fork")
  {
  }

  ~StateFork(){}

  virtual void begin(Player *target)
  {
    std::string tmp = this->getName();
    target->request(tmp);
  }

  virtual void execute(Player *target)
  {
    (void)target;
    std::cout << "execute fork" << std::endl;
  }

  virtual void end(Player *target)
  {
    (void)target;
    std::cout << "end fork" << std::endl;
  }
};

#endif	/*	STATEAVANCE_HPP_	*/

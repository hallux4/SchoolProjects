#ifndef		STATEDROITE_HPP_
# define	STATEDROITE_HPP_

#include	<iostream>

#include	"State.hh"
#include	"Player.hh"

class StateDroite : public State<Player>
{
public:
  StateDroite()
    :State<Player>("droite")
  {
  }

  ~StateDroite(){}

  virtual void begin(Player *target)
  {
    std::string tmp = this->getName();
    target->request(tmp);
  }

  virtual void execute(Player *target)
  {
    (void)target;
    std::cout << "execute droite" << std::endl;
  }

  virtual void end(Player *target)
  {
    (void)target;
    std::cout << "end droite" << std::endl;
  }
};

#endif	/*	STATEDROITE_HPP_	*/

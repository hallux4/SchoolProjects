#ifndef		STATEGAUCHE_HPP_
# define	STATEGAUCHE_HPP_

#include	<iostream>

#include	"State.hh"
#include	"Player.hh"

class StateGauche : public State<Player>
{
public:
  StateGauche()
    :State<Player>("gauche")
  {
  }

  ~StateGauche(){}

  virtual void begin(Player *target)
  {
    std::string tmp = this->getName();
    target->request(tmp);
  }

  virtual void execute(Player *target)
  {
    (void)target;
    std::cout << "execute gauche" << std::endl;
  }

  virtual void end(Player *target)
  {
    (void)target;
    std::cout << "end gauche" << std::endl;
  }
};

#endif	/*	STATEGAUCHE_HPP_	*/

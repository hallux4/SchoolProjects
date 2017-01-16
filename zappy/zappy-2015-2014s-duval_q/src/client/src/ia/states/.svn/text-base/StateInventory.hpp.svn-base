#ifndef		STATEINVENTORY_HPP_
# define	STATEINVENTORY_HPP_

#include	<iostream>

#include	"State.hh"
#include	"Player.hh"

class StateInventory : public State<Player>
{
public:
  StateInventory()
    :State<Player>("inventaire")
  {
  }

  ~StateInventory(){}

  virtual void begin(Player *target)
  {
    std::string tmp = this->getName();
    target->request(tmp);
  }

  virtual void execute(Player *target)
  {
    std::cout << "nourriture : "
	      << target->getLastRequest().getNumberInInventory("nourriture")
	      << std::endl;
  }

  virtual void end(Player *target)
  {
    (void)target;
    std::cout << "end inventory" << std::endl;
  }
};

#endif	/*	STATEAVANCE_HPP_	*/

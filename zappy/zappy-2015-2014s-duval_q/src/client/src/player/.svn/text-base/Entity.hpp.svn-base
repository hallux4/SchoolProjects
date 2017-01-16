#ifndef		ENTITY_HPP_
# define	ENTITY_HPP_

#include	"StateMachine.hh"

class Entity
{
private:
  int	UID;
  void	setID(int val)
  {
    this->UID = val;
  }
public:
  Entity(int id)
  {
    setID(id);
  }
  virtual ~Entity(){}
  virtual bool	update() = 0;
  int	getID() const
  {
    return (this->UID);
  }
};

#endif	/*	ENTITY_HPP_	*/

#include <iostream>
#include "game.hpp"
#include "gui.hpp"

namespace game
{
  tiles::tiles() : _incantation(false)
  {
    for (int i = 0; i < 7; i++)
      this->_ressources[i] = 0;
  }

  void	tiles::setRess(game::e_sprite type, int nb)
  {
    if (type < FOOD || type > THYSTAME)
      std::cerr << "game::tiles::set : ressource inconnue (" << type << ")" << std::endl;
    else
      this->_ressources[type] = nb;
  }

  void	tiles::setIncant(bool incant)
  {
    this->_incantation = incant;
  }

  int	tiles::getRess(game::e_sprite type) const
  {
    if (type < FOOD || type > THYSTAME)
      {
	std::cerr << "game::tiles::set : ressource inconnue (" << type << ")" << std::endl;
	throw gui::except("game::tiles::get - bad Ressources");
      }
    return (this->_ressources[type]);
  }

  bool tiles::getIncant() const
  {
    return (this->_incantation);
  }
};
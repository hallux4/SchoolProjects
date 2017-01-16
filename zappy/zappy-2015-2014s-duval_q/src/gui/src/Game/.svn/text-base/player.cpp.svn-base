#include <iostream>
#include <cstring>
#include "game.hpp"
#include "color.hpp"
#include "gui/except.hpp"

namespace game
{
  player::player(int x, int y, int num, orientation ori, type status) : _number(num), _status(status)
  { this->set(x, y, ori); }

  player::player(const player &other) : _orientation(other._orientation), _number(other._number), _position(other._position), _status(other._status)
  { }

  player::~player()
  { }

  void	player::set(int x, int y, orientation ori, type status)
  {
    if (ori < NORD || ori > OUEST)
      {
	std::cerr << color::red << "game::player::set : orientation invalide " << ori << color::white << std::endl;
	return ;
      }
    else
      {
	if (status == EGG || status == PLAYER)
	  this->_status = status;
	_position.first = x;
	_position.second = y;
	this->_orientation = ori;
      }
  }

#warning "A voir plus tard quand le reste marchera"
  void player::set(game::map &map, int player, int x, int y, game::orientation ori, type status)
    {
      std::map<int, game::player>::iterator	it;

      it = map._players.find(player);
      if (ori < NORD || ori > OUEST)
	{
	  std::cerr << color::red << __func__ << " : orientation invalide " << ori << color::white << std::endl;
	  return ;
	}
      if (it == map._players.end())
	{
	  std::cerr << color::red << __func__ << " : Joueur #" << player << " inexistant !" << color::white << std::endl;
	  return;
	}
      if (status == EGG || status == PLAYER)
	it->second._status = status;
      it->second._position.first = x;
      it->second._position.second = y;
      it->second._orientation = ori;
    }

  void	player::setStatus(game::map &map, int player, game::player::type status)
    {
      std::map<int, game::player>::iterator	it;

      it = map._players.find(player);
      if (it == map._players.end())
	{
	  std::cerr << color::red << __func__ << " : Joueur #" << player << " inexistant !" << color::white << std::endl;
	  return;
	}
      it->second._status = status;
    }

  bool player::isHere(int x, int y) const
    {
      if (_position.first == x && _position.second == y)
	return (true);
      return (false);
    }

  void	player::setTeam(const std::string &teamname)
  {
    _teamname = teamname;
  }


    /* --- static --- */
  void	player::setInv(game::map &map, int player, int ress[7])
  {
    std::map<int, game::player>::iterator	it = map.FindPlayer(player);

    if (it == map._players.end())
    {
      std::cerr << color::red << __func__ << " : Joueur #" << player << " inexistant !" << color::white << std::endl;
      return ;
    }
   std::memcpy(it->second._ressources, ress, (sizeof(int) * 7));
  }

  void	player::setLevel(game::map &map, int player, int level)
  {
    std::map<int, game::player>::iterator	it = map.FindPlayer(player);

    if (it == map._players.end())
    {
      std::cerr << color::red << __func__ << " : Joueur #" << player << " inexistant !" << color::white << std::endl;
      return ;
    }
   it->second._level = level;
  }

  void	player::setLevel(int level)
  {
    this->_level = level;
  }

    game::e_sprite	OrientationToSprite(game::orientation ori)
  {
    switch (ori)
    {
      case NORD: return game::CHAR_UP;
      case SUD: return game::CHAR_DOWN;
      case OUEST: return game::CHAR_LEFT;
      case EST: return game::CHAR_RIGHT;
      default : throw gui::except(__func__);
    }
  }
};

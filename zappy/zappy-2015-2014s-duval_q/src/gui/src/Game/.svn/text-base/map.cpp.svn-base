#include <iostream>
#include "game.hpp"
#include "parser.hpp"
#include "color.hpp"
#include "gui/except.hpp"

namespace game
{
  map::map() : _size(-1, -1)
  { }

  map::~map()
  { }

  void  map::setRess(int x, int y, game::e_sprite type, int nb)
  {
    unsigned int	pos;

    if (_size.first == -1 || _size.second == -1)
      throw gui::except("game::setRess utilisé avant l'initialisation de la map");
    pos = x + this->_size.first * y;
    if (pos >= this->_tiles.size())
      {
	std::cerr << color::red << "game::map::setRess : Taille invalide (" << pos << ") - " ;
	std::cerr << x << "/" << y << color::white << std::endl;
      }
    else
      this->_tiles.at(pos).setRess(type, nb);
  }

  void  map::addPlayer(int x, int y, int num_pl, orientation orient, const std::string &teamname)
  {
  std::map<int, game::player>::iterator	it;

  it = _players.find(num_pl);
  if (it != _players.end())
      {
	std::cout <<  "\t" << color::orange << "game::map::addPlayer : " << "Le joueur #" << num_pl << " existe déja." <<  color::white << std::endl;
	game::player::set(*this, x, y, num_pl, orient);
	return ;
      }
  _players.insert(std::pair<int, game::player>(num_pl, game::player(x, y, num_pl, orient)));
  _players.at(num_pl).setTeam(teamname);
  }

  void  map::rmPlayer(int num_pl)
  {
    if (_players.count(num_pl) == 0)
      std::cerr << color::red << "game::map::rmPlayer : Player " << num_pl << " n'existe pas" << color::white << std::endl;
    else
      _players.erase(num_pl);
  }

  void  map::setDim(int x, int y)
  {
    _size.first = x;
    _size.second = y;
    this->_tiles.resize(x * y);
  }

  tiles       	&map::getTile(int x, int y)
  {
    return (this->_tiles.at(x + y * _size.first));
  }

  void map::addEgg(int x, int y, int num)
  {
    if (_players.count(num) != 0)
      std::cerr << color::red << "Le joueur (oeuf) #" << num << " a déja été pondu !" << color::white << std::endl;
    else
      _players.insert(std::pair<int, game::player>(num, game::player(x, y, num, NORD, player::EGG)));
    std::list<game::player>::iterator	it;
  }

  std::map<int, game::player>::iterator	map::FindPlayer(int number)
  {
    std::map<int, game::player>::iterator	it;

    it = _players.find(number);
    if (it == _players.end())
      std::cout << color::orange << "Le joueur #" << number << " n'a été trouvé dans la liste des joueurs vivants" << color::white << std::endl;
    return (it);
  }

  void	map::addTeam(const std::string &teamname)
  {
    this->_team.push_back(teamname);
  }
}

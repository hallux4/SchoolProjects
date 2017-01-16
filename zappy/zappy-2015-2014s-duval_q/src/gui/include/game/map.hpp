#ifndef __GAME_MAP_HPP_
#define __GAME_MAP_HPP_

#include <vector>
#include <list>
#include <map>
#include "player.hpp"
#include "tiles.hpp"
#include "e_sprite.hpp"


namespace game
{

  class map
  {
  public:
    map();
    ~map();

  public:
    std::pair<int, int>		_size; // x/y
    std::vector<tiles>          _tiles;
    std::map<int, game::player> _players;
    std::list<std::string>	_team;

  public:
    void                setRess(int x, int y, game::e_sprite type, int nb);
    void                addPlayer(int x, int y, int num_pl, orientation orient, const std::string &teamname);
    void		addEgg(int x, int y, int num);
    void                rmPlayer(int num_pl);
    void                setDim(int x, int y);
    tiles               &getTile(int x, int y);
    void		addTeam(const std::string &teamname);
    std::map<int, game::player>::iterator	FindPlayer(int number);

  private:
    map(const map &other);
  };
};

#endif /* __GAME_MAP_HPP_ */

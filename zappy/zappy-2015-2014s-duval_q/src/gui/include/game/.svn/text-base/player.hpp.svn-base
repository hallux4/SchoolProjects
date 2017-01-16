#ifndef __GAME_PLAYER_HPP_
#define __GAME_PLAYER_HPP_

#include <vector>
#include <string>
#include "e_sprite.hpp"

namespace game
{
  enum  orientation
    {
      NORD = 1,
      EST = 2,
      SUD = 3,
      OUEST = 4
    };

  class map;
  class player
  {
  public:
    enum	type
      {
	  NONE,
	  EGG,
	  PLAYER
      };

  public:
    player(int x, int y, int number, orientation ori, type status = PLAYER);
    player(const player &other);
    ~player();
    bool        isHere(int x, int y) const;

    void        set(int x, int y, orientation ori, type status = NONE);
    void	setLevel(int level);
    void	setInv(const std::vector<int> &ress);
    void	setTeam(const std::string &teamname);

    static void	set(game::map &map, int player, int x, int y, game::orientation ori, type status = NONE);
    static void	setStatus(game::map &map, int player, type status);
    static void setLevel(game::map &map, int player, int level);
    static void setInv(game::map &map, int player, int ress[7]);

  public:
    orientation         _orientation;
    int                 _number;
    std::pair<int, int>	_position;
    std::string		_teamname;
    type		_status;
    int			_level;
    int			_ressources[7];

  private:
    player();
  };

  game::e_sprite	OrientationToSprite(game::orientation ori);
};

#endif /* __GAME_PLAYER_HPP_ */

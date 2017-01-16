#ifndef __GAME_TILES_HPP_
#define __GAME_TILES_HPP_

#include "game/e_sprite.hpp"

namespace game
{
  class tiles
    {
    public:
      tiles();
      void      setRess(game::e_sprite type, int nb);
      void	setIncant(bool incant);
      int       getRess(game::e_sprite type) const;
      bool	getIncant() const;

    private:
      int       _ressources[7];
      bool	_incantation;
    };
};

#endif /* __GAME_TILES_HPP_ */

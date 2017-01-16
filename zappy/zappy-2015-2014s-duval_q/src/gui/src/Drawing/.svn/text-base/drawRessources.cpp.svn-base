#include "gui/sfml.hpp"

void    sfml::drawRessources(int x, int y)
{
  const game::tiles     &tile = this->data.map.getTile(x, y);
  game::e_sprite	i = game::FOOD;
  static sf::Sprite		stone;

  while (i <= game::THYSTAME)
    {
      if (tile.getRess(i) > 0)
        {
	  stone = GetSprite(i);
          stone.SetPosition((x * gui::config::SIZE_TILES) + (i * 6) + 4, (y * gui::config::SIZE_TILES) + (i * 6 + 4));
          App.Draw(stone);
        }
      i = (game::e_sprite)((int)(i) + 1);
    }
}
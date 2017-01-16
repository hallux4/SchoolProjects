#include "gui/sfml.hpp"

void	sfml::drawHalo(int x, int y)
{
  if (data.map.getTile(x, y).getIncant() == true)
    {
      sf::Sprite	halo;

      halo = GetSprite(game::HALO);
      halo.SetPosition(x * gui::config::SIZE_TILES, y * gui::config::SIZE_TILES);
      App.Draw(halo);
    }
}
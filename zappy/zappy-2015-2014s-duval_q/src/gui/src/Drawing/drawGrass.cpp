#include "gui/sfml.hpp"
#include "gui.hpp"

void	sfml::drawGrass(int x, int y)
{
  sf::Sprite	grass = GetSprite(game::GRASS);

  grass.SetPosition(x * gui::config::SIZE_TILES, y * gui::config::SIZE_TILES);
  App.Draw(grass);
}
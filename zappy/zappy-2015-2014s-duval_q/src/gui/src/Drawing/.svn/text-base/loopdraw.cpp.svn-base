#include <iostream>
#include <cmath>
#include "gui/sfml.hpp"

void	sfml::draw_map()
{
  sf::FloatRect	rect = View.GetRect();

  rect.Bottom = std::ceil(rect.Bottom / gui::config::SIZE_TILES);
  rect.Top = std::floor(rect.Top / gui::config::SIZE_TILES);
  rect.Left = std::floor(rect.Left / gui::config::SIZE_TILES);
  rect.Right = std::ceil(rect.Right / gui::config::SIZE_TILES);
//  std::cout << rect.Left<< "/" << rect.Top << "  |  " << rect.Right << "/" << rect.Bottom << std::endl;

  drawBackground();
  for (int y = (rect.Top < 0 ? 0 : rect.Top); y < (rect.Bottom > data.map._size.second ? data.map._size.second : rect.Bottom); y++)
    for (int x = (rect.Left < 0 ? 0 : rect.Left); x < (rect.Right > data.map._size.first ? data.map._size.first : rect.Right); x++)
      {
	drawGrass(x, y);
	drawRessources(x, y);
	drawHalo(x, y);
      }
  drawPlayers(rect);
  drawFocusedTile(rect);
  drawGui();
  App.Display();
  #ifdef SHOW_FPS
  std::cout << 1.f / App.GetFrameTime() << std::endl;
  #endif
};
#include <sstream>
#include "gui/sfml.hpp"

void    sfml::drawGui()
{
  game::e_sprite	ressource = game::FOOD;
  sf::Sprite		sprite = GetSprite(game::GUI);

  Memory.OffsetView.first = View.GetRect().Right - gui::config::GUI_WIDTH;
  Memory.OffsetView.second = View.GetRect().Top;
  sprite.SetPosition(Memory.OffsetView.first, Memory.OffsetView.second);
  App.Draw(sprite);
  drawGuiInformation();

  while (ressource <= game::THYSTAME)
    {
      sprite = GetSprite(ressource);
      sprite.SetPosition(Memory.OffsetView.first + 16, Memory.OffsetView.second + 377 + ressource * 41);
      App.Draw(sprite);
      drawGuiStone(ressource);
      ressource = static_cast<game::e_sprite>(1 + static_cast<int>(ressource));
    }
}

void	sfml::drawGuiInformation()
{
  std::ostringstream	os;

  os << "Zappy - TU (" << data.TimeUnit << ")";
  drawGuiText(os.str(), 14, 10, 20);
}

void	sfml::drawGuiStone(game::e_sprite type)
{
  int	tilex = Memory.GetTileFocus().first;
  int	tiley = Memory.GetTileFocus().second;

  if (tilex >= 0 && tiley >= 0)
    {
      const game::tiles	&tiles = data.map.getTile(tilex, tiley);
      drawGuiText(tiles.getRess(type), 56, 370 + type * 41);
    }
}

/* ---- Fonctions génériques ---- */

void	sfml::drawGuiText(int value, int posX, int posY, std::size_t size)
{
  std::ostringstream	os;
  sf::String		text;

  os << value;
  text.SetColor(sf::Color(0, 0, 0));
  text.SetText(os.str());
  text.SetPosition(Memory.OffsetView.first + posX, Memory.OffsetView.second + posY);
  text.SetSize(size);
  App.Draw(text);
}

void	sfml::drawGuiText(const std::string &str, int posX, int posY, std::size_t size)
{
  sf::String	text;

  text.SetColor(sf::Color(0, 0, 0));
  text.SetText(str);
  text.SetPosition(Memory.OffsetView.first + posX, Memory.OffsetView.second + posY);
  text.SetSize(size);
  App.Draw(text);
}
#include <cmath>
#include "gui.hpp"
#include "gui/sfml.hpp"

void    sfml::drawPlayers(const sf::FloatRect &rect)
{
  std::map<int, game::player>::iterator	it;
  sf::Sprite				player;

  it = this->data.map._players.begin();
  while (it != this->data.map._players.end())
    {
      if (it->second._position.first >= rect.Left && it->second._position.first <= rect.Right)
	if (it->second._position.second >= rect.Top && it->second._position.second <= rect.Bottom)
	  {
	    player = (it->second._status == game::player::EGG ? GetSprite(game::EGG) : GetSprite(game::OrientationToSprite(it->second._orientation)));
	    int	x = it->second._position.first * 64 - rect.Left + std::ceil(rect.Left);
	    int y = it->second._position.second * 64 - rect.Top + std::ceil(rect.Top);

	    if (it->second._status == game::player::PLAYER)
	      player.SetPosition(x + 16, y + 8);
	    else if (it->second._status == game::player::EGG)
	      player.SetPosition(x + 32, y);
	    else
	      throw gui::except("Bad status - sfml::drawPlayer");
	    App.Draw(player);
	  }
      it++;
    }
}
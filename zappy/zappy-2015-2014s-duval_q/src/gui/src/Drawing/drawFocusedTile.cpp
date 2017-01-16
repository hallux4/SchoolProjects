#include <iostream>
#include <cmath>
#include "gui/sfml.hpp"

void	sfml::drawFocusedTile(const sf::FloatRect &rect)
{
  const std::pair<int, int> 	&focus = Memory.GetTileFocus();

  if (focus.first >= 0 && focus.second >= 0)
    if (focus.first >= rect.Left && focus.first <= rect.Right)
      if (focus.second >= rect.Top && focus.second <= rect.Bottom)
	{
	  sf::Sprite	high = GetSprite(game::WHITE_SQUARE);

	  high.SetPosition(focus.first * 64 - rect.Left + std::ceil(rect.Left), focus.second * 64 - rect.Top + std::ceil(rect.Top));
	  App.Draw(high);
	}
}
#include <SFML/Graphics/Sprite.hpp>
#include <iostream>
#include "gui/sfml.hpp"

void	sfml::intro()
{
#ifndef DEBUG_NO_INTRO
  this->App.Draw(GetSprite(game::INTRO));
  this->App.Display();
  this->wait(1200);
  this->App.Clear();
#endif
  std::cout << "Beginning graph loop" << std::endl;
}


#include <iostream>
#include "gui/sfml.hpp"

void	sfml::end()
{
  this->App.Clear();
  this->App.Display();
  std::cout << "Ending graph loop" << std::endl;
}
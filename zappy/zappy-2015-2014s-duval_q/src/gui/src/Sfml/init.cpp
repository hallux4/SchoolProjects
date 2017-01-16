#include <iostream>
#include "gui/sfml.hpp"
#include "gui/except.hpp"

void	sfml::init()
{
  if (this->data.map._size.first < 1  || this->data.map._size.second < 1)
    {
      std::cerr << "Taille : " << this->data.map._size.first << "/" << this->data.map._size.second << std::endl;
      throw gui::except("La map est trop petite.\n (Ou le serveur n'a pas envoyé la taille de la map)");
    }
  this->LoadGraphic();
  this->App.Create(sf::VideoMode(gui::config::WIDTH + gui::config::GUI_WIDTH, gui::config::HEIGHT, 32), "Zappy - GUI", sf::Style::Close);
  this->App.SetFramerateLimit(60);
  App.SetView(View);
}
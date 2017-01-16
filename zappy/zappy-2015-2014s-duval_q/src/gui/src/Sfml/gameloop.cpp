#include "gui/sfml.hpp"

bool    sfml::gameloop() const
{
  return (this->App.IsOpened() & !(this->data));
}
#include <iostream>
#include "game/RessourceManager.hpp"
#include "color.hpp"
#include "gui/except.hpp"

namespace game
{
  RessourceManager::RessourceManager()
  {
  }

  RessourceManager::~RessourceManager()
  { }

  bool	RessourceManager::AddImage(const std::string &filename, const std::string &imagename)
  {
    std::string		name = (imagename.size() == 0 ? filename : imagename);

    if (Image.count(name) == 1)
      {
	std::cerr << color::red << "Image #" << name << " est déja chargé." << color::white << std::endl;
	return (false);
      }
    return (Image[name].LoadFromFile(name));
  }

  void	RessourceManager::AddSprite(const std::string &imagename, const std::string &spritename, const sf::Rect<int>	&rect)
  {
    if (Image.count(imagename) == 0)
      {
	std::cerr << color::red << __func__ << " : Image #" << imagename << " n'est pas chargé !" << color::white << std::endl;
	throw gui::except("RessourceManager::AddSprite : Image not found");
      }
    Sprite[spritename].SetImage(Image[imagename]);
    if (rect.Left != 0 || rect.Bottom != 0 || rect.Right != 0 || rect.Top != 0)
      Sprite[spritename].SetSubRect(rect);
  }

  void	RessourceManager::SpriteSetCenter(const std::string &spritename, const std::pair<int, int> &pos)
  {
    if (Sprite.count(spritename) == 0)
      {
	std::cerr << color::red <<  __func__ << " : Sprite #" << spritename << " n'est pas chargé !" << color::white << std::endl;
	throw gui::except("RessourceManager::SpriteSetCenter : Sprite not found");
      }
    Sprite[spritename].SetCenter(pos.first, pos.second);
  }

  void	RessourceManager::SpriteSetPosition(const std::string &spritename, const std::pair<int, int> &pos)
  {
    if (Sprite.count(spritename) == 0)
      {
	std::cerr << color::red << __func__ << " : Sprite #" << spritename << " n'est pas chargé !" << color::white << std::endl;
	throw gui::except("RessourceManager::SpriteSetPosition : Sprite not found");
      }
    Sprite[spritename].SetPosition(pos.first, pos.second);
  }

  void	RessourceManager::SpriteResize(const std::string &spritename, const std::pair<int, int> &pos)
  {
    if (Sprite.count(spritename) == 0)
      {
	std::cerr << color::red << __func__ << " : Sprite #" << spritename << " n'est pas chargé !" << color::white << std::endl;
	throw gui::except("RessourceManager::SpriteResize : Sprite not found");
      }
    Sprite[spritename].Resize(pos.first, pos.second);
  }

  const sf::Image	&RessourceManager::GetImage(const std::string &imagename)
  {
    if (Sprite.count(imagename) == 0)
      {
	std::cerr << color::red << __func__ << " : Image #" << imagename << " n'est pas chargé !" << color::white << std::endl;
	throw gui::except("RessourceManager::GetImage : Image not found");
      }
    return (Image[imagename]);
  }

  const sf::Sprite	&RessourceManager::GetSprite(const std::string &spritename)
  {
    if (Sprite.count(spritename) == 0)
      {
	std::cerr << color::red << __func__ << " : Sprite #" << spritename << " n'est pas chargé !" << color::white << std::endl;
	throw gui::except("RessourceManager::GetSprite : Sprite not found");
      }
    return (Sprite[spritename]);
  }

  const sf::Sprite	&RessourceManager::operator[](const std::string &spritename)
  {
    if (Sprite.count(spritename) == 0)
      std::cerr << color::red << __func__ << " : Sprite #" << spritename << " n'existe pas" << color::white << std::endl;
    return (Sprite[spritename]);
  }
};
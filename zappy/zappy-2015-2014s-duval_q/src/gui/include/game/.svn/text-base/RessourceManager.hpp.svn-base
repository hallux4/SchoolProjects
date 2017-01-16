#ifndef __GAME_RESSOURCEMANAGER_HPP_
#define __GAME_RESSOURCEMANAGER_HPP_

#include <SFML/Graphics.hpp>
#include <string>
#include <map>
#include "game/e_sprite.hpp"

namespace game
{
  class RessourceManager
    {
    public:
      RessourceManager();
      ~RessourceManager();

    bool	AddImage(const std::string &filename, const std::string &imagename = "");
    void	AddSprite(const std::string &imagename, const std::string &spritename, const sf::Rect<int> &rect = sf::Rect<int>(0, 0, 0, 0));
    void	SpriteSetCenter(const std::string &spritename, const std::pair<int, int> &pos);
    void	SpriteSetPosition(const std::string &spritename, const std::pair<int, int> &pos);
    void	SpriteResize(const std::string &spritename, const std::pair<int, int> &pos);

    const sf::Image	&GetImage(const std::string &imagename);
    const sf::Sprite	&GetSprite(const std::string &spritename);
    const sf::Sprite	&operator[](const std::string &spritename);
    private:
      std::map<std::string, sf::Image>	Image;
      std::map<std::string, sf::Sprite>	Sprite;
    };
};

#endif /* __RESSOURCEMANAGER_HPP_ */

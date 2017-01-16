#include <SFML/Graphics.hpp>
#include <vector>
#include <map>
#include "gui.hpp"

namespace image
{
  enum	e_filename
  {
    INTRO,
    SCORE,
    CHAR,
    STONES,
    EGG,
    TILES,
    GUI,
    WHITE_SQR,
    HALO,
    NONE
  };
}

void	sfml::LoadGraphic(void)
{
  std::vector<std::string> 	filename;
  std::size_t			i = 0;
  bool				error = false;

  filename.resize(image::NONE);
  filename[image::INTRO] = "ressources/intro.jpg";
  filename[image::SCORE] = "ressources/score.jpg";
  filename[image::CHAR] = "ressources/Characters.png";
  filename[image::STONES] = "ressources/stones.png";
  filename[image::EGG] = "ressources/egg.png";
  filename[image::TILES] = "ressources/tiles.png";
  filename[image::GUI] = "ressources/gui.png";
  filename[image::WHITE_SQR] = "ressources/White_square.png";
  filename[image::HALO] = "ressources/fire-aura.png";

  while (i < filename.size())
      {
      if (RessManager.AddImage(filename[i]) == false)
	error = true;
      i++;
    }
  if (error)
    throw gui::except("Phase de chargement des images");

  RessManager.AddSprite(filename[image::TILES], "grass");
  RessManager.AddSprite(filename[image::STONES], "food", sf::Rect<int>(0, 0, 16, 16));
  RessManager.AddSprite(filename[image::STONES], "linemate", sf::Rect<int>(16, 0, 32, 16));
  RessManager.AddSprite(filename[image::STONES], "deraumatre", sf::Rect<int>(32, 0, 48, 16));
  RessManager.AddSprite(filename[image::STONES], "sibur", sf::Rect<int>(48, 0, 64, 16));
  RessManager.AddSprite(filename[image::STONES], "mendiane", sf::Rect<int>(64, 0, 80, 16));
  RessManager.AddSprite(filename[image::STONES], "phiras", sf::Rect<int>(80, 0, 96, 16));
  RessManager.AddSprite(filename[image::STONES], "thystame", sf::Rect<int>(96, 0, 112, 16));
  RessManager.AddSprite(filename[image::WHITE_SQR], "white_square");
  RessManager.AddSprite(filename[image::GUI], "gui", sf::Rect<int>(0, 0, 200, 800));
  RessManager.AddSprite(filename[image::INTRO], "intro");
  RessManager.AddSprite(filename[image::EGG], "egg");
  RessManager.AddSprite(filename[image::CHAR], "char_down", sf::Rect<int>(93, 0, 124, 49));
  RessManager.AddSprite(filename[image::CHAR], "char_left", sf::Rect<int>(93, 49, 124, 98));
  RessManager.AddSprite(filename[image::CHAR], "char_right", sf::Rect<int>(94, 98, 124, 147));
  RessManager.AddSprite(filename[image::CHAR], "char_up", sf::Rect<int>(93, 147, 124, 193));
  RessManager.AddSprite(filename[image::HALO], "halo");

  RessManager.SpriteSetCenter("white_square", std::pair<int, int>(2, 2));
  RessManager.SpriteSetPosition("gui", std::pair<int, int>(gui::config::WIDTH, 0));
  RessManager.SpriteResize("intro", std::pair<int, int>(gui::config::WIDTH + gui::config::GUI_WIDTH, gui::config::HEIGHT));
  RessManager.SpriteResize("egg", std::pair<int, int>(35, 35));
  RessManager.SpriteResize("halo", std::pair<int, int>(64, 64));
  filename.clear();
}

const sf::Sprite	&sfml::GetSprite(game::e_sprite type)
{
  switch (type)
  {
    case game::FOOD : return (RessManager.GetSprite("food"));
    case game::LINEMATE : return (RessManager.GetSprite("linemate"));
    case game::DERAUMATRE : return (RessManager.GetSprite("deraumatre"));
    case game::SIBUR : return (RessManager.GetSprite("sibur"));
    case game::MENDIANE : return (RessManager.GetSprite("mendiane"));
    case game::PHIRAS : return (RessManager.GetSprite("phiras"));
    case game::THYSTAME : return (RessManager.GetSprite("thystame"));
    case game::CHAR_UP : return (RessManager.GetSprite("char_up"));
    case game::CHAR_RIGHT : return (RessManager.GetSprite("char_right"));
    case game::CHAR_DOWN : return (RessManager.GetSprite("char_down"));
    case game::CHAR_LEFT : return (RessManager.GetSprite("char_left"));
    case game::EGG : return (RessManager.GetSprite("egg"));
    case game::GUI : return (RessManager.GetSprite("gui"));
    case game::INTRO : return (RessManager.GetSprite("intro"));
    case game::SCORE : return (RessManager.GetSprite("score"));
    case game::GRASS : return (RessManager.GetSprite("grass"));
    case game::WHITE_SQUARE : return (RessManager.GetSprite("white_square"));
    case game::HALO : return (RessManager.GetSprite("halo"));
    default : throw gui::except("sfml::GetSprite : e_sprite inconnu");
  }
}
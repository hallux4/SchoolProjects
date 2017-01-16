#ifndef __GUI_SFML_HPP
#define __GUI_SFML_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include "../gui.hpp"
#include "../game.hpp"

namespace gui
{
  namespace config
  {
    const int GUI_WIDTH = 200;
    const int WIDTH = 800;
    const int HEIGHT = 800;
    const int RATIO_IMAGE = 1;
    const int SIZE_TILES = 64 / RATIO_IMAGE;
    const int NB_X_TILES = WIDTH / SIZE_TILES;
    const int NB_Y_TILES = HEIGHT / SIZE_TILES;
  };
};

class sfml
{
public:
  sfml(game::data &data);
  ~sfml();

public:
  void	init();
  void	intro();
  bool	gameloop() const;
  void	process_event();
  void	draw_map();
  void	wait(int millisecond);
  void	end();
  void	exit();

private:
  sf::RenderWindow		App;
  game::data			&data;
  game::RessourceManager	RessManager;
  gui::gui_memory		Memory;
  sf::View			View;

private:
  void          	LoadGraphic(void);
  const sf::Sprite	&GetSprite(game::e_sprite type);

private:
  void		process_keyboard(const sf::Event &event);
  void		process_mouse_click(const sf::Event &event);
  void		process_mouse_position(const sf::Input &input);
  void 		  drawBackground();
  void        	  drawGrass(int x, int y);
  void		  drawRessources(int x, int y);
  void        	  drawPlayers(const sf::FloatRect &rect);
  void		  drawHalo(int x, int y);
  void		  drawFocusedTile(const sf::FloatRect &rect);
  void        	  drawGui();

		    // Position par rapport à la fenêtre (aka, les coordonnées de click)
  void              drawGuiText(int value, int posX, int posY, std::size_t size = 24);
		    // Position par rapport à la fenêtre (aka, les coordonnées de click)
  void              drawGuiText(const std::string &str, int posX, int posY, std::size_t size = 24);
  void		      drawGuiStone(game::e_sprite type);
  void		      drawGuiInformation();

private:
  sfml();
  sfml(const sfml &other);
};

#endif /* __GUI_SFML_HPP */

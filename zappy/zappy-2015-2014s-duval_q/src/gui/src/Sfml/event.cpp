#include <iostream>
#include "gui/sfml.hpp"

void	sfml::process_keyboard(const sf::Event &event)
{
  switch (event.Key.Code)
    {
    case sf::Key::Escape:
      this->App.Close();
      return;

    case sf::Key::F1:
      {
	sf::Image Screen = App.Capture();
	Screen.SaveToFile("screenshot.jpg");
	break;
      }

    case sf::Key::Space:
      View.SetCenter((gui::config::WIDTH + gui::config::GUI_WIDTH - gui::config::SIZE_TILES) / 2, (gui::config::HEIGHT  - gui::config::SIZE_TILES) / 2 );
      break;

    default:
      break;
    }
}

void    sfml::process_mouse_click(const sf::Event &event)	// On utilisera ça pour le focus de joueur
{
  std::cout << "Mouse : " << event.MouseButton.X << "/" << event.MouseButton.Y << std::endl;
/*
  float   xclick = event.MouseButton.X / 64.0 + this->_view.getX();
  float   yclick = event.MouseButton.Y / 64.0 + this->_view.getY();
  */
}

void	sfml::process_mouse_position(const sf::Input &input)
{
  int	MouseX = input.GetMouseX();
  int	MouseY = input.GetMouseY();

  if (Memory.GetLastMousePosition().first != MouseX || Memory.GetLastMousePosition().second != MouseY)
    {
      float   xpos = (MouseX + View.GetRect().Left) / 64;
      float   ypos = (MouseY + View.GetRect().Top) / 64;

      Memory.SetLastMousePosition(MouseX, MouseY);
      if (xpos < 0 || ypos < 0);
      else if (xpos >= this->data.map._size.first || ypos >= this->data.map._size.second);
      else if (MouseX >= gui::config::WIDTH);
      else
	{
	  Memory.SetTileFocus(xpos, ypos);
	  return;
	}
      Memory.SetTileFocus(-1, -1);
    }
}

void    sfml::process_event()
{
  const sf::Input 	&input = App.GetInput();
  sf::Event		event;

  while (App.GetEvent(event))
    {
      switch (event.Type)
	{
	case sf::Event::KeyPressed:
	  this->process_keyboard(event);
	  break;

	case sf::Event::Resized:
          break;

	case sf::Event::Closed:
	  this->App.Close();
          break;

        case sf::Event::MouseButtonPressed:
          this->process_mouse_click(event);
          break;

	default:
	  break;
	}
    }

#define MOVE_BY_ITERATION 16

  process_mouse_position(input);
  if(input.IsKeyDown(sf::Key::Left))
    {
      View.Move(-MOVE_BY_ITERATION, 0);
    }

  if(input.IsKeyDown(sf::Key::Right))
    {
      View.Move(MOVE_BY_ITERATION, 0);
    }

  if(input.IsKeyDown(sf::Key::Up))
    {
      View.Move(0, -MOVE_BY_ITERATION);
    }

  if(input.IsKeyDown(sf::Key::Down))
    {
      View.Move(0, MOVE_BY_ITERATION);
    }
}

#include "gui.hpp"
#include "game.hpp"

namespace gui
{
  gui_memory::gui_memory() : OffsetView(0, 0), _TileFocus(-1, -1), _PlayerFocus(-1), _LastMousePosition(0, 0)
  { }

  gui_memory::~gui_memory()
  { }

  void	gui_memory::SetTileFocus(int x, int y)
  {
    _TileFocus.first = x;
    _TileFocus.second = y;
  }

  void	gui_memory::SetPlayerFocus(int player)
  {
    _PlayerFocus = player;
  }

  void	gui_memory::SetLastMousePosition(int x, int y)
  {
    _LastMousePosition.first = x;
    _LastMousePosition.second = y;
  }

  const std::pair<int, int>	&gui_memory::GetTileFocus()
  {
    return (_TileFocus);
  }

  int				gui_memory::GetPlayerFocus()
  {
    return (_PlayerFocus);
  }

  const std::pair<int, int>	&gui_memory::GetLastMousePosition()
  {
    return (_LastMousePosition);
  }
};
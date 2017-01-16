#ifndef __GUI_MEMORY_HPP_
#define __GUI_MEMORY_HPP_

namespace game
{
    class map;
}

namespace gui
{
  class gui_memory
  {
  public:
    gui_memory();
    ~gui_memory();

    void	SetTileFocus(int x, int y);
    void	SetPlayerFocus(int player);
    void	SetLastMousePosition(int x, int y);
    const std::pair<int, int>	&GetTileFocus();
    int				GetPlayerFocus();
    const std::pair<int, int>	&GetLastMousePosition();

  public:
    std::pair<int, int>	OffsetView;

  private:
    std::pair<int, int>	_TileFocus;
    int			_PlayerFocus;
    std::pair<int, int>	_LastMousePosition;

  private:
    gui_memory(const gui_memory &other);
  };
};

#endif /* __GUI_MEMORY_HPP_ */

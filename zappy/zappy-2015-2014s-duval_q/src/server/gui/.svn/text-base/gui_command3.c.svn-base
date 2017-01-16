/*
** gui_command3.c for extlibc in /home/epitech/c/Zappy
**
** Made by claude ramseyer
** Login   <ramsey_c@epitech.net>
**
** Started on  Mon Jun 2 10:00:00 2011 claude ramseyer
** Last update Mon Jun 2 10:00:01 2011 claude ramseyer
*/

#include "gui.h"

extern t_game *g_game;

void gui_command_suc(t_gui *gui, char *command)
{
  (void) command;
  gui_send(gui, "suc");
}

void gui_command_sbp(t_gui *gui, char *command)
{
  (void) command;
  gui_send(gui, "sbp");
}

void gui_command_pnw(t_gui *gui, char *command)
{
  char buffer[GUI_BUFFER_SIZE];
  t_player *player;

  (void) command;
  lforeach(&g_game->players, player)
  {
    snprintf(buffer, GUI_BUFFER_SIZE, "pnw %i %i %i %i %i %s",
	     player->id, player->ppos_x, player->ppos_y,
	     player->orientation + 1, player->level,
	     player->team->name);
    gui_send(gui, buffer);
  }
}

void gui_command_enw(t_gui *gui, char *command)
{
  (void) gui;
  (void) command;
}

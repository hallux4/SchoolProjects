/*
** gui_action1.c for extlibc in /home/epitech/c/Zappy
**
** Made by claude ramseyer
** Login   <ramsey_c@epitech.net>
**
** Started on  Mon Jun 2 10:00:00 2011 claude ramseyer
** Last update Mon Jun 2 10:00:01 2011 claude ramseyer
*/

#include "gui.h"

void gui_action_forward(t_player *player)
{
  char buffer[GUI_BUFFER_SIZE];

  snprintf(buffer, GUI_BUFFER_SIZE, "ppo %i %i %i %i",
	   player->id, player->ppos_x, player->ppos_y,
	   player->orientation + 1);
  gui_send_all(buffer);
}

void gui_action_left(t_player *player)
{
  gui_action_forward(player);
}

void gui_action_right(t_player *player)
{
  gui_action_forward(player);
}

void gui_action_new(t_player *player)
{
  char buffer[GUI_BUFFER_SIZE];

  snprintf(buffer, GUI_BUFFER_SIZE, "pnw %i %i %i %i %i %s",
	   player->id, player->ppos_x, player->ppos_y,
	   player->orientation + 1, player->level,
	   player->team->name);
  gui_send_all(buffer);
}

void gui_action_death(t_player *player)
{
  char buffer[GUI_BUFFER_SIZE];

  snprintf(buffer, GUI_BUFFER_SIZE, "pdi %i", player->id);
  gui_send_all(buffer);
}

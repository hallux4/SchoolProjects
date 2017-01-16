/*
** gui_action3.c for extlibc in /home/epitech/c/Zappy
**
** Made by claude ramseyer
** Login   <ramsey_c@epitech.net>
**
** Started on  Mon Jun 2 10:00:00 2011 claude ramseyer
** Last update Mon Jun 2 10:00:01 2011 claude ramseyer
*/

#include "gui.h"

void gui_action_broadcast(t_player *player, char *msg)
{
  char buffer[GUI_BUFFER_SIZE];

  snprintf(buffer, GUI_BUFFER_SIZE, "pbc %i %s", player->id, msg);
  gui_send_all(buffer);
}

void gui_action_expulse(t_player *player)
{
  char buffer[GUI_BUFFER_SIZE];

  snprintf(buffer, GUI_BUFFER_SIZE, "pex %i", player->id);
}

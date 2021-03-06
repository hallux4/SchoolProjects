/*
** gui_send.c for extlibc in /home/epitech/c/Zappy
**
** Made by claude ramseyer
** Login   <ramsey_c@epitech.net>
**
** Started on  Mon Jun 2 10:00:00 2011 claude ramseyer
** Last update Mon Jun 2 10:00:01 2011 claude ramseyer
*/

#include "gui.h"

extern t_gui_manager *g_gui_manager;

int gui_send(t_gui *gui, char *msg)
{
  return client_send(gui, msg);
}

void gui_send_all(char *msg)
{
  list_foreach_param(&g_gui_manager->guis, (feachp) & gui_send, msg);
}

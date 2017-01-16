/*
** gui.c for extlibc in /home/epitech/c/Zappy
**
** Made by claude ramseyer
** Login   <ramsey_c@epitech.net>
**
** Started on  Mon Jun 2 10:00:00 2011 claude ramseyer
** Last update Mon Jun 2 10:00:01 2011 claude ramseyer
*/

#include <string.h>
#include "gui.h"

t_gui_manager * g_gui_manager = NULL;

bool gui_init()
{
  logger_message("[GUI] Gui module initialisation");
  if (!(g_gui_manager = malloc(sizeof(t_gui_manager))))
    return false;
  list_init(&g_gui_manager->guis);
  list_init(&g_gui_manager->commands);
  gui_register_command("msz", &gui_command_msz);
  gui_register_command("mct", &gui_command_mct);
  gui_register_command("bct", &gui_command_bct);
  gui_register_command("tna", &gui_command_tna);
  gui_register_command("ppo", &gui_command_ppo);
  gui_register_command("plv", &gui_command_plv);
  gui_register_command("pin", &gui_command_pin);
  gui_register_command("sgt", &gui_command_sgt);
  gui_register_command("sst", &gui_command_sst);
  return true;
}

void gui_register_command(char *name, t_gui_execute_cb callback)
{
  t_gui_command *command;

  if (!(command = malloc(sizeof(t_gui_command))))
    return;
  strncpy(command->name, name, GUI_COMMAND_SIZE);
  command->name[GUI_COMMAND_SIZE] = 0;
  command->callback = callback;
  list_add_end(&g_gui_manager->commands, command);
}

void gui_remove(t_gui *gui)
{
  if (gui->gui)
    {
      logger_verbose("[GUI] Remove gui client");
      gui->gui = false;
      list_pop(&g_gui_manager->guis, gui);
    }
}

void gui_destroy()
{
  t_gui *gui;

  if (!g_gui_manager)
    return;
  logger_message("[GUI] Gui module destroy");

  lforeach(&g_gui_manager->guis, gui)
  {
    gui->gui = false;
  }
  list_clear(&g_gui_manager->guis);
  list_free(&g_gui_manager->commands);
  free(g_gui_manager);
  g_gui_manager = NULL;
}

void gui_update_ressource(t_tile *tile)
{
  char buffer[GUI_BUFFER_SIZE];

  snprintf(buffer, GUI_BUFFER_SIZE, "bct %i %i %i %i %i %i %i %i %i",
	   tile->pos_x, tile->pos_y,
	   tile->rc_food, tile->rc_linemate, tile->rc_deraumere,
	   tile->rc_sibur, tile->rc_mendiane, tile->rc_phiras, tile->rc_thystame);
  gui_send_all(buffer);
}

/*
** gui_execute.c for extlibc in /home/epitech/c/Zappy
**
** Made by claude ramseyer
** Login   <ramsey_c@epitech.net>
**
** Started on  Mon Jun 2 10:00:00 2011 claude ramseyer
** Last update Mon Jun 2 10:00:01 2011 claude ramseyer
*/

#include <string.h>
#include "gui.h"

extern t_gui_manager *g_gui_manager;

static int gui_execute_search(t_gui_command *command, char * receive)
{
  return strncmp(command->name, receive, GUI_COMMAND_SIZE);
}

void gui_execute(t_gui *gui, char *command)
{
  t_gui_command *cmd;

  logger_verbose("[GUI] Recieve command '%s' from gui", command);
  cmd = list_get_to_param(&g_gui_manager->commands,
			  (fpredp) &gui_execute_search, command);
  if (cmd)
    {
      logger_verbose("[GUI] Execute command %s", cmd->name);
      (*cmd->callback)(gui, command);
    }
  else
    {
      logger_verbose("[GUI] No command found!");
      gui_command_sbp(gui, command);
    }
}

void gui_connect(t_gui *gui)
{
  logger_verbose("[GUI] New Client GUI connected");
  gui->exec = &gui_execute;
  gui->gui = true;
  list_add_end(&g_gui_manager->guis, gui);
  gui_command_msz(gui, NULL);
  gui_command_sgt(gui, NULL);
  gui_command_mct(gui, NULL);
  gui_command_tna(gui, NULL);
  gui_command_pnw(gui, NULL);
  gui_command_enw(gui, NULL);
}

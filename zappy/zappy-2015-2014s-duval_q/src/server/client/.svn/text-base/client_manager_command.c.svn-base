/*
** client_manager_command.c for extlibc in /home/epitech/c/Zappy
**
** Made by claude ramseyer
** Login   <ramsey_c@epitech.net>
**
** Started on  Mon Jun 2 10:00:00 2011 claude ramseyer
** Last update Mon Jun 2 10:00:01 2011 claude ramseyer
*/

#include <string.h>
#include "client.h"

extern t_client_manager *g_client_manager;

static t_command_callback *_clm_command_create(char *instruction,
					       bool param,
					       t_execute_cb callback)
{
  t_command_callback *command;

  if (!(command = malloc(sizeof(t_command_callback))))
    return NULL;
  memset(command, 0, sizeof(t_execute_cb));
  strncpy(command->instruction, instruction, CLM_CB_SIZE);
  command->length = strlen(instruction);
  command->param = param;
  command->callback = callback;
  return command;
}

static int _clm_command_retrieve_cmp(t_command_callback *command, char *action)
{
  if (strncmp(command->instruction, action, command->length) == 0)
    {
      if (command->param && action[command->length] == ' ')
	return 0;
      else if (action[command->length] == 0)
	return 0;
    }
  return 1;
}

void clm_command_register(char *instruction, bool param, t_execute_cb callback)
{
  t_command_callback *command;

  command = _clm_command_create(instruction, param, callback);
  if (command)
    list_add_end(&g_client_manager->commands, command);
}

t_command_callback *clm_command_retrieve(char *action)
{
  return list_get_to_param(&g_client_manager->commands,
			   (fpredp) & _clm_command_retrieve_cmp, action);
}

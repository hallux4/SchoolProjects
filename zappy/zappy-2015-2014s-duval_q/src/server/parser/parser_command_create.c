/*
** parser_command_create.c for zappy in /home/kersuz_v//Zappy/src/server
**
** Made by vincent kersuzan
** Login   <kersuz_v@epitech.net>
**
** Started on  Wed May 30 20:22:14 2012 vincent kersuzan
** Last update Wed May 30 20:26:58 2012 vincent kersuzan
*/

#include	<stdlib.h>
#include	<string.h>
#include	"parser.h"

t_command *parser_command_create(char *original_str)
{
  t_command *command;

  if (!original_str)
    return (NULL);
  if (!(command = malloc(sizeof(*command))))
    {
      perror("malloc");
      return (NULL);
    }
  if (!(command->original_str = strdup(original_str)))
    {
      perror("malloc");
      free(command);
      return (NULL);
    }
  command->instruction = NULL;
  list_init(&(command->arguments));
  return (command);
}

void parser_command_dump(t_command *command)
{
  t_argument *argument;

  printf("mask: %s\nchaine: %s\n",
	 command->instruction, command->original_str);
  lforeach(&command->arguments, argument)
  {
    if (argument->type == PARSER_INT_VALUE)
      printf("\tint: %i\n", (*(int *) argument->data));
    else
      printf("\tstring: %s\n", (char *) argument->data);
  }
}

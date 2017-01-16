/*
** execute_command.c for  in /home/cottin_j/Bureau/bureau/mini2/Source/mysh2
**
** Made by joffrey cottin
** Login   <cottin_j@epitech.net>
**
** Started on  Sat Dec  3 07:14:06 2011 joffrey cottin
** Last update Mon Dec  5 13:08:13 2011 joffrey cottin
*/

#include        "include/my_printf.h"
#include        "include/minishell.h"

int execute_command(char *binary, char **elems, char **environ, int pid)
{
  int status;

  if (pid > 0)
    wait(&status);
  else if (pid == 0)
    {
      execve(binary, elems, environ);
      return (1);
    }
  return (0);
}

int prepare_command(char **paths, char **elems, char **environ)
{
  int pid;
  int success;
  char *binary;

  pid = -2;
  while (*paths)
    {
      binary = my_strcat(*paths, elems[0]);
      if ((success = access(binary, X_OK)) != -1)
        {
          if ((pid = fork()) != -1)
            execute_command(binary, elems, environ, pid);
          return (0);
        }
      paths++;
    }
  if (pid <= -1)
    {
      error_mess(5, "prepare_command", "execute_command.c");
      my_printf("Command Not Found.\n");
      return (0);
    }
  return (0);
}

/*
** core.c for  in /home/cottin_j/Bureau/bureau/mini2
** 
** Made by joffrey cottin
** Login   <cottin_j@epitech.net>
** 
** Started on  Wed Nov 30 01:38:07 2011 joffrey cottin
** Last update Mon Dec  5 16:15:50 2011 joffrey cottin
*/

#include        "include/my_printf.h"
#include        "include/minishell.h"

void    catch_sigint()
{
  char		*etoile;
  int		curs_env;
  extern char	**environ;

  curs_env = search_line(USER, environ);
  if (curs_env)
    {
        etoile = (&environ[curs_env][LUSER]);
        my_printf("%s:$>", etoile);
    }
  else
    my_printf("$>");
}

int     read_line(char *buffer, char **elems, char **environ, char **paths)
{
  int          return_built;
  int           ret;

  return_built = 0;
  signal(SIGINT, catch_sigint);
  if (((ret = read(0, buffer, SIZE)) > 0))
    {
      buffer[ret - 1] = 0;
      if (ret == 1)
	return (1);
      pars_args2((epur_str(buffer)), elems);
      if (*elems && (!(return_built = built_in(environ, elems))))
	prepare_command(paths, elems, environ);
      else if (return_built == 1)
	return (0);
      return (1);
    }
  else
    error_mess(2, "readline", "core.c");
  return (0);
}

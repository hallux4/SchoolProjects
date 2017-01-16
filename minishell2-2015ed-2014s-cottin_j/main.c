/*
** main.c for  in /home/cottin_j/Bureau/bureau/mini2/Source/mysh2
**
** Made by joffrey cottin
** Login   <cottin_j@epitech.net>
**
** Started on  Thu Dec  1 18:38:34 2011 joffrey cottin
** Last update Mon Dec  5 06:35:28 2011 joffrey cottin
*/

#include        "include/my_printf.h"
#include        "include/minishell.h"

int     collect_info(char **environ)
{
  
  char          *buffer;
  char          *elems[SIZEM];
  char          **paths;

  buffer = NULL;
  while (1)
    {
      if (!(buffer = xmalloc(SIZE + 1, "read_line", "core.c")))
        return (0)
          ;
      fill_zero(buffer);
      fill_null(elems);
      catch_sigint() ;
      if (!(paths  = pars_path(environ)))
        return (0 );
      if (!(read_line(buffer, elems, environ, paths)))
        return (0 );
      free(buffer );
    }
  return (0);
}

/*
**
*/
int     main()
{
  extern char   **environ;

  if (*environ)
    collect_info(environ);
  else
    if (!(error_mess(0, "main", "main.c")))
      return (0);
  return (0);
}

/*
** pars_path.c for  in /home/cottin_j/Bureau/bureau/mini2/Source/mysh2
** 
** Made by joffrey cottin
** Login   <cottin_j@epitech.net>
** 
** Started on  Thu Dec  1 18:40:42 2011 joffrey cottin
** Last update Sun Dec  4 14:31:36 2011 joffrey cottin
*/

#include        "include/my_printf.h"
#include        "include/minishell.h"

char    **cut_to_pieces2(char *str, char **elems)
{
  int   i;
  int   j;

  i = 0;
  j = 0;
  while (*str)
    {
      if (*str == ':')
	{
          elems[i][j++] = '/';
          elems[i++][j] = '\0';
          if (!(elems[i] = xmalloc(SIZEM, "cut_to_pieces", "parth_path.c")))
	    return (0);
          j = 0;
        }
      else
        elems[i][j++] = *str;
      str++;
    }
  elems[i][j++] = '/';
  elems[i][j++] = '\0';
  return (elems);
}

int     search_line(char *path, char **environ)
{
  int   i;
  int   valid;

  i = 0;
  valid = 0;
  while (environ[i] && (my_strncmp(path, environ[i], my_strlen(path))) != 0)
  {
      i++;
  }
  if ((my_strncmp(path, environ[i], my_strlen(path))) == 0)
      {
          valid++;
          return (i);
      }
  return (0);
}

char    **pars_path(char **environ)
{
  char  *path = (PATH);
  char  *copy_path;
  char  **elems;
  int   curs_path;

  if (!(elems = xmalloc(SIZEM + 1, "pars_path", "pars_path.c")))
    return (0);
  *elems = malloc(sizeof(char) * (SIZEM));
  if (!(*elems = xmalloc(SIZEM + 1, "pars_path", "pars_path.c")))
    return (0);
  curs_path = search_line(path, environ);
  if (curs_path == 0)
    {
      error_mess(6, "pars_path", "pars_path.c");
      return 0;
    }
  if (!(copy_path = xmalloc(my_strlen(environ[curs_path]),
			    "pars_path", "pars_path.c")))
    return (0);
  my_strcpy(copy_path, environ[curs_path]);
  copy_path += 5;
  elems = cut_to_pieces2(copy_path, elems);
  return (elems);
}

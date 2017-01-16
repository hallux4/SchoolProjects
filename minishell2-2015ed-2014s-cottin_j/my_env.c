/*
 ** my_env.c for  in /home/cottin_j/Bureau/bureau/mini2
 ** 
 ** Made by joffrey cottin
 ** Login   <cottin_j@epitech.net>
 ** 
 ** Started on  Sat Dec  3 05:56:25 2011 joffrey cottin
 ** Last update Sun Dec  4 14:31:02 2011 joffrey cottin
 */

#include        "include/my_printf.h"
#include        "include/minishell.h"

int my_unsetenv (char **elems, char **environ)
{
  char *variable;
  int i;
  int curs_env;

  i = 0;
  variable = NULL;
  if (elems[1])
    {
      curs_env = search_line (elems[1], environ);
      if (curs_env)
        {
          my_printf ("%s\n", &environ[curs_env][my_strlen (elems[1])]);
        }
      else
        {
          my_printf ("%s:", elems[1]);
          error_mess (7, "my_unsetenv", "my_env.c");
        }
    }
  return (4);
}

int my_cd (char **elems, char **environ)
{
  char *etoile;
  char *home = ("HomeSweetHome");

  etoile = NULL;
  if (elems[1])
    {
      if (0 != chdir (elems[1]))
        {
          my_printf ("cd: %s: Is not a valid destination", elems[1]);
          error_mess (4, "my_cd", "my_env.c");
        }
    }
  if (!(elems[1]))
    {
      if (search_line ("HOME=", environ))
        etoile = (&environ[search_line ("HOME=", environ)][my_strlen ("HOME=")]);
      else
        etoile = home;
      if (0 != chdir (etoile))
        {
          my_printf ("cd: %s: Can't Find Home Directory %s\n", etoile, etoile);
          error_mess (4, "my_cd", "my_env.c");
        }
    }
  return (3);
}

/*
 ** return (result)
 ** exit = 1, env = 2, cd = 3, unsetenv = 4
 */
int built_in (char ** environ, char **elems)
{
  int result;

  result = 0;
  if (!(my_strncmp (elems[0], "exit", 4)))
    result = my_printf ("See You Later.\n");
  if (!(my_strncmp (elems[0], "env", 3)))
    result = print_tab (environ);
  if (!(my_strncmp (elems[0], "cd", 2)))
    result = my_cd (elems, environ);
  if (!(my_strncmp (elems[0], "setenv", 6)))
    result = my_cd (elems, environ);
  if (!(my_strncmp (elems[0], "unsetenv", 8)))
    result = my_cd (elems, environ);
  return (result);
}

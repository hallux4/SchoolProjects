/*
** my_select.c for  in /home/cottin_j/Bureau/bureau/select
** 
** Made by joffrey cottin
** Login   <cottin_j@epitech.net>
** 
** Started on  Fri Nov 25 15:04:24 2011 joffrey cottin
** Last update Sun Nov 27 20:15:58 2011 joffrey cottin
*/

#include	"hselect.h"

void	my_select(int argc, char **argv)
{
  char		*termentry;
  int		i;

  i = 1;
  termentry = NULL;
  if ((termentry = get_term(termentry)))
     if (test_tgetent(0, termentry))
        fill_name_struct(argc, argv);
}

char    *get_term(char *termentry)
{
  extern char   **environ;
  int   i = 0;

  if (environ != NULL)
    while ( environ[i] != NULL)
      {
        if (my_strncmp(environ[i], "TERM=", 5) == 0)
          return (&environ[i][5]);
        i = i + 1;
      }
  error_code(TERMENTRY);
  return (NULL);
}

int	test_tgetent(int o, char *termentry)
{
  if ((tgetent(NULL, termentry)) < 1)
    {
      error_code(DB_TERM);
      return (0);
    }
  return (1);
}

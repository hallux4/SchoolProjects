/*
** dataz.c for  in /home/cottin_j/lemipc-2015-2014s-cottin_j
** 
** Made by joffrey cottin
** Login   <cottin_j@epitech.net>
** 
** Started on  Sun Mar 25 17:03:29 2012 joffrey cottin
** Last update Sun Mar 25 17:48:30 2012 hallux
*/

#include	"lemipc.h"

bool		winner(int *battleground, int squad)
{
  int		i;

  i = 0;
  while ((battleground[i] != 0 && battleground[i] != squad)
         || i < map_size)
    i++;
  if (i == map_size - 1)
    return (true);
  return (false);
}

bool		go(int *battleground, int squad)
{
  int		i;

  i = 0;
  if (get_playerz(battleground) < 4)
    return (false);
  while ((battleground[i] != 0 && battleground[i] != squad)
         || i < map_size)
    i++;
  if (i == map_size - 1)
    return (false);
  return (true);
}

key_t		the_key_is(const char *pathname, int id)
{
  key_t		key;

  if (pathname == NULL)
    error_func("Ftok error : the pathname is NULL\n", EXIT_FAILURE);
  key = ftok(pathname, id);
  if (key == -1)
    error_func("Ftok error : cannot create key\n", EXIT_FAILURE);
  return (key);
}

void		continue_dsp(int *battleground)
{
  while (get_playerz(battleground) > 1)
    {
      map_dsp(battleground);
      sleep(1);
    }
  exit(EXIT_SUCCESS);
}

/*
** main.c for  in /home/cottin_j/lemipc-2015-2014s-cottin_j
**
** Made by joffrey cottin
** Login   <cottin_j@epitech.net>
**
** Started on  Sun Mar 25 17:05:43 2012 joffrey cottin
** Last update Sun Mar 25 17:47:01 2012 hallux
*/

#include	"lemipc.h"

const int	map_size = 100;
const int	map_len = 10;
const int	time_to_wait = 1000000;

int		main(int argc, char **argv)
{
  if (argc == 2)
    execute(atoi(argv[1]), false);
  else if (argc == 3)
    {
      if (strcmp(argv[2], "-m") == 0)
        execute(atoi(argv[1]), true);
    }
  else
    error_func("Usage : ./lemipc [no squad] [options]\n"
               "Options:\n"
               "-m : Show battleground\n", EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

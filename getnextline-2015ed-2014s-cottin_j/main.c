/*
** main.c for  in /home/cottin_j/Bureau/ssh/get_next_line_ready
** 
** Made by joffrey cottin
** 
** Started on  Tue Nov 29 15:24:30 2011 joffrey cottin
** Last update Sat Dec  3 02:07:11 2011 joffrey cottin
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

int main()/*(int ac, char **av)*/
{
  int	fd;
  char	*s;

  fd = 0;
  /*ac--;
  if ((fd = open(av[1], O_RDONLY)) == -1)
    {
      printf("can't open");
      return (0);
      }*/

  while ((s = get_next_line(fd)))
    {
      printf("%s\n", s);
      free(s);
      }
/*
  if ((close(fd)) == -1)
  printf("can't close");*/

  /* s = get_next_line(fd); */
  /*   printf("%s\n", s); */
  /* free(s); */
  return (0);
}

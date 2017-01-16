/*
** my_signal.c for  in /home/cottin_j/Bureau/bureau/minitalk
** 
** Made by joffrey cottin
** Login   <cottin_j@epitech.net>
** 
** Started on  Fri Nov 18 20:11:30 2011 joffrey cottin
** Last update Sun Nov 20 14:55:36 2011 joffrey cottin
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<signal.h>
#include	"headtalk.h"

char	bit;

void    tab(char *bin)
{
  int   i;

  i = 0;
  while (i < 8)
    bin[i++] = 0;
}

void	catch_sigusr1()
{
  signal(SIGUSR1, catch_sigusr1);
  bit = '1';
}

void	catch_sigusr2()
{
  signal(SIGUSR2, catch_sigusr2);
  bit = '0';
}

int	main()
{
  int	i;
  char	bin[8] = {0};

  i = 0;
  my_put_nbr(getpid());
  my_putstr("\n");
  while (1)
    {
      if (i > 7)
	{
	  my_putchar(my_getnbr_base(bin, "01"));
	  tab(bin);
	  i = 0;
	}
      signal(SIGUSR1, catch_sigusr1);
      signal(SIGUSR2, catch_sigusr2);
      pause();
      bin[i] = bit;
      i++;
    }
}

/*
** main.c for  in /home/cottin_j/Bureau/bureau/minitalk
** 
** Made by joffrey cottin
** Login   <cottin_j@epitech.net>
** 
** Started on  Sat Nov 19 07:38:34 2011 joffrey cottin
** Last update Sun Nov 20 23:40:22 2011 joffrey cottin
*/

#include	<signal.h>
#include        "headtalk.h"

int	number = 0;

int my_putstr(char *str)
{
  int   i;

  i = 0;
  while (str[i])
    {
      my_putchar(str[i]);
      i++;
    }
}

void    catch_sigint()
{
  int	rest;

  rest = 0;
  signal(SIGINT, catch_sigint);
  my_putstr("\n        ");
  my_put_nbr(rest - number);
  my_putstr(" characters were sent.\n");
  signal(SIGINT, catch_sigint);
  my_putstr("\n        Please wait till the sending is complete.\n");
}

void    catch_sigquit()
{
  int	rest;

  rest = 0;
  signal(SIGQUIT, catch_sigquit);
  my_putstr("\n        ");
  my_put_nbr(rest - number);
  my_putstr(" characters were sent.\n");
  signal(SIGINT, catch_sigint);
  my_putstr("\n        Please wait till the sending is complete.\n");
}

int     main(int argc, char **argv)
{
  int   i;
  int   len;

  number = len;
  i = 0;
  if (argc > 2)
    {
      len = my_strlen(argv[2]);
      my_putstr("\n        You'll send:");
      my_put_nbr(len);
      my_putstr(" characters, please wait till the end.\n");
      signal(SIGINT, catch_sigint);
      signal(SIGQUIT, catch_sigquit);
      my_read_str(argv[2], len, my_getnbr(argv[1]));
    }
}

/*
** sourceserv2.c for  in /home/cottin_j/Bureau/minitalk (copie)
** 
** Made by joffrey cottin
** Login   <cottin_j@epitech.net>
** 
** Started on  Sat Nov 19 23:08:55 2011 joffrey cottin
** Last update Sat Nov 19 23:10:19 2011 joffrey cottin
*/

#include	"headtalk.h"

void my_putchar(char c)
{
  write (1, &c, 1);
}

int my_put_nbr(int nb)
{
  if (nb == 0)
    {
      my_putchar('0');
      return 0;
    }
  if (nb <  0)
    {
      my_putchar('-');
    }
  my_modulo(nb);
}

int my_modulo(int nb)
{
  int rest;

  if (nb)
    {
      rest = nb % 10;
      if (rest < 0)
        rest = -rest;
      my_modulo(nb / 10);
      my_putchar(rest + 48);
    }
}

int my_strlen(char *str)
{
  int   i;

  i = 0;
  while (str[i++]);
  return (i - 1);
}

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

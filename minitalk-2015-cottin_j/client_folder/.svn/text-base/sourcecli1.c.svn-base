/*
** sourcetalk1.c for  in /home/cottin_j/Bureau/bureau/minitalk
** 
** Made by joffrey cottin
** Login   <cottin_j@epitech.net>
** 
** Started on  Sat Nov 19 05:54:32 2011 joffrey cottin
** Last update Sat Nov 19 10:26:24 2011 joffrey cottin
*/

#include	"headtalk.h"

void     my_putchar(char c)
{
  write(1, &c, 1);
}

int      my_strlen(char *str)
{
  int   i;

  i = 0;
  while (str[i++]);
  return (i - 1);
}

int my_getnbr(char *str)
{
  int   signe;
  int   pos;
  int   nbr;

  signe = 1;
  pos = 0;
  while (str[pos] != '\0' && (str[pos] == '+' || str[pos] == '-'))
    {
      if (str[pos] == '-')
        {
          signe = signe * -1;
        }
      pos = pos + 1;
    }
  str  = str + pos;
  nbr = 0;
  pos = 0;
  while (str[pos] >= '0' && str[pos] <= '9')
    {
      nbr = nbr * 10;
      nbr = nbr + (str[pos] - '0');
      pos = pos + 1;
    }
  return (nbr * signe);
}
int     my_put_nbr(int nb)
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

int     my_modulo(int nb)
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

/*
** source_annexe.c for  in /home/cottin_j/Bureau/bureau/select
** 
** Made by joffrey cottin
** Login   <cottin_j@epitech.net>
** 
** Started on  Fri Nov 25 15:06:55 2011 joffrey cottin
** Last update Fri Nov 25 15:06:56 2011 joffrey cottin
*/

#include        "hselect.h"

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  i = 0;
  while (s2[i] != '\0' && s1[i] == s2[i] && n >= 2)
    {
      i++;
      n--;
      if (s2[i] != s1[i])
	return s1[i] - s2[i];
    }
  if (s2[i] != s1[i])
    return s1[i] - s2[i];
  return 0;
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i++]);
  return (i - 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      my_putchar(str[i]);
      i++;
    }
}

void	my_put_nbr(int nb)
{
  if (nb == 0)
    {
      my_putchar('0');
      return;
    }
  if (nb <  0)
    {
      my_putchar('-');
    }
  my_modulo(nb);
}

void	my_modulo(int nb)
{
  int	rest;

  if (nb)
    {
      rest = nb % 10;
      if (rest < 0)
        rest = -rest;
      my_modulo(nb / 10);
      my_putchar(rest + 48);
    }
}

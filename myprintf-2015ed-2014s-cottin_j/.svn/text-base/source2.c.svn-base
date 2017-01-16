/*
** source2.c for  in /home/cottin_j/Bureau/ssh/myprintf-2015ed-2014s-cottin_j
** 
** Made by joffrey cottin
** Login   <cottin_j@epitech.net>
** 
** Started on  Fri Nov 18 15:01:47 2011 joffrey cottin
** Last update Fri Nov 18 15:01:50 2011 joffrey cottin
*/

#include        <stdio.h>
#include        <stdarg.h>
#include        <stdint.h>
#include        "hprintf.h"

int     dispatch(int type, va_list *pile, char *mod)
{
  int           wrote;

  if (type > 0 && type < 4)
    this_is_int(type, (va_arg(*pile, int)));
  else if (type > 3 && type < 7 || type > 11)
    this_is_unsign_int(type, (va_arg(*pile, unsigned)));
  else if (type == 7)
    this_is_not_good();
  else if (type > 7 && type < 11)
    this_is_pointer(type, (va_arg(*pile, char*)));
  else if (type > 10 && type < 12)
    {
      if ((sizeof(void*) == 4))
        this_is_unsign_int(type, (va_arg(*pile, unsigned)));
      else
        my_putstr("32bits only");
    }
}

int	my_put_nbr(int nb)
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

int	my_modulo(int nb)
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

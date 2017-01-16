/*
** my_printf.c for  in /home/cottin_j/Bureau/bureau/my_printf
** 
** Made by joffrey cottin
** Login   <cottin_j@epitech.net>
** 
** Started on  Tue Nov 15 21:22:50 2011 joffrey cottin
** Last update Fri Nov 18 11:15:24 2011 joffrey cottin
*/

#include        <stdio.h>
#include        <stdarg.h>
#include        "hprintf.h"

int    my_printf(char *mod, ...)
{
  va_list	pile;
  int		type;
  int		wrote;

  if (*mod)
    va_start(pile, mod);
  while (*mod)
    {
      if (*mod == '%')
	{
	  mod = space_disapears(++mod);
	  if ((type = pars_mod(mod)) > 0)
	    {
	      mod++;
	      dispatch(type, &pile, mod);
	    }
	  else
	    mod++;
	}
      else
	my_putchar_s(mod++);
    }
  va_end(pile);
}

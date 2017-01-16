/*
** parse_space.c for  in /home/cottin_j/Bureau/bureau/printfbis
** 
** Made by joffrey cottin
** Login   <cottin_j@epitech.net>
** 
** Started on  Thu Nov 17 13:50:42 2011 joffrey cottin
** Last update Sun Nov 20 23:09:01 2011 joffrey cottin
*/

#include        <stdio.h>
#include        <stdarg.h>
#include        "hprintf.h"

char	*space_disapears(char *mod)
{
  while (*mod && *mod == ' ' || *mod && *mod == '+' || *mod && *mod == '-'
	 || *mod && *mod == 'l' || *mod && *mod == 'h' || *mod && *mod == 'q'
	 || *mod && *mod == 'j' || *mod && *mod == 'z'|| *mod && *mod == 't'
	 || *mod && *mod >= '0' && *mod <= '9' || *mod && *mod == '\#'
	 || *mod && *mod == '.' || *mod && *mod == 'L' || *mod && *mod == '*')
    mod++;
  return (mod);
}

char	*my_putchar_s(char *mod)
{
  int	i;

  i = 0;
  if (mod[i])
    {
      write(1, &mod[i], 1);
      mod = mod + i;
      return (mod);
    }
}

int	pars_mod(char *mod)
{
  int	i;
  t_type      conv[] = {
    {'i', 1}, {'d', 2}, {'c', 3}, {'o', 4}, {'x', 5},
    {'X', 6}, {'%', 7}, {'s', 8}, {'S', 10}, {'p', 11}, {'b', 12},
    {'u', 13}, {0, 0}
  };
  i = 0;
  while (conv[i].modif)
    {
      if (*mod == conv[i].modif)
	return (conv[i].type);
      i++;
    }
  my_putstr("%");
  my_putchar(*mod);
  return (0);
}

void my_putnbr_base(unsigned nbr, char *base)
{
  if ((nbr / my_strlen(base)) != 0)
    my_putnbr_base((nbr / my_strlen(base)), base);
  my_putchar(base[(nbr % my_strlen(base))]);
}

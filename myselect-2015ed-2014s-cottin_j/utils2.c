/*
** utils2.c for  in /home/cottin_j/Bureau/bureau/select
** 
** Made by joffrey cottin
** Login   <cottin_j@epitech.net>
** 
** Started on  Thu Nov 24 11:10:21 2011 joffrey cottin
** Last update Sun Nov 27 20:55:33 2011 joffrey cottin
*/

#include        "hselect.h"

void    my_putchar(char c)
{
  write (2, &c, 1);
}

void	my_putspace(int nb_space)
{
  int	i;

  i = 0;
  while (i < nb_space)
    {
      my_putchar(' ');
      i++;
    }
}

/*
void     my_putstr_blank(int o, int j, int lenstrmax, t_list *base)
{
  char          *cmstr;
  int           i;

  i = 0;
  cmstr = tgetstr("cm", 0);
  while (o < base[0].colonne)
    {
      tputs(tgoto(cmstr, j, o), 1, my_putcharint);
      my_put_void(base);
      o++;
    }
  return;
*/
/*
my_putstr_blanc(base)
*/
  void    backdelkey(t_list *base)
  {
  }

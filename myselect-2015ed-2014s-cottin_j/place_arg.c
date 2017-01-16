/*
** place_arg.c for  in /home/cottin_j/Bureau/bureau/select
** 
** Made by joffrey cottin
** Login   <cottin_j@epitech.net>
** 
** Started on  Thu Nov 24 12:34:47 2011 joffrey cottin
** Last update Sun Nov 27 20:16:30 2011 joffrey cottin
*/

#include        "hselect.h"

int	first_jet(int j, int lenstrmax, t_list *base)
{
  char		*cmstr;
  int		i;
  int		curs;
  static int	k;

  cmstr = tgetstr("cm", 0);
  while (base[k].name && i < base[0].maxline - 2)
    {
      tputs(tgoto(cmstr, j, i), 1, my_putcharint);
      base[k].coorc = j;
      base[k].coorl = i;
      base[k].index = k;
      base[k].tagrm = 0;
      my_putstr(base[k].name);
      my_putspace((lenstrmax + 6) - (base[k].len + 4));
      i++;
      k++;
    }
  curs = k;
  return (curs);
}

void	my_put_void(t_list *base)
{
  int	i;

  i = 0;
  while (i++ < base[0].lenstrmax)
    my_putchar(' ');
}

void     void_jet(int o, int j, int lenstrmax, t_list *base)
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
}

/*base[0].colonne => hauteur 1ere colonne complete
**base[0].lenstrmax => longeur du plus grand argument
**
*/
void    fill_name_struct(int argc, char  **argv)
{
  int           i;
  t_list        *base;
  int           j;

  i = 0;
  j = 0;
  base = malloc(sizeof(t_list) * argc);
  base[0].maxcol = tgetnum("co");
  base[0].maxline = tgetnum("li");
  fill_struct(base, argc, argv);
  cleascreen();
  arrange_name(base, argc);
  cursorpos(base);
  testkey(base, argc, argv);
}

void     return_output(t_list *base)
{

}

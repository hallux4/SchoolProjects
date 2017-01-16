/*
** cursors.c for  in /home/cottin_j/Bureau/bureau/select
** 
** Made by joffrey cottin
** Login   <cottin_j@epitech.net>
** 
** Started on  Fri Nov 25 16:07:16 2011 joffrey cottin
** Last update Sun Nov 27 20:14:32 2011 joffrey cottin
*/

#include "hselect.h"

void	cursorpos(t_list *base)
{
  char	*cmstr;
  char	*usmod;
  char	*uemod;

  base[0].cursorpos = 0;
  cmstr = tgetstr("cm", 0);
  usmod = tgetstr("us", 0);
  uemod = tgetstr("ue", 0);

  tputs(tgoto(cmstr, 0, 0), 1, my_putcharint);
  tputs(usmod, 1, my_putcharint);
  my_putstr(base[0].name);
  tputs(uemod, 1, my_putcharint);
  tputs(tgoto(cmstr, 0, base[0].colonne), 1, my_putcharint);
}

void	my_putstr_pos(t_list *base)
{
  int	i;
  char	*cmstr;
  char	*mrmod;
  char	*memod;
  
  i = 0;
  mrmod = tgetstr("mr", 0);
  memod = tgetstr("me", 0);
    while (base[i].name)
    {
      if (base[0].cursorpos == base[i].index)
	{
          cmstr = tgetstr("cm", 0);
	  tputs(tgoto(cmstr, base[i].coorc, base[i].coorl), 1, my_putcharint);
          if (base[i].tagrm == 1)
             tputs(mrmod, 1, my_putcharint);
	  my_putstr(base[i].name);
          tputs(memod, 1, my_putcharint);
          tputs(tgoto(cmstr, 0, base[0].colonne + 1), 1, my_putcharint);
	  return;
	}
      i++;
    }
}

void	downkey(t_list *base)
{
  char	*cmstr;
  char	*usmod;
  char	*uemod;

  cmstr = tgetstr("cm", 0);
  usmod = tgetstr("us", 0);
  uemod = tgetstr("ue", 0);
  tputs(uemod, 1, my_putcharint);
  my_putstr_pos(base);
  tputs(usmod, 1, my_putcharint);
  base[0].cursorpos++;
  if (base[0].cursorpos >= base[0].indexmax)
  base[0].cursorpos = 0;
  my_putstr_pos(base);
}

void	upkey(t_list *base)
{
  char	*cmstr;
  char	*usmod;
  char	*uemod;

  cmstr = tgetstr("cm", 0);
  usmod = tgetstr("us", 0);
  uemod = tgetstr("ue", 0);
  tputs(uemod, 1, my_putcharint);
  my_putstr_pos(base);
  tputs(usmod, 1, my_putcharint);
  base[0].cursorpos--;
  if (base[0].cursorpos < 0)
  base[0].cursorpos = base[0].indexmax - 1;
  my_putstr_pos(base);
}

void	spacekey(t_list *base)
{
  char	*mrmod;
  char	*memod;

  mrmod = tgetstr("mr", 0);
  memod = tgetstr("me", 0);
  tputs(mrmod, 1, my_putcharint);
  my_putstr_pos(base);
  base[base[0].cursorpos].tagrm = 1;
  tputs(memod, 1, my_putcharint);
}

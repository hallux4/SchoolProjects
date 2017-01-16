/*
** fillstruct.c for  in /home/cottin_j/Bureau/bureau/select
** 
** Made by joffrey cottin
** Login   <cottin_j@epitech.net>
** 
** Started on  Thu Nov 24 23:18:04 2011 joffrey cottin
** Last update Sun Nov 27 20:54:47 2011 joffrey cottin
*/
#include        "hselect.h"

/*
** remplis le tableau de structure. nom et longueur des noms.
*/
int     fill_struct(t_list *base, int argc, char **argv)
{
  int	i;

  base[0].lenstrmax = 0;
  i = 0;
  while (argv[i])
    {
      base[i].name = argv[i];
      base[i].len = my_strlen(argv[i]);
      if (base[0].lenstrmax < (base[i].len))
	base[0].lenstrmax = base[i].len;
      i++;
    }
  base[i].name = NULL;
  return (0);
}

void	cleascreen()
{
  char          *clscr;

  clscr = tgetstr("cl", 0);
  tputs(clscr, 1, my_putcharint);
}

/*
** range les arguments par colonne puis en ligne si nécessaire.
** donne l'axe colonne, ligne pour chaque elements.
*/
int	arrange_name(t_list *base, int argc)
{
  int	j;
  int	i;
  int	miss;
  char	*cmstr;

  j = 0;
  cmstr = tgetstr("cm", 0);
  i = first_jet(j, base[0].lenstrmax, base);
  base[0].colonne = i;
  while (i < argc && j < (base[0].maxcol - 3 - (base[0].lenstrmax * 2)))
    {
      my_putstr(" ");
      j += base[0].lenstrmax + 2;
      i = first_jet(j, base[0].lenstrmax, base);
    }
  base[0].indexmax = i;
  miss = (base[0].colonne - (base[i - 1].coorl + 1));
  if (((base[0].colonne - (base[i - 1].coorl + 1))) != 0)
    void_jet(base[0].colonne - miss, j, base[0].lenstrmax, base);
  if ((argc - i) > 0)
    {
      tputs(tgoto(cmstr, 0, base[0].colonne), 1, my_putcharint);
      my_putstr("The window is too small, please resize it if you can.");
    }
  return (0);
}

int	testkey(t_list *base, int argc, char **argv)
{
  char		buffer[3];
  char	        *uemod;

  uemod = tgetstr("ue", 0);
  while (1)
  {
    read(0, buffer, 3);
    if (buffer[0] == 27 && buffer[1] == '[')
      {
	if (buffer[2] == 'A')
	  upkey(base);
	else if (buffer[2] == 'B')
	  downkey(base);
      }
    else if (buffer[0] == 127 || buffer[0] == '\b')
      backdelkey(base);
    else if (buffer[0] == ' ')
      spacekey(base);
    else if (buffer[0] == '\n')
      {
        tputs(uemod, 1, my_putcharint);
	return_output(base);
        return (0);
      }
   }
}

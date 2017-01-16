/*
** sourcecli2.c for  in /home/cottin_j/
** 
** Made by joffrey cottin
** Login   <cottin_j@epitech.net>
** 
** Started on  Sun Nov 20 14:46:09 2011 joffrey cottin
** Last update Sun Nov 20 15:03:45 2011 joffrey cottin
*/

#include "headtalk.h"

int	my_swap_tab(int *tab_bin)
{
  int	o;
  int	i;
  int	j;

  i = 0;
  j = 7;
  while (i < 4)
    {
      o = tab_bin[i];
      tab_bin[i++] = tab_bin[j];
      tab_bin[j--] = o;
    }
}

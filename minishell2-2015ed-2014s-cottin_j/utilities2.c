/*
** utilities2.c for  in /home/cottin_j/Bureau/bureau/mini2/Source/mysh2
** 
** Made by joffrey cottin
** Login   <cottin_j@epitech.net>
** 
** Started on  Thu Dec  1 18:40:07 2011 joffrey cottin
** Last update Thu Dec  1 18:43:36 2011 joffrey cottin
*/

#include        "include/my_printf.h"
#include        "include/minishell.h"

void    fill_null(char **tab)
{
  int i;

  i = 0;
  while (i < SIZEM)
    tab[i++] = NULL;
}

void    fill_zero(char *str)
{
  int i;

  i = 0;
  while (i < SIZE)
    str[i++] = 0;
}

/*
** errorselect.c for  in /home/cottin_j/Bureau/bureau/select
** 
** Made by joffrey cottin
** Login   <cottin_j@epitech.net>
** 
** Started on  Wed Nov 23 01:47:34 2011 joffrey cottin
** Last update Wed Nov 23 04:22:44 2011 joffrey cottin
*/
#include        "hselect.h"

void	error_code(int code)
{
  if (code == MISS_ARG)
    my_putstr("Please, input your choices, at least one.\n");
  if (code == TERMENTRY)
    my_putstr("Cannot retrieve <TERM=Variable>\n");
  if (code == DB_TERM)
    my_putstr("Termcaps database not found.\n");
  if (code == CANNOT_LIST)
    my_putstr("Your linked list has gone wrong.\n");
}

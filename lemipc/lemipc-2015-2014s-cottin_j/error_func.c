/*
** error_func.c for  in /home/cottin_j/lemipc-2015-2014s-cottin_j
**
** Made by joffrey cottin
** Login   <cottin_j@epitech.net>
**
** Started on  Sun Mar 25 17:34:36 2012 joffrey cottin
** Last update Sun Mar 25 17:48:51 2012 hallux
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	"lemipc.h"

void		error_func(char *error, int code)
{
  delete_map();
  fprintf(stderr, "function : %s", error);
  exit(code);
}

/*
** main.c for  in /home/cottin_j/Bureau/bureau/my_printf
** 
** Made by joffrey cottin
** Login   <cottin_j@epitech.net>
** 
** Started on  Wed Nov 16 10:29:05 2011 joffrey cottin
** Last update Mon Nov 21 09:18:32 2011 joffrey cottin
*/

#include	<stdio.h>
#include	<stdarg.h>
#include	<limits.h>
#include	"hprintf.h"

int	main(int argc, char **argv)
{
  char toto[] = "mamamia";

  

  
  my_printf("0");
  my_printf("-i donne %              i\n", -123456);
  my_printf("-d donne %     d\n", -123456);
  my_printf("-o donne %o\n", -123456);
  my_printf("-x donne %x\n", -123456);
  my_printf("-X donne %X\n", -123456);
  my_printf("-b donne %b\n", -123456);
  
  my_printf("i donne %i\n", 123456);
  my_printf("d donne %d\n", 123456);
  my_printf("o donne %o\n", 123456);
  my_printf("x donne %x\n", 123456);
  my_printf("X donne %X\n", 123456);
  my_printf("b donne %b\n", 123456);
  
  my_printf("%s\n", toto);  
  toto[2] = 31;
  toto[4] = 127;
  my_printf("%S\n", toto);  
  my_printf("Ma batterie est à %d%%%#%M et je pointe sur %            s \n",
	    50 + 50, toto);
  printf("Ma batterie est à %d%     %     %#%M et je pointe sur %                s \n\n",
	 50 + 50, toto);
  my_printf("%p\n", toto);
  printf("%p\n\n", toto);
}

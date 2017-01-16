/*
** error_message.c for  in /home/cottin_j/Bureau/bureau/mini2/Source/mysh2
** 
** Made by joffrey cottin
** Login   <cottin_j@epitech.net>
** 
** Started on  Thu Dec  1 18:40:25 2011 joffrey cottin
** Last update Sun Dec  4 14:03:12 2011 joffrey cottin
*/

#include        "include/my_printf.h"
#include        "include/minishell.h"

int    error_mess(int type, char* func, char *file)
{
  if (type == 0)
    my_printf("\nExit : Environ Not Found : %s in %s\n", func, file);
  if (type == 1)
    my_printf("\nMalloc Faillure : %s in %s\n", func, file);
  if (type == 2)
    my_printf("\nSee You Later.\n");
  if (type == 3)
    my_printf("\nCan't Read\n");
  if (type == 4)
    my_printf("\nChdir Faillure : %s in %s\n", func, file);
  if (type == 6)
    my_printf("\nCan't Resolve Path : %s in %s\n", func, file);
  if (type == 7)
    my_printf("\nNot a valid entry : %s in %s\n", func, file);
  return (0);
}

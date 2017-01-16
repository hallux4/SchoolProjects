/*
** pars_args.c for  in /home/cottin_j/Bureau/bureau/mini2/Source/mysh2
** 
** Made by joffrey cottin
** Login   <cottin_j@epitech.net>
** 
** Started on  Thu Dec  1 18:39:34 2011 joffrey cottin
** Last update Mon Dec  5 16:21:02 2011 joffrey cottin
*/

#include        "include/my_printf.h"
#include        "include/minishell.h"

char            *del_space(char *str)
{
  int           i;

  i = 0;
  while (*str && str[i] == ' ')
    {
      while (*str && str[i] == ' ')
        i++;
    }
  return (&str[i]);
}

char *epur_str(char *str)
{
  int space;
  int i;
  char *news;
  int j;

  space = 1;
  i = 0;
  j = 0;
  if (!(news = xmalloc(my_strlen(str), "epur_str", "pars_arg.c")))
    return (0);
  while (str[i])
    {
      while (str[i] == ' ' && space)
	i++;
      space = 0;
      while (str[i] == ' ' && str[i + 1] == ' ')
	i++;
      news[j++] = str[i++];
    }
  news[j] = 0;
  return news;
}

int     pars_args2(char *start, char **elems)
{
  while (*start)
    {
      if (*start == ' ')
	start++;
      *elems = start;
      while (*start && *start != ' ')
	start++;
      *start = '\0';
      start++;
      elems++;
    }
   return 0;
}

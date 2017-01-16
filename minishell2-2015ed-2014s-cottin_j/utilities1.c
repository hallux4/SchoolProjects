/*
** utilities1.c for  in /home/cottin_j/Bureau/bureau/mini2/Source/mysh2
** 
** Made by joffrey cottin
** Login   <cottin_j@epitech.net>
** 
** Started on  Thu Dec  1 18:41:29 2011 joffrey cottin
** Last update Sat Dec  3 07:20:53 2011 joffrey cottin
*/

/*#include	<unistd.h>*/
#include        "include/my_printf.h"
#include        "include/minishell.h"

int     my_strncmp(char *s1, char *s2, int n)
{
  int   i;

  i = 0;
  while (s1[i] && s1[i] == s2[i] && i < n - 1)
    i++;
  return (s1[i] - s2[i]);
}

char    *my_strcpy(char *dest, char *src)
{
  int   i;

  i = 0;
  while (src[i])
    {
      dest[i] = src[i];
      i += 1;
    }
  dest[i] = '\0';
  return dest;
}

void     *xmalloc(int size, char *func, char *file)
{
  void *u;

  if (!(u = malloc(size)))
    if (!(error_mess(1, func, file)))
      return u;
  return u;
}

int    print_tab(char **tab)
{
  while (*tab)
    {
      my_printf("%s\n", *tab);
      tab++;
    }
  return (2);
}

char    *my_strcat(char *src1, char *src2)
{
  int   i;
  int   j;
  char  *destnew;

  i = 0;
  j = 0;
  if (!(destnew = xmalloc(my_strlen(src1) + my_strlen(src2),
			  "my_strcat", "my_strcat.c")))
    return (0);
  while (src1[j])
    destnew[i++] = src1[j++];
  j = 0;
  while (src2[j])
    destnew[i++] = src2[j++];
  destnew[i] = 0;
  return destnew;
}

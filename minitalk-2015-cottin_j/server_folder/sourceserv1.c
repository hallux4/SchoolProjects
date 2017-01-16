/*
** sourceserv.c for  in /home/cottin_j/Bureau/minitalk (copie)
** 
** Made by joffrey cottin
** Login   <cottin_j@epitech.net>
** 
** Started on  Sat Nov 19 21:57:39 2011 joffrey cottin
** Last update Sun Nov 20 14:57:55 2011 joffrey cottin
*/

#include "headtalk.h"

int my_getnbr_base(char *str, char *base)
{
  int   res;
  int   signe;
  int   pos;

  signe = 1;
  pos = 0;
  while (str[pos] != '\0' && (str[pos] == '+' || str[pos] == '-'))
    {
      if (str[pos] == '-')
        signe = -signe;
      pos = pos + 1;
    }
  str  = str + pos;

  res = my_converte(str, base);
  return (res * signe);
}

int     my_converte(char *str, char *base)
{
  int   nbr;
  int   base_int;
  int   i;
  int   j;

  nbr = 0;
  i = 0;
  base_int = my_strlen(base);
  while (str[i])
    {
      j = 0;
      while (base[j])
        {
          if (str[i] == base[j])
            nbr = nbr * base_int + j;
          j++;
        }
      i++;
    }
  return nbr;
}

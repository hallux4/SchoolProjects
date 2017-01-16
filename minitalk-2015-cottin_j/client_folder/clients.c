/*
** tp_kill.c for  in /home/cottin_j/Bureau/bureau/minitalk
**
** Made by joffrey cottin
** Login   <cottin_j@epitech.net>
**
** Started on  Fri Nov 18 18:28:33 2011 joffrey cottin
** Last update Wed Mar  7 15:37:34 2012 joffrey cottin
*/
#include        <signal.h>
#include        "headtalk.h"

void    my_read_str(char *str, int len, int pid)
{
  int   i;
  int   j;
  int   tab_bin[8] = {0};
  extern int number;

  j = 0;
  while (j < len)
    {
      my_put_nbr_base(str[j++], "2", tab_bin);
      my_swap_tab(tab_bin);
      i = 0;
      number--;
      while (i < 8)
        if ((tab_bin[i++]) == 1)
          my_kill(pid, SIGUSR1);
        else
          my_kill(pid, SIGUSR2);
      tab_bin_zero(tab_bin);
    }
}

int my_kill(pid_t pid, int sig)
{
  usleep(2500);
  kill(pid, sig);
}

int my_put_nbr_base(int nbr, char *base, int *tab_bin)
{
  int   base_int;

  base_int = (my_getnbr(base));
  my_convert(nbr, base_int, 0, tab_bin);
}

int my_convert(int nb, int base, int i, int *tab_bin)
{
  int rest;

  if (nb)
    {
      rest = nb % base;
      nb = nb / base;
      tab_bin[i] = rest;
      my_convert(nb, base, ++i, tab_bin);
    }
}

void    tab_bin_zero(int *tab_bin)
{
  int   i;

  i = 0;
  while (i < 8)
    tab_bin[i++] = 0;
}

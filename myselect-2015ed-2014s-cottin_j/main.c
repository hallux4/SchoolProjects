/*
** main.c for  in /home/cottin_j/Bureau/bureau/select
** 
** Made by joffrey cottin
** Login   <cottin_j@epitech.net>
** 
** Started on  Tue Nov 22 23:02:10 2011 joffrey cottin
** Last update Sat Nov 26 13:27:59 2011 joffrey cottin
*/

#include        "hselect.h"

void     raw_mode(t_termios *t, t_termios *old, int argc, char **argv)
{
  int nb;

  t->c_lflag &= ~ECHO;
  t->c_lflag &= ~ICANON;
  if (tcsetattr(0, 0, t) == -1)
    {
      my_putstr("tcsetattr failed\n");
      return;
    }
  nb = argc - 1;
  if (argc > 1)
    {
      argv++;
      my_select(nb, argv);
    }
  else if (argc < 2)
    error_code(MISS_ARG);
  if (tcsetattr(0, 0, old) == -1)
    {
      my_putstr("tcsetattr failed\n");
      return;
    }
  return;
}

int	main(int argc, char **argv)
{
  t_termios     new;
  t_termios     old;

  if (tcgetattr(0, &new) == -1)
    my_putstr("tcgetattr failed\n");
  if (tcgetattr(0, &old) == -1)
    my_putstr("tcgetattr failed\n");
  else
    raw_mode(&new, &old, argc, argv);
  return (0);
}

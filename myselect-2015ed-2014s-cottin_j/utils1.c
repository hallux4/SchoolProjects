/*
** utils1.c for  in /home/cottin_j/Bureau/bureau/select
** 
** Made by joffrey cottin
** Login   <cottin_j@epitech.net>
** 
** Started on  Fri Nov 25 15:07:28 2011 joffrey cottin
** Last update Sun Nov 27 20:18:42 2011 joffrey cottin
*/

#include        "hselect.h"

int	my_putcharint(int c)
{
  write(2, &c, 1);
  return (0);
}

void	raw_mode_on()
{
  t_termios     new;

  if (tcgetattr(0, &new) == -1)
    {
      my_putstr("tcgetattr failed\n");
      return;
    }
  else
    {
      new.c_lflag &= ~ICANON;
      new.c_lflag &= ~ECHO;
    }
  if (tcsetattr(0, 0, &new) == -1)
    {
      my_putstr("tcsetattr failed\n");
      return;
    }
}

void	raw_mode_off()
{
  t_termios     old;

  if (tcgetattr(0, &old) == -1)
    {
      my_putstr("tcgetattr failed\n");
      return;
    }
  if (tcsetattr(0, 0, &old) == -1)
    {
      my_putstr("tcsetattr failed\n");
      return;
  }
}

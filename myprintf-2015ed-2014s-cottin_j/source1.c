/*
** source1.c for  in /home/cottin_j/Bureau/bureau/my_printf
** 
** Made by joffrey cottin
** Login   <cottin_j@epitech.net>
** 
** Started on  Wed Nov 16 01:53:56 2011 joffrey cottin
** Last update Sat Nov 19 15:44:04 2011 joffrey cottin
*/
#include <unistd.h>

void	 my_putchar(char c)
{
  write(1, &c, 1);
}

int	 my_putstr(char *str)
{
  int   i;

  i = 0;
  while (str[i])
    {
      my_putchar(str[i]);
      i++;
    }
}

int	 my_strlen(char *str)
{
  int   i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

int	my_putstrinv(char *str)
{
  int   i;

  i = 0;
  while (str[i])
    {
      if (str[i] < 32 || str[i] > 126)
	{
	  my_putstr("\\");
	  if (str[i] < 8)
	    my_putstr("00");
	  if (str[i] < 64)
	    my_putstr("0");
	  my_putnbr_base(str[i], "01234567");
	}
      else
	my_putchar(str[i]);
      i++;
    }
}

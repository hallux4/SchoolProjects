/*
** print_func.c for  in /home/cottin_j/Bureau/bureau/my_printf
** 
** Made by joffrey cottin
** Login   <cottin_j@epitech.net>
** 
** Started on  Wed Nov 16 01:53:29 2011 joffrey cottin
** Last update Fri Nov 18 15:16:34 2011 joffrey cottin
*/

#include        <stdio.h>
#include        <stdarg.h>
#include	<stdint.h>
#include        "hprintf.h"

void this_is_int(int modif, int val_char)
{
  if (modif == 1 || modif == 2)
    my_put_nbr(val_char);
  if (modif == 3)
    my_putchar(val_char);
}

int this_is_pointer(int modif, char* str)
{
  if (modif == 10)
    my_putstrinv(str);
  if (modif == 8)
    my_putstr(str);
}

void this_is_not_good(void)
{
  my_putchar('%');
}

void this_is_unsign_int(int modif, unsigned value_plus)
{

  if (modif == 4)
    my_putnbr_base(value_plus, "01234567");
  if (modif == 5)
    my_putnbr_base(value_plus, "0123456789abcdef");
  if (modif == 6)
    my_putnbr_base(value_plus, "0123456789ABCDEF");
  if (modif == 11)
    {
      my_putstr("0x");
      my_putnbr_base(value_plus, "0123456789abcdef");
    }
  if (modif == 12)
    my_putnbr_base(value_plus, "01");
  if (modif == 13)
    my_putnbr_base(value_plus, "0123456789");
}

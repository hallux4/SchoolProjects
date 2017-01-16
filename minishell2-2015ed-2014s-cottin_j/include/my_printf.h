/*
** hprintf.h for  in /home/cottin_j/Bureau/bureau/my_printf
** 
** Made by joffrey cottin
** Login   <cottin_j@epitech.net>
** 
** Started on  Wed Nov 16 02:29:17 2011 joffrey cottin
** Last update Fri Nov 18 14:53:21 2011 joffrey cottin
*/

#ifndef	__HPRINTF_H__
#define	__HPRINTF_H__
#include        <unistd.h>
#include        <stdio.h>
#include        <stdarg.h>
#include	<stdint.h>
typedef struct  s_type
{
  char		modif;
  int		type;
} t_type;

typedef struct	s_format
{
  char		formchar;
  int		formint;
} t_format;

char    *space_disapears(char *mod);
char    *my_putchar_s(char *mod);
int     my_putchar(char c);
void    my_putstr(char *str);
int	my_printf(char *mod, ...);
int     pars_mod(char *mod);
void	my_put_nbr(int nbr);
void	my_putnbr_base(unsigned nbr, char *base);
void    dispatch(int type, va_list *pile);
void	my_putstrinv(char *str);
void    this_is_int(int modif, int val_char);
void    this_is_pointer(int modif, char* str);
void    this_is_not_good(void);
void    this_is_unsign_int(int modif, unsigned value_plus);
int	my_strlen(char *str);
int     error_mess(int type, char* func, char *file);

#endif
/* HPRINTF_H */


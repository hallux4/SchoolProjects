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
void    my_putchar(char c);
int     my_putstr(char *str);
int	my_printf(char *mod, ...);
int     pars_mod(char *mod);
int	my_put_nbr(int nbr);
void	my_putnbr_base(unsigned nbr, char *base);
int     dispatch(int type, va_list *pile, char *mode);

#endif
/* HPRINTF_H */


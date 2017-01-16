/*
** hselect.h for  in /home/cottin_j/Bureau/bureau/select
** 
** Made by joffrey cottin
** Login   <cottin_j@epitech.net>
** 
** Started on  Tue Nov 22 23:11:17 2011 joffrey cottin
** Last update Sun Nov 27 20:15:33 2011 joffrey cottin
*/

#ifndef		__HSELECT_H__
#define		__HSELECT_H__
#define		MISS_ARG	0
#define		TERMENTRY	1
#define		DB_TERM		2
#define		CANNOT_LIST	3
#define		NO_MALLOC	4

#include	<term.h>
#include	<curses.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	<stddef.h>

typedef int (*move_to)(int, int);

typedef struct termios t_termios;
typedef struct s_list
{
  char          *name;
  int		coorc;
  int		coorl;
  int		len;
  int		cursorpos;
  int		maxline;
  int		maxcol;
  int		colonne;
  int		lenstrmax;
  int		index;
  int           indexmax;
  int           tagrm;
} t_list;

/*
** main.c
*/
void     raw_mode(t_termios *t, t_termios *old, int argc, char **argv);

/*
** my_select.c
*/
void    my_select(int argc, char **argv);
char    *get_term(char *termentry);
int     test_tgetent(int o, char *termentry);

/*
** errorselect.c
*/
void    error_code(int code);

/*
** utils1.c
*/
int     my_putcharint(int c);
void	raw_mode_on();
void     raw_mode_off();

/*
** utils2.c
*/
void    my_putspace(int nb_space);
void    my_putchar(char c);

/*
** place_arg.c
*/
int     first_jet(int j, int lenstrmax, t_list *base);
void	my_put_void(t_list *base);
void     void_jet(int o, int j, int lenstrmax, t_list *base);
void    fill_name_struct(int argc, char **argv);
void     return_output(t_list *base);

/*
** fillstruct.c
*/
int	fill_struct(t_list *base, int argc, char **argv);
void	cleascreen();
int     arrange_name(t_list *base, int argc);
int	testkey(t_list *base, int argc, char **argv);

/*
** utils1.c
*/
void	cursorpos(t_list *base);
void	my_putstr_pos(t_list *base);
void	downkey(t_list *base);
void	upkey(t_list *base);
void	backdelkey(t_list *base);
void	spacekey(t_list *base);

/*
** source_annexe.c
*/
int	my_strncmp(char *s1, char *s2, int n);
int	my_strlen(char *str);
void	my_putstr(char *str);
void    my_put_nbr(int nb);
void	my_modulo(int nb);

#endif
/*__HSELECT_H__*/

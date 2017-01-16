/*
** get_next_line.h for  in /home/cottin_j/Bureau/bureau/select
** 
** Made by joffrey cottin
** 
** Started on  Tue Nov 22 18:37:30 2011 joffrey cottin
** Last update Tue Nov 29 16:21:31 2011 joffrey cottin
*/

#ifndef         __GNL_H__
# define        __GNL_H__

#define         READ_BUFF 50
#define         PASS_BUFF 200

typedef struct  s_out
{
  char          *dest;
  int           i;
}               t_out;

typedef struct s_in
{
    char        src[READ_BUFF + 1];
    int         j;
    int         nb_char;
}               t_in;

char            *get_next_line(const int fd);

#endif
/*__GNL_H__*/

/*
** minishell.h for  in /home/cottin_j/Bureau/ssh/minishell2-2015ed-2014s-cottin_j/header
** 
** Made by joffrey cottin
** Login   <cottin_j@epitech.net>
** 
** Started on  Sat Dec  3 07:27:02 2011 joffrey cottin
** Last update Sat Dec  3 07:27:46 2011 joffrey cottin
*/

#ifndef __MINISHELL_H__
#define	__MINISHELL_H__

#include        <sys/types.h>
#include        <stdlib.h>
#include        <stdio.h>
#include        <unistd.h>
#include        <sys/wait.h>
#include        <ctype.h>
#include        <string.h>
#include        <dirent.h>
#include        <signal.h>
#define         SIZEM           512
#define         SIZE            2048
#define         DIRPATH         300
#define         USER            "USERNAME="
#define         LUSER           my_strlen(USER)
#define         PATH            "PATH="
#define         LPATH           my_strlen(PATH)
/*
**  main.c
*/
int     collect_info(char **environ);

/*
**  core1.c
*/
int     read_line(char *buffer, char **elems, char **environ, char **paths);
void    catch_sigint();
/*
**  core2.c
*/
int     prepare_command(char **paths, char **elems, char **environ);
int     built_in(char ** environ, char **elems);
int     daddys_son(char **paths, char **elems, char **environ);

/*
**  error_message.c
*/
int     error_mess(int, char*, char *);

/*
**  pars_path.c
*/
char    **pars_path(char **);
char    **cut_to_pieces2(char *str, char **elems);

/*
**  pars_args.c
*/
int     pars_args2(char *, char **);
char    *epur_str(char *str);

/*
**  my_env.c
*/
int     built_in(char ** environ, char **elems);
int     search_line(char *path, char **environ);
int     my_cd(char **elems, char **environ);
/*
**  utilities1.c
*/
int     my_strncmp(char *, char *, int);
char    *my_strcpy(char *, char *);
char    *my_strcat(char *, char *);
int     print_tab(char **);
void    *xmalloc(int, char *, char *);

/*
**  utilities2.c
*/
void    fill_null(char **tab);
void    fill_zero(char *str);

#endif
/* MINISHELL_H */

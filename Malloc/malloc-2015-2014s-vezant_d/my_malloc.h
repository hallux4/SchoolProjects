/*
** my_malloc.h for  in /home/cottin_j/Desktop/Malloc/damz
**
** Made by joffrey cottin
** Login   <cottin_j@epitech.net>
**
** Started on  Wed Feb  1 20:38:25 2012 joffrey cottin
** Last update Fri Feb  3 23:37:32 2012 joffrey cottin
*/

#ifndef		__MY_MALLOC_H__
#define		__MY_MALLOC_H__

#include	<unistd.h>
#include	<string.h>
#include	<stddef.h>
#include	<stdio.h>

#define ROUGE	"\033[31m"
#define BLANC	"\033[37m"

typedef struct  meta_s
{
  struct meta_s*	next;
  struct meta_s*	prev;
  size_t		size;
  size_t		freenext;
} meta_t;

void            init_page(meta_t* data, size_t size,
			  meta_t* prev, int nb_pages);
void		show_alloc_mem();
meta_t*         go_all_over_list(meta_t** tmp, size_t to_alloc, meta_t* ret);
void            init_meta(meta_t* data, size_t size,
                          meta_t* next, meta_t* prev);
void*           malloc(size_t size);
#endif
/* MY_MALLOC_H */


/*
** my_malloc.c for  in /home/cottin_j/Desktop/Malloc/damz
**
** Made by joffrey cottin
** Login   <cottin_j@epitech.net>
**
** Started on  Wed Feb  1 20:37:44 2012 joffrey cottin
** Last update Sat Feb  4 22:33:57 2012 joffrey cottin
*/

#include        "my_malloc.h"

meta_t*         g_head;

size_t          align(size_t size)
{
  int           n;

  if ((n = size % 8) > 0)
    return (size + n);
  return size;
}

void            init_meta(meta_t* data, size_t size,
                          meta_t* next, meta_t* prev)
{
  data->size = size;
  data->next = next;
  data->prev = prev;
  data->freenext = data->prev->freenext;
  data->freenext -= size;
  data->prev->freenext = 0;
}

void*           alloc_next(size_t to_alloc)
{
  meta_t*       tmp;
  meta_t*       ret;
  int           nb_pages;

  tmp = g_head;
  ret = NULL;
  nb_pages = ((int)to_alloc / getpagesize()) + 1;
  if ((ret = go_all_over_list(&tmp, to_alloc, ret))!= NULL)
     return ret;
  if (tmp->prev && (((int)tmp->prev->freenext - (int)to_alloc) < 0))
    {
      if ((ret = (meta_t*)sbrk(nb_pages * getpagesize())) == (void*)-1)
	return NULL;
      init_page(ret, to_alloc, tmp, nb_pages);
      tmp->next = ret;
    }
  else
    {
      ret = (meta_t*)((char*)tmp + tmp->size);
      init_meta(ret, to_alloc, 0, tmp);
      tmp->next = ret;
    }
  return ret;
}

void* malloc(size_t size)
{
  size_t to_alloc;

  to_alloc = align(size + sizeof (meta_t));
  if (!g_head)
    {
      if ((g_head = sbrk(getpagesize())) == (void*)-1)
        return NULL;
      init_page(g_head, to_alloc, NULL, 0);
      return (void*) ((char*) g_head + sizeof (meta_t));
    }
  else
    return (void*) ((char*) alloc_next(to_alloc) + sizeof (meta_t));
}

void init_page(meta_t* data, size_t size,
               meta_t* prev, int nb_pages)
{
  data->size = size;
  data->next = NULL;
  data->prev = prev;
  if (nb_pages)
    data->freenext = (size_t)(nb_pages * getpagesize());
  else
    data->freenext = (size_t)getpagesize();
  data->freenext -= size;
}

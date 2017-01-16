/*
 ** malloc_aux.c for  in /home/cottin_j/Desktop/Malloc/malloc-2015-2014s-vezant_d
 **
 ** Made by joffrey cottin
 ** Login   <cottin_j@epitech.net>
 **
 ** Started on  Fri Feb  3 22:09:00 2012 joffrey cottin
 ** Last update Sat Feb  4 22:49:32 2012 joffrey cottin
 */

#include        "my_malloc.h"

void free(void* ptr)
{
    meta_t* tmp;

    if (ptr)
    {
        tmp = (meta_t*) ((char*) ptr - sizeof (meta_t));
        if (tmp->prev)
        {
            tmp->prev->freenext += (tmp->freenext + tmp->size);
            tmp->prev->next = tmp->next;
            if (tmp->next)
                tmp->next->prev = tmp->prev;
            else
            {
                sbrk(-((int) (tmp->prev->freenext / (size_t) getpagesize()) * getpagesize()));
            }
        }
    }
}

void show_alloc_mem()
{
    meta_t* tmp;
    extern meta_t* g_head;

    tmp = g_head;
    printf("break : %p\n", sbrk(0));
    while (tmp)
    {
        printf("%p - %p : ", ((char*) tmp + sizeof (tmp) - sizeof (char*)),
               ((char*) tmp + tmp->size));
        printf("\033[31m %u octets\033[37m", (unsigned int) tmp->size);
        printf(" - freenext = %u\n", (unsigned int) tmp->freenext);
        tmp = tmp->next;
    }
}

meta_t* go_all_over_list(meta_t** tmp, size_t to_alloc, meta_t *ret)
{
    while ((*tmp)->next)
    {
        if ((*tmp)->freenext >= to_alloc)
        {
            ret = (meta_t*) ((char*) (*tmp) + (*tmp)->size);
            init_meta(ret, to_alloc, (*tmp)->next, (*tmp));
            (*tmp)->next = ret;
            return ret;
        }
        (*tmp) = (*tmp)->next;
    }
    return ret;
}

void* realloc(void *ptr, size_t size)
{
    void * ret;
    meta_t *tmp;
    
    tmp = (meta_t*)((char*) ptr - sizeof(meta_t));
    if (ptr != NULL && size > 0)
    {
        if (NULL == (ret = malloc(size)))
            return ptr;
        if (size <= tmp->size)
                memcpy(ret, ptr, size);
        else
                memcpy(ret, ptr, tmp->size - sizeof(meta_t));
        free(ptr);
        return ret;
    }
    return ptr;
}
 
void *calloc(size_t nmemb, size_t size)
{
    if (nmemb > 0 && size > 0)
        return malloc(nmemb * size);
    return NULL;
}
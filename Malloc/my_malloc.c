/*
** fichier.c for  in /home/cottin_j/Desktop/Malloc
**
** Made by joffrey cottin
** Login   <cottin_j@epitech.net>
**
** Started on  Sun Jan 29 15:55:37 2012 joffrey cottin
** Last update Tue Jan 31 15:12:01 2012 joffrey cottin
*/

#include <unistd.h>
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int my_strlen(char *str)
{
  int i = 0;
  while (str[i++]);
  return --i;
}

void my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}

void *malloc(size_t size)
{
  void *lib_handle;
  void *(*fn)(size_t);
  char *error;
  void *ptr;

  my_putstr("je malloc de size et je renvois un pointeur !!");
  lib_handle = dlopen("/lib64/libc.so.6", RTLD_NOW);
  if (!lib_handle)
    {
      fprintf(stderr, "%s\n", dlerror());
      exit(1);
    }
  fn = dlsym(lib_handle, "malloc");
  if ((error = dlerror()) != NULL)
    {
      fprintf(stderr, "%s\n", error);
      exit(1);
    }
  ptr = (*fn)(size);
  return (ptr);
}

void free(void *ptr)
{
  void *lib_handle;
  void (*fn)(void *);
  char *error;

  my_putstr("je free ptr !!");
  lib_handle = dlopen("/lib64/libc.so.6", RTLD_LAZY);
  if (!lib_handle)
    {
      fprintf(stderr, "%s\n", dlerror());
      exit(1);
    }
  fn = dlsym(lib_handle, "free");
  if ((error = dlerror()) != NULL)
    {
      fprintf(stderr, "%s\n", error);
      exit(1);
    }
  (*fn)(ptr);
}

void *realloc(void *ptr, size_t size)
{
  void *lib_handle;
  void (*fn)(void *, size_t);
  char *error;

  my_putstr("je realloc ma zone, prends Big Mama !!");
  lib_handle = dlopen("/lib64/libc.so.6", RTLD_LAZY);
  if (!lib_handle)
    {
      fprintf(stderr, "%s\n", dlerror());
      exit(1);
    }
  fn = dlsym(lib_handle, "realloc");
  if ((error = dlerror()) != NULL)
    {
      fprintf(stderr, "%s\n", error);
      exit(1);
    }
  (*fn)(ptr, size);
  return (ptr);
}

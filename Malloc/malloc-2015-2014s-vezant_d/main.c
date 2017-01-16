/*
** main.c for  in /home/cottin_j/Desktop/Malloc/malloc-2015-2014s-vezant_d
**
** Made by joffrey cottin
** Login   <cottin_j@epitech.net>
**
** Started on  Sat Feb  4 23:03:05 2012 joffrey cottin
** Last update Sat Feb  4 23:12:03 2012 joffrey cottin
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>


int main(int argc, char *argv[])
{
  char *toto;
  char *s;
  int fd;
  void *lib_handle;
  void *(*fn)();
  char *error;

  lib_handle = dlopen("libmy_malloc.so", RTLD_LAZY);
  if (!lib_handle)
    {
      fprintf(stderr, "%s\n", dlerror());
      exit(1);
    }
  fn = dlsym(lib_handle, "show_alloc_mem");
  if ((error = dlerror()) != NULL)
    {
      fprintf(stderr, "%s\n", error);
      exit(1);
    }
  toto = malloc(178);
  /* free(toto); */
  toto = malloc(288);
  /* free(toto); */
  toto = malloc(328);
  /* free(toto); */
  toto = malloc(458);
  /* free(toto); */
  (*fn)();
  return 0;
}

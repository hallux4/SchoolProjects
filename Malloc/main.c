#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

/* int main(int argc, char *argv[]) */
/* { */
/*   void *lib_handle; */
/*   void (*fn)(char *); */
/*   char *error; */

/*   lib_handle = dlopen("libfichier.so", RTLD_LAZY); */
/*   if (!lib_handle) */
/*     { */
/*       fprintf(stderr, "%s\n", dlerror()); */
/*       exit(1); */
/*     } */
/*   fn = dlsym(lib_handle, "my_putstr"); */
/*   if ((error = dlerror()) != NULL) */
/*     { */
/*       fprintf(stderr, "%s\n", error); */
/*       exit(1); */
/*     } */
/*   if (--argc > 0) */
/*     { */
/*       argv++; */
/*       (*fn)(*argv); */
/*       (*fn)("\n"); */
/*       dlclose(lib_handle); */
/*     } */
/*   return 0; */
/* } */

int main(int argc, char *argv[])
{
  void *lib_handle;
  void (*fn)(char *);
  void (*fn2)(const char *);
  char *toto="tototo";
  int x = 46;
  char *error;
  char *titi;

  titi = malloc(128);

  lib_handle = dlopen("libfichier.so", RTLD_LAZY);
  if (!lib_handle)
    {
      fprintf(stderr, "%s\n", dlerror());
      exit(1);
    }
  fn = dlsym(lib_handle, "my_putstr");
  if ((error = dlerror()) != NULL)
    {
      fprintf(stderr, "%s\n", error);
      exit(1);
    }
  (fn*)("salut");

  //printf("setrlimit = %d\n", getrlimit;
  printf("\n");
  printf("   l'adresse de la fonction main est : %p\n", main);
  printf("   l'adresse de la foction libc printf est : %p\n", printf);
  printf("   l'adresse de la chaine constante toto est : %p\n\n", toto);

  printf("   l'adresse du break est  = %p\n", sbrk(0));
  printf("   l'adresse de la chaine malloc titi est : %p\n\n", titi);

  printf("   l'adresse de la variable locale x : %p\n", &x);
  printf("   l'adresse de la foction lib my_putstr est : %p\n\n", fn);
  dlclose(lib_handle);

  free(titi);

  //  printf("   liberation memoire de la zone titi : %p\n\n");
  //printf("   l'adresse du pointeur titi est : %p\n\n", titi);

  void* tmp;
  printf("   ===========test des retour sur SBRK et BRK=========\n\n");
  printf("   la taille d'une page est de : %u Octet\n", getpagesize());
  printf("   l'adresse du pointeur sbrk(0) est : %p\n", sbrk(0));
  printf("   l'adresse du pointeur sbrk(128)  est : %p\n", sbrk(-128));
  printf("   l'adresse du pointeur sbrk(0) est : %p\n\n", tmp = sbrk(0));
  printf("   l'adresse du pointeur sbrk(0) est : %p\n\n", tmp);
  //printf("   brk(tmp) = %p\n", brk(tmp));
  char* i = (int*)tmp;

  int j = 1;
  printf("   l'adresse du pointeur i est : %p\n", i);
  while (j) {
    printf("   l'adresse du pointeur sbrk(0) est : %p\n", sbrk(0));
    printf("   l'adresse du pointeur i est : %p\n", i);
    i+=1;
    printf("   les 2 premiers char sont : %c %c\n", i[0], i[1]);
  }

  return 0;
}

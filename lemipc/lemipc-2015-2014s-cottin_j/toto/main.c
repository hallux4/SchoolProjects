#include "lemipc.h"

int             main(int argc, char **argv)
{
  int           verif = argc;

  if (argc == 2)
    run(atoi(argv[1]), FALSE);
  else if (argc == 3)
    {
      if (strcmp(argv[2], "-m") == 0)
        run(atoi(argv[1]), TRUE);
      else
        verif = 0;
    }
  if (verif != 2 && verif != 3)
    exit_error("Usage : ./lemipc [no team] [options]\n"
               "Options:\n"
               "-m : Show map\n");
  return (EXIT_SUCCESS);
}
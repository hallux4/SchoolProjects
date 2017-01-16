#include "lemipc.h"

int             main()
{
  SDL_Surface   *ecran, *carreblanc = SDL_LoadBMP("carreblanc.bmp");
  SDL_Event     event;
  int           *map;
  t_teams       *teams;

  teams = init_teams(teams);
  map = get_map();
  ecran = init_sdl((MAP_LEN * 30) + 60, (MAP_LEN * 30) + 60);
  if (ecran == NULL)
    exit_error("Error : Cannot load sdl\n");
  while (1)
    {
      while (SDL_PollEvent(&event))
        if (event.type == SDL_QUIT)
          sdl_quit(map, ecran, carreblanc, teams);
      aff_map_sdl(map, carreblanc, ecran, teams);
      usleep(1000);
      if (get_nb_players(map) == 0)
        {
          printf("Partie terminee !");
          sdl_quit(map, ecran, carreblanc, teams);
          return (EXIT_SUCCESS);
        }
    }
  return (EXIT_SUCCESS);
}

t_teams         remp_struct(int no, int R, int G, int B)
{
  t_teams       tmp;

  tmp.no = no;
  tmp.R = R;
  tmp.G = G;
  tmp.B = B;
  return (tmp);
}

t_teams         *init_teams(t_teams *t)
{
  t = xmalloc(sizeof(t_teams) * MAX_TEAM);
  t[0] = remp_struct(1, 255, 0, 0);
  t[1] = remp_struct(2, 0, 0, 255);
  t[2] = remp_struct(3, 0, 255, 0);
  t[3] = remp_struct(4, 255, 102, 0);
  t[4] = remp_struct(5, 204, 51, 204);
  t[5] = remp_struct(6, 255, 255, 0);
  t[6] = remp_struct(7, 51, 255, 255);
  t[7] = remp_struct(MAX_TEAM, 0, 0, 0);
  return (t);
}

void            sdl_quit(int *map, SDL_Surface *ecran,
                         SDL_Surface *carre, t_teams *teams)
{
  int           i;

  free(ecran);
  free(carre);
  free(teams);
  exit(EXIT_SUCCESS);
}
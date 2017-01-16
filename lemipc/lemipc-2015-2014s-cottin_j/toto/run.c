#include "lemipc.h"

void            aff_rules()
{
  printf("Regles :\n"
         "- Si un client est dedie a l'affichage, celui-ci"
         " continuera son exection jusqu'a la fin de la partie, "
         "meme si le joueur est ammene a etre tue.\n"
         "- Losqu'un joueur effectue un deplacement, "
         "celui-ci devra attendre TIME_TO_WAIT (lemipc.h) avant de pouvoir"
         " effectuer un autre deplacement.\n"
         "- Lorsq'un joueur est encercle par 2 joueurs d'une "
         "autre equipe, celui-ci mourra au debut de son prochain tour.\n"
         "- La parie demmare quant au moins 4 joueurs et 2 equipes "
         "differentes sont connectes a la partie.\n");
}

#include "libc_my.h"

void            exit_success(char *str)
{
  put_str(str);
  exit(EXIT_SUCCESS);
}

void            aff_map(int *map)
{
  int           i;
  int           line_len;

  line_len = 0;
  for (i = 0; i != MAP_SIZE; i++)
    {
      printf("%i ", map[i]);
      line_len++;
      if (line_len >= MAP_LEN)
        {
          printf("\n");
          line_len = 0;
        }
    }
  printf("\n\n");
}

int             *get_map()
{
  key_t         key;
  int           shm_id;
  void          *addr;

  key = get_key(getenv("HOME"), MAP_KEY);
  shm_id = shmget(key, MAP_SIZE, SHM_R | SHM_W);
  printf("Shm : %i\n", shm_id);
  if (shm_id == -1)
    return (create_map(key));
  addr = shmat(shm_id, NULL, SHM_R | SHM_W);
  return ((int *)addr);
}

void            run(int no_team, t_bool aff)
{
  int           *map;
  int           pos;
  int           semid = get_semaphore();

  if (aff == TRUE)
    aff_rules();
  srand(time(NULL));
  map = get_map();
  pos = place_player(map, semid);
  map[pos] = no_team;
  if (no_team == 0)
    {
      delete_map();
      exit_success("Map delete\n");
    }
  while (verif_go(map, no_team) != TRUE)
    {
      if (aff == TRUE)
        printf("En attente de %i autres joueurs et de"
               " 2 equipes differentes\n", 4 - get_nb_players(map));
      sleep(2);
    }
  printf("Debut de la partie dans 5 secondes ...\n");
  sleep(5);
  main_loop(no_team, aff, pos, map, semid);
}

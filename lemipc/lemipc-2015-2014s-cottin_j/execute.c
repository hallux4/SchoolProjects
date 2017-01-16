/*
** execute.c for  in /home/cottin_j/lemipc-2015-2014s-cottin_j
** 
** Made by joffrey cottin
** Login   <cottin_j@epitech.net>
** 
** Started on  Sun Mar 25 17:04:31 2012 joffrey cottin
** Last update Sun Mar 25 17:49:41 2012 hallux
*/

#include	"lemipc.h"

void		rules()
{
  printf("Regles :\n"
         "- Lorsq'un joueur est encercle par 2 joueurs d'une "
         "autre equipe, celui-ci mourra au debut de son prochain tour.\n"
         "- La parie demmare quant au moins 4 joueurs et 2 equipes "
         "differentes sont connectes a la partie.\n");
}

void		map_dsp(int *battleground)
{
  int		i;
  int		line_len;

  line_len = 0;
  i = 0;
  while (i != map_size)
    {
      if (battleground[i] == 0)
           printf("\033[31m%d\033[37m ", battleground[i]);
      else
           printf("%d ", battleground[i]);   
      line_len++;
      if (line_len >= map_len)
        {
	  printf("\n");
          line_len = 0;
        }
      i++;
    }
  printf("\n\n");
}

int		*get_map()
{
  key_t		key;
  int		shm_id;
  void		*addr;

  key = the_key_is(getenv("PWD"), MAP_KEY);
  shm_id = shmget(key, map_size, SHM_R | SHM_W);
  printf("Shm : %i\n", shm_id);
  if (shm_id == -1)
    return (create_map(key));
  addr = shmat(shm_id, NULL, SHM_R | SHM_W);
  return ((int *)addr);
}

void		execute(int no_team, bool aff)
{
  int		*battleground;
  int		pos;
  int		semid = get_semz();

  if (aff == true)
    rules();
  srand(time(NULL));
  battleground = get_map();
  pos = place_player(battleground, semid);
  battleground[pos] = no_team;
  if (no_team == 0)
    {
      delete_map();
      error_func("Map delete\n", EXIT_SUCCESS);
    }
  while (go(battleground, no_team) != true)
    {
      if (aff == true)
        printf("En attente de %i autres joueurs et de"
               " 2 equipes differentes\n", 4 - get_playerz(battleground));
      sleep(2);
    }
  printf("Debut de la partie dans 5 secondes ...\n");
  sleep(5);
  main_loop(no_team, aff, pos, battleground, semid);
}


#include "lemipc.h"

void            delete_map()
{
  key_t         key;
  int           shm_id;

  key = get_key(getenv("HOME"), MAP_KEY);
  shm_id = shmget(key, MAP_SIZE, SHM_R | SHM_W);
  if (shm_id == -1)
    printf("Error : Map cannot be deleted because she's already deleted\n");
  else
    {
      shmctl(shm_id, IPC_RMID, NULL);
      printf("Map deleted\n");
    }
}

int             *create_map(int key)
{
  int           *map;
  void          *addr;
  int           shm_id;
  int           i;

  printf("Map doesn't exit : Creation\n");
  shm_id = shmget(key, MAP_SIZE, IPC_CREAT | SHM_R | SHM_W);
  addr = shmat(shm_id, NULL, SHM_R | SHM_W);
  map = (int *)addr;
  for (i = 0; i != MAP_SIZE; i++)
    map[i] = 0;
  return (map);
}

int             get_nb_players(int *map)
{
  int           i;
  int           nb_players = 0;

  for (i = 0; i != MAP_SIZE; i++)
    if (map[i] != 0)
      nb_players++;
  return (nb_players);
}

int             place_player(int *map, int semid)
{
  int           ret;

  sem_lock(semid);
  if (map[0] == 0)
    return (sem_unlockreturn(semid, 0));
  if (map[MAP_SIZE -1] == 0)
    return (sem_unlockreturn(semid, MAP_SIZE - 1));
  if (map[MAP_LEN - 1] == 0)
    return (sem_unlockreturn(semid, MAP_LEN - 1));
  if (map[MAP_SIZE - MAP_LEN] == 0)
    return (sem_unlockreturn(semid, MAP_SIZE - MAP_LEN));
  if (get_nb_players(map) == MAP_SIZE)
    {
      sem_unlock(semid);
      exit_error("Cannot place player : Map is full\n");
    }
  ret = 0;
  while (map[ret] != 0)
    ret = rand() % MAP_SIZE;
  return (sem_unlockreturn(semid, ret));
}
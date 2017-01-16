
#include "lemipc.h"

t_bool          move_up(int *map, int pos, int no_team)
{
  if (pos <= MAP_LEN - 1)
    return (FALSE);
  if (map[pos - MAP_LEN] != 0)
    return (FALSE);
  map[pos] = 0;
  map[pos - MAP_LEN] = no_team;
  return (TRUE);
}

t_bool          move_down(int *map, int pos, int no_team)
{
  if (pos >= MAP_SIZE - MAP_LEN)
    return (FALSE);
  if (map[pos + MAP_LEN] != 0)
    return (FALSE);
  map[pos] = 0;
  map[pos + MAP_LEN] = no_team;
  return (TRUE);
}

t_bool          move_left(int *map, int pos, int no_team)
{
  if (pos % MAP_LEN == 0)
    return (FALSE);
  if (map[pos - 1] != 0)
    return (FALSE);
  map[pos] = 0;
  map[pos - 1] = no_team;
  return (TRUE);
}

t_bool          move_right(int *map, int pos, int no_team)
{
  if (pos % MAP_LEN == 9)
    return (FALSE);
  if (map[pos + 1] != 0)
    return (FALSE);
  map[pos] = 0;
  map[pos + 1] = no_team;
  return (TRUE);
}

int             move_to_ennemy(int *map, int pos, int no_team, int semid)
{
  int           pos_en;
  int           len;
  int           nb;

  sem_lock(semid);
  pos_en = found_ennemy(no_team, pos, map);
  len = calc_len(pos, pos_en);
  if (pos_en == -1)
    {
      printf("YOU WIN (team no %i)\n", no_team);
      if (get_nb_players(map) == 1)
        {
          sem_unlock(semid);
          delete_map();
          sem_delete(semid);
        }
      map[pos] = 0;
      exit(EXIT_SUCCESS);
    }
  if (len <= 1)
    return (sem_unlockreturn(semid, pos));
  nb = rand() % 2;
  if (nb == 0)
    return (vert_move(pos, pos_en, map, no_team, semid));
  return (horiz_move(pos, pos_en, map, no_team, semid));
}
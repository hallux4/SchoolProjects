#include "lemipc.h"

void            exit_success(char *str);

t_bool          is_dead(int no_team, int pos, int *map, int semid)
{
  int           ennemy = 0;

  sem_lock(semid);
  if (pos > MAP_LEN - 1)
    if (map[pos - 10] != 0 && map[pos - 10] != no_team)
      ennemy++;
  if (pos < MAP_SIZE - MAP_LEN)
    if (map[pos + 10] != 0 && map[pos + 10] != no_team)
      ennemy++;
  if (pos % MAP_LEN != 0)
    if (map[pos - 1] != 0 && map[pos - 1] != no_team)
      ennemy++;
  if (pos % MAP_LEN != 9)
    if (map[pos + 1] != 0 && map[pos + 1] != no_team)
      ennemy++;
  if (ennemy >= 2)
    return (sem_unlockreturn(semid, TRUE));
  return (sem_unlockreturn(semid, FALSE));
}

int             found_ennemy(int no_team, int pos, int *map)
{
  int           i;

  (void)pos;
  for (i = 0; map[i] == no_team || map[i] == 0; i++)
    if (i >= MAP_SIZE)
      return (-1);
  return (i);
}

int             calc_len(int pos1, int pos2)
{
  int           len;

  if (pos1 > pos2)
    {
      len = pos2;
      pos2 = pos1;
      pos1 = len;
    }
  len = 0;
  while (pos2 - pos1 > 9)
    {
      len++;
      pos1 += 10;
    }
  while (pos2 - pos1 > 0)
    {
      len++;
      pos1++;
    }
  return (len);
}

void            main_loop(int no_team, t_bool aff, int pos,
                          int *map, int semid)
{
  while (1)
    {
      if (aff == TRUE)
        aff_map(map);
      if (is_dead(no_team, pos, map, semid) == TRUE)
        {
          sem_lock(semid);
          map[pos] = 0;
          sem_unlock(semid);
          if (aff == FALSE)
            exit_success("Vous etes mort\n");
          continue_aff(map);
        }
      pos = move_to_ennemy(map, pos, no_team, semid);
      if (is_dead(no_team, pos, map, semid) == TRUE)
        {
          sem_lock(semid);
          map[pos] = 0;
          sem_unlock(semid);
          if (aff == FALSE)
            exit_success("Vous etes mort\n");
          continue_aff(map);
        }
      usleep(TIME_TO_WAIT);
    }
}

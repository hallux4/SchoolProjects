#include "lemipc.h"

int             vert_move(int pos, int pos_en, int *map,
                          int no_team, int semid)
{
  t_bool        ret;

  if (pos / MAP_LEN < pos_en / MAP_LEN)
    {
      ret = move_down(map, pos, no_team);
      if (ret == TRUE)
        {
          sem_unlock(semid);
          return (pos + MAP_LEN);
        }
    }
  else if (pos / MAP_LEN > pos_en / MAP_LEN)
    {
      ret = move_up(map, pos, no_team);
      if (ret == TRUE)
        {
          sem_unlock(semid);
          return (pos - MAP_LEN);
        }
    }
  sem_unlock(semid);
  return (random_move(pos, map, no_team));
}

int             horiz_move(int pos, int pos_en, int *map,
                           int no_team, int semid)
{
  t_bool        ret;

  if (pos % 10 < pos_en % 10)
    {
      ret = move_right(map, pos, no_team);
      if (ret == TRUE)
        {
          sem_unlock(semid);
          return (pos + 1);
        }
    }
  else if (pos % 10 > pos_en % 10)
    {
      ret = move_left(map, pos, no_team);
      if (ret == TRUE)
        {
          sem_unlock(semid);
          return (pos - 1);
        }
    }
  sem_unlock(semid);
  return (random_move(pos, map, no_team));
}

int             random_move(int pos, int *map, int no_team)
{
  int           nb;
  t_bool        ret;

  while (1)
    {
      nb = rand() % 4;
      switch(nb)
        {
        case 0: ret = move_up(map, pos, no_team);
          if (ret == TRUE)
            return (pos - 10);
          break;
        case 1: ret = move_down(map, pos, no_team);
          if (ret == TRUE)
            return (pos + 10);
        case 2: ret = move_left(map, pos, no_team);
          if (ret == TRUE)
            return (pos - 1);
        case 3: ret = move_right(map, pos, no_team);
          if (ret == TRUE)
            return (pos + 1);
        default: break;
        }
    }
}
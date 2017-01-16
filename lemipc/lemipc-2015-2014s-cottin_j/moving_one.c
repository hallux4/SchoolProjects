/*
** move.c for  in /home/cottin_j/lemipc-2015-2014s-cottin_j
** 
** Made by joffrey cottin
** Login   <cottin_j@epitech.net>
** 
** Started on  Sun Mar 25 17:08:59 2012 joffrey cottin
** Last update Sun Mar 25 17:10:07 2012 joffrey cottin
*/

#include	"lemipc.h"

bool		up(int *battleground, int pos, int no_squad)
{
  if (pos <= map_len - 1)
    return (false);
  if (battleground[pos - map_len] != 0)
    return (false);
  battleground[pos] = 0;
  battleground[pos - map_len] = no_squad;
  return (true);
}

bool		down(int *battleground, int pos, int no_squad)
{
  if (pos >= map_size - map_len)
    return (false);
  if (battleground[pos + map_len] != 0)
    return (false);
  battleground[pos] = 0;
  battleground[pos + map_len] = no_squad;
  return (true);
}

bool		left(int *battleground, int pos, int no_squad)
{
  if (pos % map_len == 0)
    return (false);
  if (battleground[pos - 1] != 0)
    return (false);
  battleground[pos] = 0;
  battleground[pos - 1] = no_squad;
  return (true);
}

bool          right(int *battleground, int pos, int no_squad)
{
  if (pos % map_len == 9)
    return (false);
  if (battleground[pos + 1] != 0)
    return (false);
  battleground[pos] = 0;
  battleground[pos + 1] = no_squad;
  return (true);
}

int             ennemy(int *battleground, int pos, int no_squad, int semid)
{
  int           pos_en;
  int           len;
  int           nb;

  lock_semz(semid);
  pos_en = battle_dir(no_squad, pos, battleground);
  len = calc_len(pos, pos_en);
  if (pos_en == -1)
    {
      printf("YOU WIN (squad no %i)\n", no_squad);
      if (get_playerz(battleground) == 1)
        {
            unlock_semz(semid);
            delete_map();
            delete_semz(semid);
        }
      battleground[pos] = 0;
      exit(EXIT_SUCCESS);
    }
  if (len <= 1)
    return (ret_unlock_semz(semid, pos));
  nb = rand() % 2;
  if (nb == 0)
    return (vert_move(pos, pos_en, battleground, no_squad, semid));
  return (horiz_move(pos, pos_en, battleground, no_squad, semid));
}

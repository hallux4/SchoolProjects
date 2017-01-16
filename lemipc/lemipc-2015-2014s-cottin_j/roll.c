/*
** loop.c for  in /home/cottin_j/lemipc-2015-2014s-cottin_j
** 
** Made by joffrey cottin
** Login   <cottin_j@epitech.net>
** 
** Started on  Sun Mar 25 17:10:26 2012 joffrey cottin
** Last update Sun Mar 25 17:56:20 2012 hallux
*/

#include	"lemipc.h"

bool		is_dead(int no_squad, int pos, int *battleground, int semid)
{
  int		ennemy;

  ennemy = 0;
  lock_semz(semid);
  if (pos > map_len - 1)
    if (battleground[pos - 10] != 0 && battleground[pos - 10] != no_squad)
      ennemy++;
  if (pos < map_size - map_len)
    if (battleground[pos + 10] != 0 && battleground[pos + 10] != no_squad)
      ennemy++;
  if (pos % map_len != 0)
    if (battleground[pos - 1] != 0 && battleground[pos - 1] != no_squad)
      ennemy++;
  if (pos % map_len != 9)
    if (battleground[pos + 1] != 0 && battleground[pos + 1] != no_squad)
      ennemy++;
  if (ennemy >= 2)
    return (ret_unlock_semz(semid, true));
  return (ret_unlock_semz(semid, false));
}

int		battle_dir(int no_squad, int pos, int *battleground)
{
  int		i;

  (void)pos;
  i = 0;
  while (battleground[i] == no_squad || battleground[i] == 0)
    {
      if (i >= map_size)
        return (-1);
      i++;
    }
  return (i);
}

int		calc_len(int pos1, int pos2)
{
  int		len;

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

void		main_loop(int no_squad,
			  bool aff,
			  int pos,
			  int *battleground,
			  int semid)
{
  while (1)
    {
      if (aff == true)
	map_dsp(battleground);
      if (is_dead(no_squad, pos, battleground, semid) == true)
        {
	  lock_semz(semid);
          battleground[pos] = 0;
          unlock_semz(semid);
          if (aff == false)
            error_func("Vous etes mort\n", EXIT_SUCCESS);
          continue_dsp(battleground);
        }
      pos = ennemy(battleground, pos, no_squad, semid);
      if (is_dead(no_squad, pos, battleground, semid) == true)
        {
	  lock_semz(semid);
          battleground[pos] = 0;
          unlock_semz(semid);
          if (aff == false)
            error_func("Vous etes mort\n", EXIT_SUCCESS);
          continue_dsp(battleground);
        }
      usleep(time_to_wait);
    }
}

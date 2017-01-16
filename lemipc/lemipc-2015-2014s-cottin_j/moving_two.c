/*
** move2.c for  in /home/cottin_j/lemipc-2015-2014s-cottin_j
** 
** Made by joffrey cottin
** Login   <cottin_j@epitech.net>
** 
** Started on  Sun Mar 25 17:07:53 2012 joffrey cottin
** Last update Sun Mar 25 17:58:23 2012 hallux
*/

#include	"lemipc.h"

int		vert_move(int pos,
			  int pos_en,
			  int *battleground,
			  int no_squad,
			  int semid)
{
  bool		ret;

  if (pos / map_len < pos_en / map_len)
    {
      ret = down(battleground, pos, no_squad);
      if (ret == true)
        {
	  unlock_semz(semid);
          return (pos + map_len);
        }
    }
  else if (pos / map_len > pos_en / map_len)
    {
      ret = up(battleground, pos, no_squad);
      if (ret == true)
        {
          unlock_semz(semid);
          return (pos - map_len);
        }
    }
  unlock_semz(semid);
  return (randomed(pos, battleground, no_squad));
}

int		horiz_move(int pos,
			   int pos_en,
			   int *battleground,
			   int no_squad,
			   int semid)
{
  bool		ret;

  if (pos % 10 < pos_en % 10)
    {
      ret = right(battleground, pos, no_squad);
      if (ret == true)
        {
	  unlock_semz(semid);
          return (pos + 1);
        }
    }
  else if (pos % 10 > pos_en % 10)
    {
      ret = left(battleground, pos, no_squad);
      if (ret == true)
        {
          unlock_semz(semid);
          return (pos - 1);
        }
    }
  unlock_semz(semid);
  return (randomed(pos, battleground, no_squad));
}

int		randomed(int pos, int *battleground, int no_squad)
{
  int		nb;
  int		i;
  bool		ret;
  t_move	move[] = {
    {0, up, (UP)}, {1, down, (DOWN)},
    {2, left, (LEFT)}, {3, right, (RIGHT)}
  };

  while (42)
    {
      i = 0;
      nb = rand() % 4;
      while (i < 4)
        {
	  if (nb == move[i].nb_dir)
            {
	      ret = move[i].func_dir(battleground, pos, no_squad);
              if (ret)
                return (pos + move[i].ret_dir);
            }
          i++;
        }
    }
}

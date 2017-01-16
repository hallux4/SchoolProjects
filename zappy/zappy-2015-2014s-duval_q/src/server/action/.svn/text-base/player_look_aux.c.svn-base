/*
** player_look_aux.c for extlibc in /home/epitech/c/Zappy
**
** Made by claude ramseyer
** Login   <ramsey_c@epitech.net>
**
** Started on  Mon Jun 2 10:00:00 2011 claude ramseyer
** Last update Mon Jun 2 10:00:01 2011 claude ramseyer
*/

#include	"game.h"

extern t_game *g_game;

void compute_index(int *x, int *y, int operation)
{
  int operator;

  if (operation < 0)
    operation = -operation, operator = -1;
  else
    operator = 1;
  if (x)
    {
      while (operation--)
	{
	  *x = *x + operator;
	  if (*x < 0)
	    *x = g_game->world.dimensions.x - 1;
	  if (*x >= g_game->world.dimensions.x)
	    *x = 0;
	}
    }
  if (y)
    {
      *y = *y + operator;
      if (*y < 0)
	*y = g_game->world.dimensions.y - 1;
      if (*y >= g_game->world.dimensions.y)
	*y = 0;
    }
}

void _look_east(t_tile *orig_tile, t_list *tile_list, int level)
{
  int idx;
  int idy;
  int orig_x;
  int orig_y;

  idx = 1;
  idy = 0;
  orig_x = orig_tile->coord.x;
  orig_y = orig_tile->coord.y;
  while (idx <= level)
    {
      compute_index(&orig_x, NULL, 1);
      idy = -idx;
      while (idy <= ((1 + idx * 2) / 2))
	{
	  compute_index(NULL, &orig_y, idy);
	  list_add_end(tile_list, world_get_tile(orig_x, orig_y));
	  idy++;
	}
      idx++;
    }
}

void _look_north(t_tile *orig_tile, t_list *tile_list, int level)
{
  int idx;
  int idy;
  int orig_x;
  int orig_y;

  idy = 1;
  orig_x = orig_tile->coord.x;
  orig_y = orig_tile->coord.y;
  logger_debug("[PLAYER] player is in %d:%d",
	       orig_tile->coord.x, orig_tile->coord.y);
  while (idy <= level)
    {
      compute_index(&orig_y, NULL, -1);
      idx = -idy;
      while (idx <= ((1 + idy * 2) / 2))
	{
	  compute_index(NULL, &orig_x, idx);
	  list_add_end(tile_list, world_get_tile(orig_x, orig_y));
	  logger_debug("[PLAYER] tile is %i:%i",
		   world_get_tile(orig_x, orig_y)->coord.x,
		   world_get_tile(orig_x, orig_y)->coord.y);
	  idx++;
	}
      idy++;
    }
}

void _look_south(t_tile *orig_tile, t_list *tile_list, int level)
{
  int idx;
  int idy;
  int orig_x;
  int orig_y;

  idx = 0;
  idy = 1;
  orig_x = orig_tile->coord.x;
  orig_y = orig_tile->coord.y;
  while (idy <= level)
    {
      compute_index(&orig_y, NULL, 1);
      idx = -idy;
      while (idx <= ((1 + idy * 2) / 2))
	{
	  compute_index(NULL, &orig_x, -idx);
	  list_add_end(tile_list, world_get_tile(orig_x, orig_y));
	  idx++;
	}
      idy++;
    }
}

void _look_west(t_tile *orig_tile, t_list *tile_list, int level)
{
  int idx;
  int idy;
  int orig_x;
  int orig_y;

  idx = 1;
  idy = 0;
  orig_x = orig_tile->coord.x;
  orig_y = orig_tile->coord.y;
  while (idx <= level)
    {
      compute_index(&orig_x, NULL, -1);
      idy = -idx;
      while (idy <= (1 + (idx * 2) / 2))
	{
	  compute_index(NULL, &orig_y, -idy);
	  list_add_end(tile_list, world_get_tile(orig_x, orig_y));
	  idy++;
	}
      idx++;
    }
}

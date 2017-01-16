/*
** world.c for extlibc in /home/epitech/c/Zappy
**
** Made by claude ramseyer
** Login   <ramsey_c@epitech.net>
**
** Started on  Mon Jun 2 10:00:00 2011 claude ramseyer
** Last update Mon Jun 2 10:00:01 2011 claude ramseyer
*/

#include "game.h"

extern t_game *g_game;

void world_add_player(t_player *player, int x, int y)
{
  t_tile *tile;

  tile = world_get_tile(x, y);
  player->tile = tile;
  list_add_end(&tile->players, player);
}

void world_remove_player(t_player *player)
{
  if (player->tile)
    {
      list_pop(&player->tile->players, player);
      player->tile = NULL;
    }
}

bool world_move_player(t_player *player)
{
  return world_move_to(player, player->orientation);
}

bool world_move_to(t_player *player, t_orientation direction)
{
  int x;
  int y;

  if (player->tile)
    {
      x = player->ppos_x;
      y = player->ppos_y;
      if (direction == OR_EAST)
	x += 1;
      else if (direction == OR_NORTH)
	y -= 1;
      else if (direction == OR_WEST)
	x -= 1;
      else if (direction == OR_SOUTH)
	y += 1;
      world_remove_player(player);
      world_add_player(player, x, y);
      return true;
    }
  return false;
}

t_tile *world_get_tile(int x, int y)
{
  int w;
  int h;

  w = g_game->world.w_width;
  h = g_game->world.w_height;
  if (x < 0)
    x = (x % w) + w;
  else if (x >= w)
    x = x % w;
  if (y < 0)
    y = (y % h) + h;
  else if (y >= h)
    y = y % h;
  return &g_game->world.tiles[y * w + x];
}

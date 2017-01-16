/*
** game_get.c for extlibc in /home/epitech/c/Zappy
**
** Made by claude ramseyer
** Login   <ramsey_c@epitech.net>
**
** Started on  Mon Jun 2 10:00:00 2011 claude ramseyer
** Last update Mon Jun 2 10:00:01 2011 claude ramseyer
*/

#include <string.h>
#include "game.h"

extern t_game *g_game;

int game_width()
{
  if (g_game)
    return g_game->world.w_width;
  return 0;
}

int game_height()
{
  if (g_game)
    return g_game->world.w_height;
  return 0;
}

t_player *game_get_player(int id)
{
  t_player *player;

  lforeach(&g_game->players, player)
  {
    if (player->id == id)
      return player;
  }
  return NULL;
}

int game_get_item_from_name(char *name)
{
  if (strcmp(name, "nourriture") == 0)
    return IT_FOOD;
  else if (strcmp(name, "linemate") == 0)
    return IT_LINEMATE;
  else if (strcmp(name, "deraumere") == 0)
    return IT_DERAUMERE;
  else if (strcmp(name, "sibur") == 0)
    return IT_SIBUR;
  else if (strcmp(name, "mendiane") == 0)
    return IT_MENDIANE;
  else if (strcmp(name, "phiras") == 0)
    return IT_PHIRAS;
  else if (strcmp(name, "thystame") == 0)
    return IT_THYSTAME;
  return -1;
}

/*
** player.c for zappy in /home/lukior/Zappy/src/player
**
** Made by damien vezant
** Login   <vezant_d@epitech.net>
**
** Started on  Tue May 29 03:16:17 2012 damien vezant
** Last update Tue May 29 07:13:17 2012 damien vezant
*/

#include		"game.h"

int g_player_id = 0;

t_player *player_create()
{
  t_player *player;

  if ((player = calloc(1, sizeof(t_player))) == NULL)
    return (NULL);
  logger_verbose("[GAME] New player %i", g_player_id);
  player->id = g_player_id++;
  player->level = 1;
  player->orientation = rand() % 4;
  player->inv_food = 10;
  return (player);
}

void player_free(t_player *player)
{
  if (player->ghost)
    game_remove_slot(player);
  logger_message("[GAME] Player %i is dead", player->id);
  world_remove_player(player);
  free(player);
}

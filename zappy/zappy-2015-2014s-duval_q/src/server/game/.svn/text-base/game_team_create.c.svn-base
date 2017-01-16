/*
** team.c for zappy in /home/lukior/Zappy/src/game/player
**
** Made by damien vezant
** Login   <vezant_d@epitech.net>
**
** Started on  Tue May 29 06:35:21 2012 damien vezant
** Last update Tue May 29 06:59:53 2012 damien vezant
*/

#include <string.h>
#include "game.h"

t_team *team_create(char *name, int slots)
{
  t_team *team;

  if (game_get_team(name) || slots <= 0 || slots > TEAM_MAX_SLOT)
    return NULL;
  if ((team = calloc(1, sizeof(t_team))) == NULL)
    return (NULL);
  logger_verbose("[GAME] Team '%s' create", name);
  strncpy(team->name, name, TEAM_NAME_SIZE);
  team->players = 0;
  team->free = 0;
  team->slots = slots;
  return (team);
}

t_player *team_create_player(t_team *team)
{
  t_player *player;
  if (team->players < team->slots)
    {
      player = player_create();
      if (player)
	{
	  team->players++;
	  player->team = team;
	  return player;
	}
    }
  return NULL;
}

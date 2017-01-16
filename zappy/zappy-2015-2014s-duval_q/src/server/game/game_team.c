/*
** game_player_remove.c for zappy in /home/lukior/Zappy/src/player
**
** Made by damien vezant
** Login   <vezant_d@epitech.net>
**
** Started on  Tue May 29 04:35:28 2012 damien vezant
** Last update Tue May 29 07:12:47 2012 damien vezant
*/

#include <string.h>
#include "game.h"

extern t_game *g_game;

void game_create_team(char *name)
{
  t_team *team;

  team = team_create(name, g_game->nb_slots);
  if (team)
    game_add_team(team);
}

void game_add_team(t_team *team)
{
  list_add_end(&g_game->teams, team);
}

t_team *game_get_team(char *name)
{
  t_team *team;

  lforeach(&g_game->teams, team)
  {
    if (strcmp(team->name, name) == 0)
      return team;
  }
  return NULL;
}

t_list *game_get_teams()
{
  return &g_game->teams;
}

int game_count_team()
{
  return list_size(&g_game->teams);
}

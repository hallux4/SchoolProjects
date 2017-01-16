/*
** game_slot.c for extlibc in /home/epitech/c/Zappy
**
** Made by claude ramseyer
** Login   <ramsey_c@epitech.net>
**
** Started on  Mon Jun 2 10:00:00 2011 claude ramseyer
** Last update Mon Jun 2 10:00:01 2011 claude ramseyer
*/

#include "game.h"
#include "gui.h"

extern t_game *g_game;

static t_player *_game_get_slot(t_team *team)
{
  t_player *player;

  if (team->free > 0)
    {

      lforeach(&g_game->free, player)
      {
	if (player->team == team)
	  {
	    list_remove(player);
	    team->free--;
	    player->ghost = 0;
	  }
      }
    }
  else if (team->players < team->slots)
    {
      player = team_create_player(team);
      list_add_end(&g_game->players, player);
      world_add_player(player, rand(), rand());
      if (g_game->food)
	game_consume_food(player, 0);
      gui_action_new(player);
    }
}

t_player *game_get_slot(char *name)
{
  t_team *team;
  t_player *player;

  logger_verbose("[GAME] Search team '%s'", name);
  player = NULL;
  team = game_get_team(name);
  if (team)
    {
      logger_verbose("[GAME] Team %s found", name);
      player = _game_get_slot(team);
    }
  return player;
}

void game_add_slot(t_player *player)
{
  logger_verbose("[GAME] Player %i slot", player->id);
  player->ghost = 1;
  player->team->free++;
  list_add_end(&g_game->free, player);
}

void game_remove_slot(t_player *player)
{
  logger_verbose("[GAME] Player %i unslot", player->id);
  player->ghost = 0;
  player->team->free--;
  list_pop(&g_game->free, player);
}

void game_free_player(t_player *player)
{
  if (player->ghost)
    {
      game_remove_slot(player);
      player->ghost = 0;
    }
  list_pop(&g_game->players, player);
  player->team->players--;
  player->team->slots--;
  if (!player->team->slots)
    logger_message("[GAME] Team %s loose!", player->team->name);
  player_free(player);
}

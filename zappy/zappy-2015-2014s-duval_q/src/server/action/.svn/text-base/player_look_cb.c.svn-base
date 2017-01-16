/*
** player_look_cb.c for zappy in /home/lukior/Zappy/src/server/game
**
** Made by damien vezant
** Login   <vezant_d@epitech.net>
**
** Started on  Wed May 30 14:13:02 2012 damien vezant
** Last update Tue Jul  3 22:13:14 2012 quentin duval
*/

#include	<string.h>
#include	"game.h"

#define		BUFF_SIZE	1024

void _look_east(t_tile *orig_tile, t_list *tile_list, int level);
void _look_north(t_tile *orig_tile, t_list *tile_list, int level);
void _look_south(t_tile *orig_tile, t_list *tile_list, int level);
void _look_west(t_tile *orig_tile, t_list *tile_list, int level);

static char *res_string[] = {
  " nourriture",
  " linemate",
  " deraumere",
  " sibur",
  " mendiane",
  " phiras",
  " thystame"
};
static t_client *_player;
static bool is_first;

static void _listing(int *ressource, int item, char *msg)
{
  int idx;

  idx = 0;
  while (idx++ < ressource[item])
    msg = strcat(msg, res_string[item]);
}

static void _tile_lister(t_tile *tile, char *msg)
{
  if (!is_first)
    msg = strcat(msg, ",");
  _listing((int*) &tile->ressources, IT_FOOD, msg);
  _listing((int*) &tile->ressources, IT_LINEMATE, msg);
  _listing((int*) &tile->ressources, IT_DERAUMERE, msg);
  _listing((int*) &tile->ressources, IT_SIBUR, msg);
  _listing((int*) &tile->ressources, IT_MENDIANE, msg);
  _listing((int*) &tile->ressources, IT_PHIRAS, msg);
  _listing((int*) &tile->ressources, IT_THYSTAME, msg);
  is_first = false;
  client_send_nonl(_player, msg);
  bzero(msg, BUFF_SIZE);
}

static void _looking(t_player *player, char *msg)
{
  t_list tile_list;

  logger_debug("[PLAYER] player level = %d", player->level);
  list_init(&tile_list);
  list_add_end(&tile_list, player->tile);
  if (player->orientation == OR_EAST)
    _look_east(player->tile, &tile_list, player->level);
  else if (player->orientation == OR_NORTH)
    _look_north(player->tile, &tile_list, player->level);
  else if (player->orientation == OR_SOUTH)
    _look_south(player->tile, &tile_list, player->level);
  else if (player->orientation == OR_WEST)
    _look_west(player->tile, &tile_list, player->level);
  is_first = true;
  msg = strcat(msg, "{");
  list_foreach_param(tile_list, (feachp) & _tile_lister, msg);
  client_send(_player, "}");
  list_clear(&tile_list);
}

void player_look_end_cb(t_client *client, int error)
{
  char *msg;

  (void) msg;
  if (!error)
    {
      msg = calloc(1, BUFF_SIZE);
      _player = client;
      _looking(client->player, msg);
      free(msg);
    }
  else
    client_send(client, REP_KO);
  client_action_finish(client);
}

void player_look_start_cb(t_client *client, char *command)
{
  (void) command;
  kernel_register_wakeup(DELAY_STANDARD,
			 (kn_wakeup_cb) player_look_end_cb, client);
}

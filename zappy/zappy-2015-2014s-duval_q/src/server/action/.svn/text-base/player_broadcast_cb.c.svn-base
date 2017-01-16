/*
** player_broadcast_cb.c for extlibc in /home/epitech/c/Zappy
**
** Made by claude ramseyer
** Login   <ramsey_c@epitech.net>
**
** Started on  Mon Jun 2 10:00:00 2011 claude ramseyer
** Last update Mon Jun 2 10:00:01 2011 claude ramseyer
*/

#include <string.h>
#include "game.h"
#include "client.h"
#include "gui.h"

extern t_game *g_game;

static void player_broadcast_vector(t_player *p1,
				    t_player *p2,
				    t_vector *vector)
{
  vector->x = p2->ppos_x - p1->ppos_x;
  vector->y = p2->ppos_y - p1->ppos_y;
  if (game_width() - vector->x < vector->x)
    vector->x = game_width() - vector->x;
  if (game_height() - vector->y < vector->y)
    vector->y = game_height() - vector->y;
}

static int player_broadcast_tile(t_player *p1, t_player *p2, t_vector *vector)
{
  (void) p1;
  (void) p2;
  (void) vector;
  logger_error("[GAME] Broadcast not complete implemented");
  return 0;
}

static int player_broadcast_direction(t_player *p1, t_player *p2)
{
  t_vector vector;
  int dir;

  if (p1->ppos_x == p2->ppos_x && p1->ppos_y == p2->ppos_y)
    return 0;
  player_broadcast_vector(p1, p2, &vector);
  if (vector.x == 0)
    dir = vector.y > 0 ? 0 : 4;
  else if (vector.y == 0)
    dir = vector.x > 0 ? 6 : 2;
  else
    dir = player_broadcast_tile(p1, p2, &vector);
  dir = (dir + (p2->orientation * 2)) % 8 + 1;
  return dir;
}

void player_broadcast_end_cb(t_client *client, int error)
{
  t_player *player;
  t_client *pclient;

  if (!error)
    {

      lforeach(&g_game->players, player)
      {
	pclient = client_get_from_player(player);
	if (pclient)
	  {
	    client_send(pclient, "%i %s",
		     player_broadcast_direction(player, client->player),
		     client->param);
	  }
      }
      client_send(client, REP_OK);
      gui_action_broadcast(client->player, client->param);
    }
  else
    client_send(client, REP_KO);
  free(client->param);
  client->param = NULL;
  client_action_finish(client);
}

void player_broadcast_start_cb(t_client *client, char *command)
{
  client->param = strdup(&command[10]);
  kernel_register_wakeup(DELAY_STANDARD,
			 (kn_wakeup_cb) & player_broadcast_end_cb,
			 client);
}

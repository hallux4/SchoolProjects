/*
** player_expulse_cb.c for zappy in /home/lukior/Zappy/src/server/game
**
** Made by damien vezant
** Login   <vezant_d@epitech.net>
**
** Started on  Wed May 30 17:08:35 2012 damien vezant
** Last update Wed May 30 20:44:30 2012 damien vezant
*/

#include "game.h"
#include "client.h"
#include "gui.h"

static void _player_expulse_exec(t_client *client)
{
  t_tile *tile;
  t_client *other;
  t_player *player;

  tile = client->player->tile;
  lforeach(&tile->players, player)
  {
    if (player != client->player)
      {
	world_move_to(player, client->player->orientation);
	other = client_get_from_player(player);
	gui_action_forward(player);
	if (other)
	  {
	    client_send(other, "deplacement: %i",
		     client->player->orientation + 1);
	    kernel_cancel_wakeup(other);
	  }
      }
  }
}

void player_expulse_end_cb(t_client *client, int error)
{

  if (!error)
    {
      gui_action_expulse(client->player);
      client_send(client, REP_OK);
      _player_expulse_exec(client);
    }
  else
    client_send(client, REP_KO);
  client_action_finish(client);
}

void player_expulse_start_cb(t_client *client, char *command)
{
  (void) command;
  kernel_register_wakeup(DELAY_STANDARD,
			 (kn_wakeup_cb) player_expulse_end_cb, client);
}

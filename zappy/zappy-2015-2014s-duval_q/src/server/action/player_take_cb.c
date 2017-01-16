/*
** player_take.c for zappy in /home/lukior/Zappy/src/game
**
** Made by damien vezant
** Login   <vezant_d@epitech.net>
**
** Started on  Tue May 29 07:59:30 2012 damien vezant
** Last update Wed May 30 20:40:28 2012 damien vezant
*/

#include	"game.h"
#include "gui.h"

void player_take_end_cb(t_client *client, int error)
{
  int item;
  int *inventory;

  item = (int) ((long int) client->param);
  inventory = (int *) &client->player->tile->ressources;
  if (!error && item >= 0 && item < 7 && inventory[item] > 0)
    {
      inventory[item]--;
      inventory = (int *) &client->player->inventory;
      inventory[item]++;
      client_send(client, REP_OK);
      gui_action_take(client->player, item);
    }
  else
    client_send(client, REP_KO);
  client_action_finish(client);
}

void player_take_start_cb(t_client *client, char *command)
{
  int item;
  int *inventory;

  item = game_get_item_from_name(&command[6]);
  if (item != -1)
    {
      inventory = (int *) &client->player->tile->ressources;
      if (inventory[item] > 0)
	{
	  client->param = (void *) ((long int) item);
	  kernel_register_wakeup(DELAY_STANDARD,
			   (kn_wakeup_cb) & player_take_end_cb, client);
	  return;
	}
    }
  client_send(client, REP_KO);
  client_action_finish(client);
}

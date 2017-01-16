/*
** client_player.c for extlibc in /home/epitech/c/Zappy
**
** Made by claude ramseyer
** Login   <ramsey_c@epitech.net>
**
** Started on  Mon Jun 2 10:00:00 2011 claude ramseyer
** Last update Mon Jun 2 10:00:01 2011 claude ramseyer
*/

#include <string.h>
#include "client.h"
#include "network.h"
#include "gui.h"

bool client_player_search(t_client *client, char *team)
{
  t_player *player;

  if (strcmp(team, GRAPHIC_TEAM) == 0)
    {
      gui_connect(client);
      return true;
    }
  else
    {
      logger_verbose("[CLIENT] Search player in team '%s'", team);
      player = game_get_slot(team);
      if (player)
	{
	  logger_verbose("[CLIENT] Find player %i for client", player->id);
	  client->player = player;
	  client_send(client, "%i", player->team->slots - player->team->players);
	  client_send(client, "%i %i", game_width(), game_height());
	  client->exec = (t_execute_cb) & client_action_save;
	  return true;
	}
    }
  logger_error("[CLIENT] No free player found");
  return false;
}

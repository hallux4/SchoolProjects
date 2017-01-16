/*
** client_get_set.c for extlibc in /home/epitech/c/Zappy
**
** Made by claude ramseyer
** Login   <ramsey_c@epitech.net>
**
** Started on  Mon Jun 2 10:00:00 2011 claude ramseyer
** Last update Mon Jun 2 10:00:01 2011 claude ramseyer
*/

#include "client.h"

extern t_client_manager *g_client_manager;

t_socket *client_get_socket(t_client *client)
{
  return client->socket;
}

t_player *client_get_player(t_client *client)
{
  return client->player;
}

bool client_set_player(t_client *client, t_player *player)
{
  if (client->player)
    return false;
  client->player = player;
  return true;
}

t_client *client_get_from_player(t_player *player)
{
  t_client *client;

  lforeach(&g_client_manager->clients, client)
  {
    if (client->player == player)
      return client;
  }
  return NULL;
}

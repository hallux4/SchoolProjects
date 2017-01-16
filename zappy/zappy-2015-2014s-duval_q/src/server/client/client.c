/*
** client.c for extlibc in /home/epitech/c/Zappy
**
** Made by claude ramseyer
** Login   <ramsey_c@epitech.net>
**
** Started on  Mon Jun 2 10:00:00 2011 claude ramseyer
** Last update Mon Jun 2 10:00:01 2011 claude ramseyer
*/

#include "client.h"
#include "network.h"
#include "gui.h"

t_client *client_create(t_socket *socket)
{
  t_client *client;

  if (!(client = malloc(sizeof(t_client))))
    return NULL;
  return client_init(client, socket);
}

t_client *client_init(t_client *client, t_socket *socket)
{
  client->socket = socket;
  client->player = NULL;
  client->busy = false;
  client->exec = (t_execute_cb) & client_player_search;
  client->gui = false;
  list_init(&client->actions);
  _client_manager_add(client);
  return client;
}

void client_destroy(t_client *client)
{
  logger_message("[CLIENT] Client %i destroy", CLP_ID(client));
  list_free(&client->actions);
  _client_manager_remove(client);
  if (client->player)
    game_add_slot(client->player);
  if (client->gui)
    gui_remove(client);
  if (client->socket)
    {
      logger_message("[CLIENT] Client %i close socket", CLP_ID(client));
      network_del_socket(client->socket);
      socket_close(client->socket);
    }
  free(client);
}

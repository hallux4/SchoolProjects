/*
** client_manager_retrieve.c for extlibc in /home/epitech/c/Zappy
**
** Made by claude ramseyer
** Login   <ramsey_c@epitech.net>
**
** Started on  Mon Jun 2 10:00:00 2011 claude ramseyer
** Last update Mon Jun 2 10:00:01 2011 claude ramseyer
*/

#include "client.h"

extern t_client_manager *g_client_manager;

static int _clm_cmp_player(t_client *client, t_player *player)
{
  return client->player == player;
}

static int _clm_cmp_socket(t_client *client, t_socket *socket)
{
  return client->socket == socket;
}

t_client *clm_retrieve_from_player(t_player* player)
{
  return list_get_to_param(&g_client_manager->clients,
			   (fpredp) & _clm_cmp_player, player);
}

t_client *clm_retrieve_from_socket(t_socket* socket)
{
  return list_get_to_param(&g_client_manager->clients,
			   (fpredp) & _clm_cmp_socket, socket);
}

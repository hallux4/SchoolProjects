/*
** client_send.c for extlibc in /home/epitech/c/Zappy
**
** Made by claude ramseyer
** Login   <ramsey_c@epitech.net>
**
** Started on  Mon Jun 2 10:00:00 2011 claude ramseyer
** Last update Mon Jun 2 10:00:01 2011 claude ramseyer
*/

#include <stdarg.h>
#include "client.h"

static char buffer[1024 + 1];

int client_send(t_client *client, char *mask, ...)
{
  va_list vl;
  int size;

  va_start(vl, mask);
  size = vsnprintf(buffer, 1024, mask, vl);
  logger_verbose("[CLIENT] Client %i send %i bytes '%s'",
		 CLP_ID(client), size, buffer);
  buffer[size++] = '\n';
  buffer[size] = '\0';
  size = socket_write(client->socket, buffer, size);
  va_end(vl);
  return size;
}

int client_send_nonl(t_client *client, char *mask, ...)
{
  va_list vl;
  int size;

  va_start(vl, mask);
  size = vsnprintf(buffer, 1024, mask, vl);
  logger_verbose("[CLIENT] Client %i send %i bytes '%s'",
		 CLP_ID(client), size, buffer);
  size = socket_write(client->socket, buffer, size);
  va_end(vl);
  return size;
}

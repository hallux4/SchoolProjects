/*
** player_fork.c for zappy in /home/lukior/Zappy/src/game
**
** Made by damien vezant
** Login   <vezant_d@epitech.net>
**
** Started on  Tue May 29 08:21:57 2012 damien vezant
** Last update Tue Jun 26 10:29:21 2012 quentin duval
*/

#include	"game.h"

void player_fork_end_cb(t_client *client, int error)
{
  (void) error;
  client_send(client, REP_KO);
}

void player_fork_start_cb(t_client *client, char *command)
{
  (void) command;
  kernel_register_wakeup(DELAY_FORK,
			 (kn_wakeup_cb) player_fork_end_cb, client);
}

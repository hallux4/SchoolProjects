/*
** clock_get_time.c for zappy in /home/duval_q//Documents/projects/zappy/src/server/clock
**
** Made by quentin duval
** Login   <duval_q@epitech.net>
**
** Started on  Wed May 30 18:47:48 2012 quentin duval
** Last update Tue Jun 26 11:19:58 2012 quentin duval
*/

#include	"clock.h"

extern t_clock *g_clock;

struct timeval *clock_get_time()
{
  clock_set_time_to_current(&g_clock->current);
  return (&(g_clock->current));
}

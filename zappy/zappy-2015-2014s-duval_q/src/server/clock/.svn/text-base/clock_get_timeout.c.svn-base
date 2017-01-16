/*
** clock_turn.c for zappy in /home/duval_q//Documents/projects/zappy/src/server/clock
**
** Made by quentin duval
** Login   <duval_q@epitech.net>
**
** Started on  Tue May 29 10:22:12 2012 quentin duval
** Last update Fri Jun 29 16:19:43 2012 quentin duval
*/

#include	<stdlib.h>
#include	"clock.h"
#include	"time_utils.h"
#include	"logger.h"

t_clock *g_clock;

struct timeval *clock_get_timeout(struct timeval *begin,
				  unsigned int unit_time)
{
  struct timeval end_date;

  if (!begin || !g_clock)
    return (NULL);
  timeval_copy(&end_date, begin);
  clock_move_date(&end_date, unit_time);
  timeval_diff(&g_clock->timeout, &end_date, clock_get_time());
  logger_debug("[CLOCK] With %d units of time, timeout is set to %lu:%lu",
	       unit_time,
	       g_clock->timeout.tv_sec,
	       g_clock->timeout.tv_usec);
  return (&(g_clock->timeout));
}

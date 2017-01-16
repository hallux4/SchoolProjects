/*
** clock_timeval_unit_convert.c for zappy in /home/duval_q//Documents/projects/zappy/src/server/clock
**
** Made by quentin duval
** Login   <duval_q@epitech.net>
**
** Started on  Wed May 30 18:49:40 2012 quentin duval
** Last update Tue Jun 26 11:21:59 2012 quentin duval
*/

#include	"clock.h"
#include	"logger.h"

extern t_clock *g_clock;

void time_unit_to_timeval(struct timeval *time, unsigned int unit)
{
  time->tv_sec = unit / g_clock->frequency;
  unit = unit % g_clock->frequency;
  time->tv_usec = (unit * 1000000) / g_clock->frequency;
}

unsigned int timeval_to_time_unit(struct timeval *time)
{
  unsigned int res;

  res = time->tv_sec * g_clock->frequency;
  res += (time->tv_usec * g_clock->frequency) / 1000000;
  return res;
}

/*
** kernel_wakeup.c for zappy in /home/duval_q//Documents/projects/zappy/src/server/kernel
**
** Made by quentin duval
** Login   <duval_q@epitech.net>
**
** Started on  Thu May 31 16:30:58 2012 quentin duval
** Last update Thu Jun 14 21:01:39 2012 quentin duval
*/

#include "kernel.h"
#include "clock.h"
#include "logger.h"
#include "debug.h"

extern t_kernel *g_kernel;

bool kernel_register_wakeup(unsigned int time,
			    kn_wakeup_cb callback,
			    void* param)
{
  t_kernel_callback *wakeup;

  logger_debug("[KERNEL] Register wakeup '%s' in %i time, %i in standby",
	       debug_get_callback_name(callback), time,
	       list_size(&g_kernel->callbacks));
  if (!(wakeup = malloc(sizeof(t_kernel_callback))))
    return false;
  clock_set_time_to_current(&wakeup->begin);
  wakeup->time = time;
  wakeup->callback = callback;
  wakeup->param = param;
  list_add_to(&g_kernel->callbacks, (fcmp) & kernel_wakeup_insert, wakeup);
  logger_verbose("[DUMP] %i callback in standby",
		 list_size(&g_kernel->callbacks));
  list_foreach(&g_kernel->callbacks, (feach) & kernel_wakeup_dump);
  return true;
}

void kernel_unregister_wakeup(void *param)
{
  t_kernel_callback *data;

  lforeach(&g_kernel->callbacks, data)
  {
    if (data->param == param)
      {
	list_remove(data);
	free(data);
      }
  }
}

void kernel_cancel_wakeup(void *param)
{
  t_kernel_callback *data;

  lforeach(&g_kernel->callbacks, data)
  {
    if (data->param == param)
      {
	(*data->callback)(data->param, 1);
	list_remove(data);
	free(data);
      }
  }
}

int kernel_wakeup_insert(t_kernel_callback *first, t_kernel_callback *second)
{
  struct timeval first_end;
  struct timeval second_end;

  first_end = first->begin;
  clock_move_date(&first_end, first->time);
  second_end = second->begin;
  clock_move_date(&second_end, second->time);
  return clock_compare(&first_end, &second_end) * -1;
}

int kernel_wakeup()
{
  t_kernel_callback *wakeup;
  struct timeval end;
  struct timeval *time;
  int count;

  count = 0;
  wakeup = list_get_begin(&g_kernel->callbacks);
  time = clock_get_time();
  while (wakeup)
    {
      end = wakeup->begin;
      clock_move_date(&end, wakeup->time);
      if (clock_compare(time, &end) >= 0)
	{
	  list_pop_begin(&g_kernel->callbacks);
	  (*wakeup->callback)(wakeup->param, KN_ERROR_OK);
	  free(wakeup);
	  count++;
	}
      else
	return count;
      wakeup = list_get_begin(&g_kernel->callbacks);
    }
  return count;
}

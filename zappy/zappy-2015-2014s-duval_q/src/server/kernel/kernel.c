/*
** kernel.c for zappy in /home/duval_q//Documents/projects/zappy/src/server/kernel
**
** Made by quentin duval
** Login   <duval_q@epitech.net>
**
** Started on  Thu May 31 16:27:37 2012 quentin duval
** Last update Tue Jun 12 16:35:12 2012 quentin duval
*/

#include "kernel.h"
#include "logger.h"
#include "gui.h"
#include "debug.h"

t_kernel *g_kernel = NULL;

void kernel_init()
{
  srand(getpid());
  if (g_kernel != NULL)
    return;
  if ((g_kernel = malloc(sizeof(t_kernel))) == NULL)
    return;
  list_init(&g_kernel->callbacks);
  g_kernel->init = 0;
  g_kernel->run = false;
  kernel_signal();
  logger_message("[KERNEL] Kernel init");
}

#define kopt kernel_get_opt
#define kopti kernel_getopt_int
#define kretf kernel_retrieve_flag_index

bool kernel_init_with_argv(int argc, char **argv)
{
  int index;
  int team;

  kernel_init();
  team = 0;
  if (kernel_client_init(kopti(argc, argv, "-p", 3945)) &&
      kernel_game_init(kopti(argc, argv, "-x", 10),
		       kopti(argc, argv, "-y", 10),
		       kopti(argc, argv, "-c", 10),
		       kretf(argc, argv, "-i") < 0) &&
      kernel_gui_init() && kernel_clock_init(kopti(argc, argv, "-t", 100)))
    {
      logger_verbose("[KERNEL] Search team definition");
      if ((index = kernel_retrieve_flag_index(argc, argv, "-n") + 1))
	{
	  while (index < argc && (!IS_FLAG(argv[index])))
	    {
	      kernel_add_team(argv[index++]);
	      team++;
	    }
	}
      else
        logger_error("[KERNEL] No team has created");
    }
  return team > 0;
}

void kernel_destroy()
{
  logger_message("[KERNEL] Kernel destroy");
  if (!g_kernel)
    return;
  list_free(&g_kernel->callbacks);
  gui_destroy();
  client_manager_destroy();
  game_destroy();
  clock_destroy();
  free(g_kernel);
  g_kernel = NULL;
  debug_destroy();
}

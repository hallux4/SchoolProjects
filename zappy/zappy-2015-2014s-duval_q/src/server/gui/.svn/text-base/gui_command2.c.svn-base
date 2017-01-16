/*
** gui_command2.c for extlibc in /home/epitech/c/Zappy
**
** Made by claude ramseyer
** Login   <ramsey_c@epitech.net>
**
** Started on  Mon Jun 2 10:00:00 2011 claude ramseyer
** Last update Mon Jun 2 10:00:01 2011 claude ramseyer
*/

#include "gui.h"
#include "parser.h"
#include "clock.h"

void gui_command_ppo(t_gui *gui, char *command)
{
  char buffer[GUI_BUFFER_SIZE];
  t_command *parse;
  t_player *player;

  parse = parser_parse(command, "ppo %d");
  if (parse)
    {
      player = game_get_player(parser_get_int(parse, 1));
      parser_command_destroy(parse);
      if (player)
	{
	  snprintf(buffer, GUI_BUFFER_SIZE, "ppo %i %i %i",
		   player->id, player->ppos_x, player->ppos_y);
	  gui_send(gui, buffer);
	  return;
	}
    }
  gui_command_sbp(gui, NULL);
}

void gui_command_plv(t_gui *gui, char *command)
{
  char buffer[GUI_BUFFER_SIZE];
  t_command *parse;
  t_player *player;

  parse = parser_parse(command, "plv %d");
  if (parse)
    {
      player = game_get_player(parser_get_int(parse, 1));
      parser_command_destroy(parse);
      if (player)
	{
	  snprintf(buffer, GUI_BUFFER_SIZE, "plv %i %i",
		   player->id, player->level);
	  gui_send(gui, buffer);
	  return;
	}
    }
  gui_command_sbp(gui, NULL);
}

void gui_command_pin(t_gui *gui, char *command)
{
  char buffer[GUI_BUFFER_SIZE];
  t_command *parse;
  t_player *player;

  parse = parser_parse(command, "pin %d");
  if (parse)
    {
      player = game_get_player(parser_get_int(parse, 1));
      parser_command_destroy(parse);
      if (player)
	{
	  snprintf(buffer, GUI_BUFFER_SIZE, "pin %i %i %i %i %i %i %i %i %i %i",
		  player->id, player->ppos_x, player->ppos_y,
		  player->inv_food, player->inv_linemate, player->inv_deraumere,
		  player->inv_sibur, player->inv_mendiane,
		   player->inv_phiras, player->inv_thystame);
	  gui_send(gui, buffer);
	  return;
	}
    }
  gui_command_sbp(gui, NULL);
}

void gui_command_sgt(t_gui *gui, char *command)
{
  char buffer[GUI_BUFFER_SIZE];

  (void) command;
  snprintf(buffer, GUI_BUFFER_SIZE, "sgt %i", clock_get_frequency());
  gui_send(gui, buffer);
}

void gui_command_sst(t_gui *gui, char *command)
{
  t_command *parse;
  int clock;
  int old;

  parse = parser_parse(command, "sgt %d");
  if (parse)
    {
      clock = parser_get_int(parse, 1);
      parser_command_destroy(parse);
      old = clock_get_frequency();
      if (clock_set_frequency(clock))
	{
	  gui_command_sgt(gui, NULL);
	  return;
	}
    }
  gui_command_sbp(gui, NULL);
}

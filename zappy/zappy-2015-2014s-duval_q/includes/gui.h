/*
** gui.h for extlibc in /home/epitech/c/Zappy
**
** Made by claude ramseyer
** Login   <ramsey_c@epitech.net>
**
** Started on  Mon Jun 2 10:00:00 2011 claude ramseyer
** Last update Mon Jun 2 10:00:01 2011 claude ramseyer
*/

#ifndef __GUI_H__
#define	__GUI_H__

#include "list.h"
#include "logger.h"
#include "client.h"
#include "game.h"

#define GUI_BUFFER_SIZE 64
#define GUI_COMMAND_SIZE 3

typedef t_client t_gui;
typedef t_execute_cb t_gui_execute_cb;

typedef struct s_gui_manager {
	t_list guis;
	t_list commands;
} t_gui_manager;

typedef struct s_gui_command {
	char name[GUI_COMMAND_SIZE + 1];
	t_gui_execute_cb callback;
} t_gui_command;

bool gui_init();
void gui_register_command(char *name, t_gui_execute_cb callback);
void gui_destroy();

void gui_connect(t_gui *gui);
void gui_remove(t_gui *gui);
void gui_execute(t_gui *gui, char *command);
int gui_send(t_gui *gui, char *msg);
void gui_send_all(char *msg);

void gui_update_ressource(t_tile *tile);

void gui_action_forward(t_player *player);
void gui_action_left(t_player *player);
void gui_action_right(t_player *player);
void gui_action_new(t_player *player);
void gui_action_death(t_player *player);
void gui_action_take(t_player *player, t_item item);
void gui_action_drop(t_player *player, t_item item);
void gui_action_broadcast(t_player *player, char *msg);
void gui_action_expulse(t_player *player);

void gui_command_msz(t_gui *gui, char *command);
void gui_command_mct(t_gui *gui, char *command);
void gui_command_bct(t_gui *gui, char *command);
void gui_command_tna(t_gui *gui, char *command);
void gui_command_ppo(t_gui *gui, char *command);
void gui_command_plv(t_gui *gui, char *command);
void gui_command_pin(t_gui *gui, char *command);
void gui_command_sgt(t_gui *gui, char *command);
void gui_command_sst(t_gui *gui, char *command);
void gui_command_suc(t_gui *gui, char *command);
void gui_command_sbp(t_gui *gui, char *command);
void gui_command_pnw(t_gui *gui, char *command);
void gui_command_enw(t_gui *gui, char *command);

#endif

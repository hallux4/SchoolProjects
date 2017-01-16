/*
** game.h for extlibc in /home/epitech/c/Zappy
**
** Made by claude ramseyer
** Login   <ramsey_c@epitech.net>
**
** Started on  Mon Jun 2 10:00:00 2011 claude ramseyer
** Last update Mon Jun 2 10:00:01 2011 claude ramseyer
*/

#ifndef __GAME_H__
#define	__GAME_H__

#include <stdlib.h>
#include "game_info.h"
#include "logger.h"
#include "client.h"
#include "kernel.h"

/*player*/
t_player *player_create();
void player_free(t_player *player);

/*team*/
t_team *team_create(char *name, int slots);
t_player *team_create_player(t_team *team);

/*world*/
void world_add_player(t_player *player, int x, int y);
void world_remove_player(t_player *player);
bool world_move_player(t_player *player);
bool world_move_to(t_player *player, t_orientation direction);
t_tile *world_get_tile(int x, int y);

/*game*/
bool game_init(int x, int y, int nb_slots, int food);
int game_width();
int game_height();
void game_destroy();

void game_create_team(char *team);
void game_add_team(t_team *team);
t_team *game_get_team(char *name);
t_list *game_get_teams();
t_player *game_get_player(int id);
int game_get_item_from_name(char *name);
int game_count_team();

t_player *game_get_slot(char *team);
void game_add_slot(t_player *player);
void game_remove_slot(t_player *player);
void game_free_player(t_player *player);

void game_consume_food(t_player *player, int error);
void game_food_dead(t_player *player);
t_tile *world_add_ressource(t_item ressource);

void game_world_dump();

/*callback*/
void player_broadcast_end_cb(t_client *client, int error);
void player_broadcast_start_cb(t_client *client, char *command);
void player_connect_nbr_cb(t_client *client, char *command);
void player_death_cb(t_client *client, char *command);
void player_drop_end_cb(t_client *client, int error);
void player_drop_start_cb(t_client *client, char *command);
void player_expulse_end_cb(t_client *client, int error);
void player_expulse_start_cb(t_client *client, char *command);
void player_fork_end_cb(t_client *client, int error);
void player_fork_start_cb(t_client *client, char *command);
void player_forward_end_cb(t_client *client, int error);
void player_forward_start_cb(t_client *client, char *command);
void player_incantation_end_cb(t_client *client, int error);
void player_incantation_start_cb(t_client *client, char *command);
void player_inventory_end_cb(t_client *client, int error);
void player_inventory_start_cb(t_client *client, char *command);
void player_left_end_cb(t_client *client, int error);
void player_left_start_cb(t_client *client, char *command);
void player_look_end_cb(t_client *client, int error);
void player_look_start_cb(t_client *client, char *command);
void player_right_end_cb(t_client *client, int error);
void player_right_start_cb(t_client *client, char *command);
void player_take_end_cb(t_client *client, int error);
void player_take_start_cb(t_client *client, char *command);

#endif

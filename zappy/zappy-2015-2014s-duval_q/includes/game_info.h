/*
** game_info.h for extlibc in /home/epitech/c/Zappy
**
** Made by claude ramseyer
** Login   <ramsey_c@epitech.net>
**
** Started on  Mon Jun 2 10:00:00 2011 claude ramseyer
** Last update Mon Jun 2 10:00:01 2011 claude ramseyer
*/

#ifndef __GAME_INFO_H__
#define	__GAME_INFO_H__

#include <stdbool.h>
#include "list.h"

#define	REP_OK		"ok"
#define	REP_KO		"ko"
#define	REP_VOIR	"%s"
#define	REP_INVENTORY	"{nourriture %d, linemate %d, deraumere %d, sibur %d, mendiane %d, phiras %d, thystame %d}"
#define	REP_INCANTATION	"elevation en cours niveau actuel : %d"
#define	REP_CONNECT_NBR	"%d"
#define	REP_DEATH	"mort"

#define	TEAM_NAME_SIZE	32

#define	DELAY_STANDARD	7
#define	DELAY_INCANT	300
#define	DELAY_FORK	42
#define DELAY_FOOD	126

#define WORLD_MAX_SIZE 1000
#define TEAM_MAX_SLOT 50

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define IMPAIR(a) ((a) & 1)
#define PAIR(a) (!(IMPAIR(a)))
#define ABS(a) ((a) > 0 ? (a) : -(a))

typedef struct s_player t_player;
typedef struct s_team t_team;
typedef struct s_tile t_tile;

typedef enum {
	IT_FOOD,
	IT_LINEMATE,
	IT_DERAUMERE,
	IT_SIBUR,
	IT_MENDIANE,
	IT_PHIRAS,
	IT_THYSTAME
} t_item;

typedef enum {
	OR_NORTH,
	OR_EAST,
	OR_SOUTH,
	OR_WEST
} t_orientation;

typedef struct s_leveler {
	int nb_players;
	int linemate;
	int deraumere;
	int sibur;
	int mendiane;
	int phiras;
	int thystame;
} t_leveler;

typedef struct s_inventory {
	int food;
	int linemate;
	int deraumere;
	int sibur;
	int mendiane;
	int phiras;
	int thystame;
} t_inventory;

typedef struct s_pos {
	int x;
	int y;
} t_pos;

typedef t_pos t_dim;
typedef t_pos t_vector;

typedef struct s_world {
	t_tile *tiles;
	t_dim dimensions;
#define w_width dimensions.x
#define w_height dimensions.y
} t_world;

typedef struct s_game {
	t_world world;
	t_list teams;
	t_list players;
	t_list free;
	int nb_slots;
	int food;
} t_game;

struct s_player {
	int id;
	t_team *team;
	t_tile *tile;
#define ppos_x tile->coord.x
#define ppos_y tile->coord.y
	t_orientation orientation;
	t_inventory inventory;
#define inv_food inventory.food
#define inv_linemate inventory.linemate
#define inv_deraumere inventory.deraumere
#define inv_sibur inventory.sibur
#define inv_mendiane inventory.mendiane
#define inv_phiras inventory.phiras
#define inv_thystame inventory.thystame
	int level;
	int ghost;
};

struct s_team {
	char name[TEAM_NAME_SIZE + 1];
	int players;
	int free;
	int slots;
};

struct s_tile {
	t_list players;
	t_pos coord;
#define pos_x coord.x
#define pos_y coord.y
	t_inventory ressources;
#define rc_food ressources.food
#define rc_linemate ressources.linemate
#define rc_deraumere ressources.deraumere
#define rc_sibur ressources.sibur
#define rc_mendiane ressources.mendiane
#define rc_phiras ressources.phiras
#define rc_thystame ressources.thystame
};

#endif

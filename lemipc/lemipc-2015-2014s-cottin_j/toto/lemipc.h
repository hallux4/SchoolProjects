#ifndef __LEMIPC_H__
# define __LEMIPC_H__

#include "libc_my.h"
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <time.h>
#include <SDL/SDL.h>

# define MAP_SIZE       100
# define MAP_LEN        10
# define TIME_TO_WAIT   1000000

# define MAP_KEY        1
# define SEMAPHORE_KEY  2

#define MAX_TEAM        42421337

typedef struct          s_teams
{
  int           no;
  int           R;
  int           G;
  int           B;
}                       t_teams;

/* run.c */
void            run(int no_team, t_bool aff);
void            aff_map(int *map);
int             *get_map();
void            aff_rules();

/* data.c */
key_t           get_key(const char *pathname, int id);
t_bool          verif_go(int *map, int team);
void            continue_aff(int *map);
t_bool          has_win(int *map, int team);

/* map.c */
int             *create_map(int shm_id);
void            delete_map();
int             get_nb_players(int *map);
int             place_player(int *map, int semid);

/* loop.c */
void            main_loop(int no_team, t_bool aff, int pos, int *map, int semid);
int             found_ennemy(int no_team, int pos, int *map);
t_bool          is_dead(int no_team, int pos, int *map, int semid);
int             calc_len(int pos1, int pos2);

/* semaphore.c */
int             get_semaphore();
int             sem_delete(int semid);
int             sem_lock(int semid);
int             sem_unlock(int semid);
int             sem_unlockreturn(int semid, int ret);

/* move.c */
t_bool          move_up(int *map, int pos, int no_team);
t_bool          move_down(int *map, int pos, int no_team);
t_bool          move_right(int *map, int pos, int no_team);
t_bool          move_left(int *map, int pos, int no_team);
int             move_to_ennemy(int *map, int pos, int no_team, int semid);

/* move2.c */
int             random_move(int pos, int *map, int no_team);
int             horiz_move(int pos, int pos_en, int *map, int no_team, int semid);
int             vert_move(int pos, int pos_en, int *map, int no_team, int semid);

/* sdl_map.c */
void            aff_map_sdl(int *map, SDL_Surface *carreblanc,
                            SDL_Surface *ecran, t_teams *teams);
void            drawFullRect(SDL_Surface * surf, int posX, int posY, t_teams teams);
void            drawteam(SDL_Surface *ecran, SDL_Rect pos, int team, t_teams *teams);
SDL_Surface     *init_sdl(int x, int y);

/* aff.c */
t_teams         remp_struct(int no, int R, int G, int B);
t_teams         *init_teams(t_teams *t);
void            sdl_quit(int *map, SDL_Surface *ecran, SDL_Surface *carre, t_teams *teams);

#endif
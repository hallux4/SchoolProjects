/*
** lemipc.h for  in /home/cottin_j/Desktop/Dropbox/lemipc/lemipc-2015-2014s-cottin_j
** 
** Made by joffrey cottin
** Login   <cottin_j@epitech.net>
** 
** Started on  Sun Mar 25 17:12:04 2012 joffrey cottin
** Last update Sun Mar 25 17:53:19 2012 hallux
*/

#ifndef		LEMIPC_H_
# define	LEMIPC_H_

# include	<sys/types.h>
# include	<sys/ipc.h>
# include	<sys/shm.h>
# include	<sys/sem.h>
#include	<time.h>
#include        <stdlib.h>
#include        <string.h>
#include        <stdio.h>
# include	<limits.h>
# include	<stdbool.h>
# include	<unistd.h>

extern const int	map_size;
extern const int	map_len;
extern const int	time_to_wait;

# define	MAP_KEY		2
# define	SEMAPHORE_KEY	2

enum	e_move {
  UP = (- 10),
  DOWN = (10),
  LEFT = (- 1),
  RIGHT = (1)
};

typedef bool	(*func)(int *battleground, int pos, int no_squad);

typedef struct	s_move {
  int		nb_dir;
  func		func_dir;
  enum e_move	ret_dir;
} t_move;

/*
** execute.c
*/
void	execute(int no_squad, bool aff);
void	map_dsp(int *battleground);

/*
** dataz.c
*/
key_t	the_key_is(const char *pathname, int id);
bool	go(int *battleground, int squad);
void	continue_dsp(int *battleground);
bool	winner(int *battleground, int squad);

/*
** battleground.c
*/
int	*create_map(int shm_id);
void	delete_map();
int	get_playerz(int *battleground);
int	place_player(int *battleground, int semid);

/*
** loop.c
*/
void	main_loop(int no_squad,
		  bool aff,
		  int pos,
		  int *battleground,
		  int semid);
int	battle_dir(int no_squad, int pos, int *battleground);
bool	is_dead(int no_squad, int pos, int *battleground, int semid);
int	calc_len(int pos1, int pos2);

/*
** semz.c
*/
int	get_semz();
int	delete_semz(int semid);
int	lock_semz(int semid);
int	unlock_semz(int semid);
int	ret_unlock_semz(int semid, int ret);

/*
** moving_one.c
*/
bool	up(int *battleground, int pos, int no_squad);
bool	down(int *battleground, int pos, int no_squad);
bool	right(int *battleground, int pos, int no_squad);
bool	left(int *battleground, int pos, int no_squad);
int	ennemy(int *battleground, int pos, int no_squad, int semid);

/*
** moving_two.c
*/
int	randomed(int pos, int *battleground, int no_squad);
int	horiz_move(int pos,
		   int pos_en,
		   int *battleground,
		   int no_squad,
		   int semid);

int	vert_move(int pos,
		  int pos_en,
		  int *battleground,
		  int no_squad,
		  int semid);

/*
** error_func.c
*/
void	error_func(char *error, int code);

#endif /* LEMIPC_H_ */

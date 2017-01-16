/*
** semz.c for  in /home/cottin_j/lemipc-2015-2014s-cottin_j
** 
** Made by joffrey cottin
** Login   <cottin_j@epitech.net>
** 
** Started on  Sun Mar 25 17:06:36 2012 joffrey cottin
** Last update Sun Mar 25 17:59:20 2012 hallux
*/

#include	"lemipc.h"

int		get_semz()
{
  key_t		key;
  int		sem_id;

  key = the_key_is(getenv("PWD"), SEMAPHORE_KEY);
  if ((sem_id = semget(key, 1, SHM_R | SHM_W)) == -1)
    {
      sem_id = semget(key, 1, IPC_CREAT | SHM_R | SHM_W);
      semctl(sem_id, 0, SETVAL, 1);
    }
  return (sem_id);
}

int		delete_semz(int semid)
{
  int		ret;

  ret = semctl(semid, 0, IPC_RMID, 0);
  if (ret != -1)
    printf("Semaphore deleted\n");
  else
    perror("Semaphore delete: ");
  return (ret);
}

int		lock_semz(int semid)
{
  struct sembuf	sempar;

  sempar.sem_num = 0;
  sempar.sem_op = -1;
  sempar.sem_flg = SEM_UNDO;
  return (semop(semid, &sempar, 1));
}

int		unlock_semz(int semid)
{
  struct sembuf	sempar;

  sempar.sem_num = 0;
  sempar.sem_op = 1;
  sempar.sem_flg = SEM_UNDO;
  return (semop(semid, &sempar, 1));
}

int		ret_unlock_semz(int semid, int ret)
{
  struct sembuf	sempar;

  sempar.sem_num = 0;
  sempar.sem_op = 1;
  sempar.sem_flg = SEM_UNDO;
  if (semop(semid, &sempar, 1) == -1)
    {
      perror("semop : ");
      return (-1);
    }
  return (ret);
}

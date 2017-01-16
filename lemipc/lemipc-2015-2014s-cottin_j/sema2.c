#include        <sys/types.h>
#include	<sys/shm.h>
#include	<sys/sem.h>
#include        <sys/ipc.h>
#include        <stdio.h>


int     main(int argc, char **argv)
{
  key_t key;
  int	sem_id;
  int	*addr;
  struct sembuf sops;

  if (argc != 2)
    {
      printf("[USAGE] %s pathname\n", argv[0]);
      return (0);
    }
  key = ftok(argv[1], 0);
  printf("key = [%d]\n", key);

  sem_id = semget(key, 1, SHM_R | SHM_W);
  if (sem_id == -1)
    {
      sem_id = semget(key, 1, IPC_CREAT | SHM_R | SHM_W);
      printf("sem_id = [%d]\n", sem_id);
      semctl(sem_id, 0, SETVAL, 4);
    }
  else
    {
      printf("value = %d\n \n", semctl(sem_id, 0, GETVAL));
      sops.sem_num = 0;
      sops.sem_op = 1;
      sops.sem_flg = 0;
      semop(sem_id, &sops, 1);
      printf("value = %d\n \n", semctl(sem_id, 0, GETVAL));
}
  return (0);
}

#include        <sys/types.h>
#include	<sys/shm.h>
#include        <sys/ipc.h>
#include        <stdio.h>


int     main(int argc, char **argv)
{
  key_t key;
  int	shm_id;
  int	*addr;

  if (argc != 2)
    {
      printf("[USAGE] %s pathname\n", argv[0]);
      return (0);
    }
  key = ftok(argv[1], 0);
  printf("key = [%d]\n", key);

  shm_id = shmget(key, 42, SHM_R | SHM_W);
  if (shm_id == -1)
    {
      shm_id = shmget(key, 42, IPC_CREAT | SHM_R | SHM_W);
      printf("Creating shm [%d]\n", shm_id);
      addr = shmat(shm_id, NULL, SHM_R | SHM_W);
      sprintf((char *)addr, "Epitech Nice Rox");
    }
  else
    {
      printf("Already create [%d]\n", shm_id);
      addr = shmat(shm_id, NULL, SHM_R | SHM_W);
      printf("--> %s\n", (char*) addr);
      shmctl(shm_id, IPC_RMID, NULL);
    }
  return (0);
}

#include        <sys/types.h>
#include        <sys/shm.h>
#include        <sys/ipc.h>
#include        <stdio.h>
#include <string.h>


typedef struct s_msg
{
  long type;
  char str[32];
} t_msg;


int     main(int argc, char **argv)
{
  key_t key;
  int   msg_id;
  t_msg	mymsg;

  if (argc != 2)
    {
      printf("[USAGE] %s pathname\n", argv[0]);
      return (0);
    }
  key = ftok(argv[1], 0);
  printf("key = [%d]\n", key);

  msg_id = msgget(key, SHM_R | SHM_W);
  if (msg_id == -1)
    {
      msg_id = msgget(key, IPC_CREAT | SHM_R | SHM_W);
      printf("Create msg (%d)\n", msg_id);
      msgrcv(msg_id, &mymsg, sizeof(mymsg), 42, 0);
      printf("Receive: %s (%d)\n", mymsg.str, mymsg.type);
    }
  else
    {
      mymsg.type = 42;
      bzero(mymsg.str, sizeof(mymsg));
      printf("toto\n");
      sprintf(mymsg.str, "Hello World\n");
      msgsnd(msg_id, &mymsg, sizeof(mymsg), 0);
      msgctl(msg_id, IPC_RMID, 0);
    }
  return (0);
}

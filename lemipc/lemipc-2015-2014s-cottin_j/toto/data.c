#include "lemipc.h"

t_bool          has_win(int *map, int team)
{
  int           i;

  i = 0;
  while ((map[i] != 0 && map[i] != team)
         || i < MAP_SIZE)
    i++;
  if (i == MAP_SIZE - 1)
    return (TRUE);
  return (FALSE);
}

t_bool          verif_go(int *map, int team)
{
  int           i;

  i = 0;
  if (get_nb_players(map) < 4)
    return (FALSE);
  while ((map[i] != 0 && map[i] != team)
         || i < MAP_SIZE)
    i++;
  if (i == MAP_SIZE - 1)
    return (FALSE);
  return (TRUE);
}

key_t           get_key(const char *pathname, int id)
{
  key_t         key;

  if (pathname == NULL)
    exit_error("Ftok error : pathname is NULL\n");
  key = ftok(pathname, id);
  if (key == -1)
    exit_error("Ftok error : cannot create key\n");
  return (key);
}

void            continue_aff(int *map)
{
  while (get_nb_players(map) > 1)
    {
      aff_map(map);
      sleep(1);
    }
  exit(EXIT_SUCCESS);
}
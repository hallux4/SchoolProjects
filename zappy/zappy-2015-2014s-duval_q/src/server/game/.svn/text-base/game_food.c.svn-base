/*
** game_food.c for extlibc in /home/epitech/c/Zappy
**
** Made by claude ramseyer
** Login   <ramsey_c@epitech.net>
**
** Started on  Mon Jun 2 10:00:00 2011 claude ramseyer
** Last update Mon Jun 2 10:00:01 2011 claude ramseyer
*/

#include "game.h"
#include "client.h"
#include "gui.h"

void game_consume_food(t_player *player, int error)
{
  (void) error;
  if (player->inv_food > 0)
    {
      player->inv_food--;
      gui_update_ressource(world_add_ressource(IT_FOOD));
      kernel_register_wakeup(DELAY_FOOD,
			     (kn_wakeup_cb) & game_consume_food, player);
    }
  else
    game_food_dead(player);
}

void game_food_dead(t_player *player)
{
  t_client *client;

  logger_message("[GAME] player %i starved ... dead!", player->id);
  client = client_get_from_player(player);
  if (client)
    {
      client_send(client, "mort");
      client_unconnect(client);
    }
  gui_action_death(player);
  game_free_player(player);
}

t_tile *world_add_ressource(t_item ressource)
{
  t_tile *tile;
  int *inventory;

  tile = world_get_tile(rand(), rand());
  inventory = (int *) &tile->ressources;
  inventory[ressource]++;
  return tile;
}

//
// client.hh for  in /home/hallux/Bureau/Dropbox/zappy/zappy-2015-2014s-duval_q/src/client/papy
//
// Made by joffrey
// Login   <hallux@epitech.net>
//
// Started on  Mon Jun 25 00:27:28 2012 joffrey
// Last update Wed Jun 27 14:52:48 2012 joffrey
//

#ifndef CLIENT_HH
#define CLIENT_HH

#include <map>
#include <string>
#include "connect.hh"

typedef enum actual {
  ONE,
  TWO,
  THREE,
  FOUR,
  FIVE,
  SIX,
  SEVEN,
  EIGHT
} level;

// avance d’une case
// tourne à droite de 90 degrés
// tourne à gauche de 90 degrés
// voir
// inventaire
// prend objet
// pose objet
// expulse les joueurs de cette case
// broadcast texte
// débute l’incantation
// fork un joueur
// Nombre de slots non utilisés par l’équipe
// mort d’un joueur

class Client {

public:

  Client();
  Client(int argc, char **argv);
  ~Client();

  // debug
  void test_args();
  void display_map();
  void display_params();

  int move();
  int turn_right();
  int turn_left();
  int observe();
  int inventory();
  int take_item();
  int drop_item();
  int push_player();
  int speak();
  int cast_spell();
  int forking();
  int free_slot();
  int die_count();

  void delete_option();
  void fill_args(int argc, char **argv);

private:

  std::map<std::string, std::string> map_args;
  actual level;
  Connect * link;

};

#endif

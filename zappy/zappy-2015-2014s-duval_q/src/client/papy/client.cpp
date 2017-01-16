//
// client.cpp for  in /home/hallux/Bureau/Dropbox/zappy/zappy-2015-2014s-duval_q/src/client/papy
//
// Made by joffrey
// Login   <hallux@epitech.net>
//
// Started on  Mon Jun 25 00:26:39 2012 joffrey
// Last update Wed Jun 27 15:29:42 2012 joffrey
//

#include "client.hh"

Client::Client()
{

}

Client::Client(int argc, char **argv)
{
  link = new Connect(argc, argv);
}

Client::~Client()
{

}

int Client::move()
{
  return (0);
}

int Client::turn_right()
{
  return (0);
}

int Client::turn_left()
{
  return (0);
}

int Client::observe()
{
  return (0);
}

int Client::inventory()
{
  return (0);
}

int Client::take_item()
{
  return (0);
}

int Client::drop_item()
{
  return (0);
}

int Client::push_player()
{
  return (0);
}

int Client::speak()
{
  return (0);
}

int Client::cast_spell()
{
  return (0);
}

int Client::forking()
{
  return (0);
}

int Client::free_slot()
{
  return (0);
}

int Client::die_count()
{
  return (0);
}

void Client::test_args()
{
  map_args = link->get_info();
  display_map();
}

void Client::display_map()
{
  std::map<std::string, std::string>::iterator it_map;
  for (it_map = map_args.begin(); it_map != map_args.end(); it_map++)
    {
      std::cout << (*it_map).first << " " << (*it_map).second << std::endl;
    }
}

void Client::delete_option()
{
  delete link;
}

void Client::fill_args(int argc, char **argv)
{
  link = new Connect(argc, argv);
}

void Client::display_params()
{
  link->sin_client();
}

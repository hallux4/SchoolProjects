//
// connect.hh for  in /home/hallux/Bureau/Dropbox/zappy/zappy-2015-2014s-duval_q/src/client/papy
//
// Made by joffrey
// Login   <hallux@epitech.net>
//
// Started on  Mon Jun 25 01:14:22 2012 joffrey
// Last update Wed Jun 27 03:53:27 2012 joffrey
//

#ifndef CONNECT_HH
#define CONNECT_HH

#include <map>
#include <string>
#include <netdb.h>
#include <arpa/inet.h>
#include "options.hh"

class Connect {

public:

  Connect(int argc, char **argv);
  ~Connect();

  int	get_socket();
  void	display_opt();
  int	get_connection();
  void	xsocket();
  void	sin_client();
  void	xconnect();
  bool	is_ok() const { return sock != -1; }
  std::map<std::string, std::string> get_info();

private:

  int   sock;
  Options *command;

  struct sockaddr_in *sin;
  struct protoent *pe;
};

#endif

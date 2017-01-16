//
// options.hh for  in /home/hallux/Bureau/Dropbox/zappy/zappy-2015-2014s-duval_q/src/client/papy
//
// Made by joffrey
// Login   <hallux@epitech.net>
//
// Started on  Mon Jun 25 01:29:56 2012 joffrey
// Last update Wed Jun 27 16:47:05 2012 joffrey
//

#ifndef OPTION_HH
#define OPTION_HH

#include <string>
#include <stdlib.h>
#include <sstream>
#include <iostream>
#include "error.hpp"

class Options {

public:

  Options(int argc, char **argv);
  ~Options();
  int get_opt();
  void usage();
  void is_number();

  std::string const & get_team_name();
  std::string const & get_host_name();
  std::string const &  get_port();

private:

  int args_count;
  char **args_value;

  std::string team_name;
  std::string host_name;
  std::string port;

};

#endif

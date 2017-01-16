//
// options.cpp for  in /home/hallux/Bureau/Dropbox/zappy/zappy-2015-2014s-duval_q/src/client/papy
//
// Made by joffrey
// Login   <hallux@epitech.net>
//
// Started on  Mon Jun 25 01:32:14 2012 joffrey
// Last update Wed Jun 27 17:17:58 2012 joffrey
//

#include "options.hh"

Options::Options(int argc, char **argv)
  : args_count(argc), args_value(argv)
{
  host_name = "localhost";
  team_name = "Unknown";
  port = "Unknown";
  get_opt();
}

Options::~Options()
{

}

int Options::get_opt()
{
  int opt = 0;

  while ((opt = getopt(args_count, args_value, "n:p:h:")) != -1)
    {
      if (opt == 'n')
        team_name = std::string(optarg);
      else if (opt == 'p')
        {
          port = std::string(optarg);
          is_number();
        }
      else if (opt == 'h')
        host_name = std::string(optarg);
      if (opt == '?' || opt == ':')
        usage();
    }
  return (0);
}

void Options::usage()
{
  throw error("Bad Syntax Option.\n"
              "-n nom d’equipe\n"
              "-p port\n"
              "-h nom de la machine, par defaut localhost");
}

std::string const & Options::get_team_name()
{
  return (team_name);
}

std::string const & Options::get_host_name()
{
  return (host_name);
}

std::string const & Options::get_port()
{
  return (port);
}

void Options::is_number()
{
  std::istringstream tmp(port);
  int portal;
  tmp >> portal;

  if (portal < 1 || portal > 65535)
    throw error("Incorrect Port Number");
}


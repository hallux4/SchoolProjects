//
// connect.cpp for  in /home/hallux/Bureau/Dropbox/zappy/zappy-2015-2014s-duval_q/src/client/papy
//
// Made by joffrey
// Login   <hallux@epitech.net>
//
// Started on  Mon Jun 25 01:17:47 2012 joffrey
// Last update Wed Jun 27 16:41:59 2012 joffrey
//

#include "connect.hh"

Connect::Connect(int argc, char **argv)
  : sock(-1)
{
  command = new Options(argc, argv);
}

Connect::~Connect()
{
  delete command;
}

int Connect::get_socket()
{
  return (0);
}

//debug
void Connect::display_opt()
{
  std::cout << command->get_host_name()
            << command->get_port()
            << command->get_team_name()
            << std::endl;
}

std::map<std::string, std::string> Connect::get_info()
{
  std::map<std::string, std::string> args_map;
  std::map<std::string, std::string>::iterator it;

  args_map["team_name"] = command->get_team_name();
  args_map["host_name"] = command->get_host_name();
  args_map["port"] = command->get_port();

  return (args_map);
}

int Connect::get_connection()
{
  pe = getprotobyname("TCP");
  xsocket();
  xconnect();
}

void Connect::xsocket()
{
  sock = socket(AF_INET, SOCK_STREAM, pe->p_proto);
  if (!is_ok())
    throw error("Cannot open socket");
}

void Connect::sin_client()
{
  const char *portal = command->get_port().c_str();

  sin = (sockaddr_in*)malloc(sizeof(struct sockaddr_in));
  sin->sin_family = AF_INET;
  sin->sin_port = htons(atoi(portal));
  std::string ip("127.0.0.1");

  if (command->get_host_name() == "localhost")
    // std::cout << "TOTO A LA PLAGE\n";
    sin->sin_addr.s_addr = inet_addr(ip.c_str());
  else
    throw error ("TMP::Dunno what IP it is !!::TMP");
}

void Connect::xconnect()
{

}

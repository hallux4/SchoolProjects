#include <iostream>
#include "network.hpp"
#include "game.hpp"
#include "parser.hpp"
#include "gui.hpp"

void  network::iteration(__attribute__((unused))INetwork &sock,
                         __attribute__((unused))game::data &data,
                         __attribute__((unused))parser &pars)
{
  std::string buffer;

  if (!sock == false)
    throw network::except("Connection lost");
  sock.send(data.waitList);
  sock.receive(buffer, 0.030);
  pars.parse(buffer);
  pars.interpret(data);
}

void  network::init(__attribute__((unused))INetwork &sock,
                    __attribute__((unused))game::data &data,
                    __attribute__((unused))parser &pars)
{
  std::string buffer;
  int         essay = 1;
  bool        status = false;

  status = sock.connect();
  while (status != true)
    {
      essay++;
      if (essay > 50)
        throw network::except("Impossible de se connecter au server distant");
      sf::Sleep(2);
      std::cout << "Essai " << essay << " - ";
      status = sock.connect();
    }
  sock.receive(buffer, 10);
  pars.parse(buffer);
  if (pars.getFirstString().compare("BIENVENUE") == 0)
    {
      sock.send("GRAPHIC\n");
      data.allowConnection();
      pars.delFirstString();
      sock.send(data.waitList);
      sock.receive(buffer, 10);
      pars.parse(buffer);
      pars.interpret(data);
    }
  else
    throw network::except("Mauvais server");
}

extern "C" INetwork     *network::create()
{
  return (new sfNetwork);
}

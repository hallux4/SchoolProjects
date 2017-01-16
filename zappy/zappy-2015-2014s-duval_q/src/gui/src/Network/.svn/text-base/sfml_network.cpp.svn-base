#include <iostream>
#include "network/sfml_network.hpp"
#include "parser.hpp"
#include "color.hpp"

sfNetwork::sfNetwork() : _addr("localhost"), _port(4242)
{
  _sock.SetBlocking(true);
 _selector.Add(this->_sock);
}

sfNetwork::~sfNetwork()
{
  if (_sock.IsValid())
    _sock.Close();
}

void  sfNetwork::send(const std::string &msg)
{
  if (_sock.Send(msg.c_str(), msg.size()) != sf::Socket::Done)
   throw network::except("sfNetwork::send");
}

void  sfNetwork::send(const std::list<std::string> &list)
{
  std::list<std::string>::const_iterator	cit;

  cit = list.begin();
  while (cit != list.end())
    {
      if (_sock.Send(cit->c_str(), cit->size()) != sf::Socket::Done)
        throw network::except("sfNetwork::send(list)");
      cit++;
    }
}

bool  sfNetwork::connect()
{
  sf::Socket::Status  res;

  std::cout << "Tentative de connection ... " << std::flush;
  res = _sock.Connect(_port, _addr);
  if (res == sf::Socket::Done)
    {
      std::cout << color::green << "Réussie!" << color::white << std::endl;
      return (true);
    }
  else
    {
      std::cout << color::red << "Echec." << color::white << std::endl;
      return (false);
    }
}

bool  sfNetwork::disconnect()
{
  if (_sock.IsValid())
    return (_sock.Close());
  return (true);
}

void  sfNetwork::setIp(const std::string &host)
{
  this->_addr = host;
  if(this->_addr.IsValid() == false)
    std::cerr << "L'adresse '" << host << "' est invalide" << std::endl;
}

void  sfNetwork::setPort(const std::string &port)
{
  this->_port = static_cast<unsigned short>(atoi(port.c_str()));
}

bool  sfNetwork::isValid(void)
{
  return (_sock.IsValid());
}

bool  sfNetwork::operator!()
{
  return (_sock.IsValid());
}

void    sfNetwork::receive(std::string &buffer, float timeout)
{
  if (isReady(timeout))
    receive(buffer);
}

void  sfNetwork::receive(std::string &buffer)
{
  char          receive_buffer[512];
  std::size_t   howmany = 512;

  buffer.clear();
  while (isReady(0.010))
    {
      std::memset(receive_buffer, '\0', howmany);
      if (_sock.Receive(receive_buffer, 256, howmany) != sf::Socket::Done)
        throw network::except("sfNetwork::receive");
      buffer += receive_buffer;
    }
}

bool  sfNetwork::isReady(float timeout)
{
  if (_selector.Wait(timeout) > 0)
    return (true);
  return (false);
}

#ifndef __NETWORK_SFML_NETWORK_HPP_
#define __NETWORK_SFML_NETWORK_HPP_

#include <SFML/Network.hpp>
#include <exception>
#include "Inetwork.hpp"

class sfNetwork : public INetwork
{
public:
  sfNetwork();
  ~sfNetwork();

public:
  void  send(const std::string &msg);
  void	send(const std::list<std::string> &list);
  void  receive(std::string &buffer, float timeout);

  bool	connect();
  bool  disconnect();

  void  setIp(const std::string&host);
  void  setPort(const std::string &port);

  bool  isValid(void);
  bool  operator!();

private:
  sf::IPAddress		        _addr;
  unsigned short 	        _port;
  sf::SocketTCP		        _sock;
  sf::Selector< sf::SocketTCP > _selector;

  void receive(std::string &buffer);
  bool isReady(float timeout);

private:
  sfNetwork(const sfNetwork &other);
};

#endif /* __NETWORK_SFML_NETWORK_HPP_ */


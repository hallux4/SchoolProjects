//
// Socket.cc for network in /home/duval_q//Documents/perso/server/cppServerAPI/src/network/socket
// 
// Made by quentin duval
// Login   <duval_q@epitech.net>
// 
// Started on  Wed Jun 13 12:49:42 2012 quentin duval
// Last update Thu Jul  5 23:23:23 2012 quentin duval
//

#include	<iostream>
#include	<stdexcept>
#include	"Socket.hpp"

Socket::Socket(e_type type)
{
  this->af = AF_INET;
  if (type == UDP)
    {
      this->type = SOCK_DGRAM;
      this->protocol = IPPROTO_UDP;
    }
  else if (type == TCP)
    {
      this->type = SOCK_STREAM;
      this->protocol = IPPROTO_TCP;
    }
  else
    throw std::invalid_argument("not tcp or udp");
  this->addr_in.sin_family = AF_INET;
  this->length = sizeof(this->addr_in);
  isCrude = false;
}

Socket::Socket(SOCKET const s)
  :sock(s)
{
  isCrude = true;
}

Socket::~Socket()
{

}

void	Socket::init()
{
  if (isCrude)
    return;
  if ((sock = socket(this->af, this->type, this->protocol)) == SOCKET_ERROR)
    throw (std::invalid_argument("init : unable to init socket"));
}

void	Socket::binds(unsigned short port, std::string const &ip)
{
  if (!ip.compare("")
      || ((this->addr_in.sin_addr.s_addr = inet_addr(ip.c_str())) == INADDR_NONE))
    throw std::exception();
  else
    addr_in.sin_addr.s_addr = INADDR_ANY;
  if (port == 0)
    port = this->addr_in.sin_port;
  if (bind(sock, reinterpret_cast<SOCKADDR*>(&addr_in), this->length) == SOCKET_ERROR)
    throw std::exception();
}

void	Socket::connects(std::string const &ip, unsigned short port)
{
  SOCKADDR_IN	peer;
  
  peer.sin_family = AF_INET;
  peer.sin_port = htons(port);
  if ((peer.sin_addr.s_addr = inet_addr(ip.c_str())) == INADDR_NONE
      || connect(this->sock, reinterpret_cast<SOCKADDR*>(&peer), sizeof(peer)) == SOCKET_ERROR)
    throw std::invalid_argument("connect : unable to connect");
}
  
void    Socket::disconnects()
{
  if (closesocket(this->sock) < 0)
    throw std::exception();
}

void	Socket::listens(int max)
{
  if (listen(this->sock, max) == SOCKET_ERROR)
    throw std::exception();
}

void	Socket::accepts(Socket *peer)
{
  SOCKET	ret;
  SOCKADDR	addr;
  socklen_t	length = sizeof(addr);

  if ((ret = accept(this->sock, &addr, &length)) < 0)
    throw std::exception();
  peer->sock = ret;
  peer->setAddr(&addr);
}

void	Socket::setAddr(SOCKADDR *addr)
{
  this->addr_in = *reinterpret_cast<SOCKADDR_IN*>(addr);
  this->length = sizeof(this->addr_in);
}

void	Socket::setPort(unsigned short port)
{
  this->addr_in.sin_addr.s_addr = htons(port);
}

SOCKET	Socket::getSocket()
{
  return (this->sock);
}

SOCKADDR_IN	*Socket::getSocketAddress()
{
  return &(this->addr_in);
}

socklen_t	*Socket::getSocklenPtr()
{
  return &this->length;
}

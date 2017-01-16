//
// Socket.hh for network in /home/duval_q//Documents/perso/server/cppServerAPI/src/network/socket
// 
// Made by quentin duval
// Login   <duval_q@epitech.net>
// 
// Started on  Wed Jun 13 12:49:47 2012 quentin duval
// Last update Thu Jul  5 23:25:04 2012 quentin duval
//

#ifndef		SOCKET_HH_
# define	SOCKET_HH_

# include	<string>
# define	MAX 255

# ifdef		_WIN32
#  include	<winsock2.h>
typedef	int	socklen_t;
# elif defined	(linux)
#  include	<sys/types.h>
#  include	<sys/socket.h>
#  include	<netinet/in.h>
#  include	<arpa/inet.h>
#  include	<unistd.h>
#  define	INVALID_SOCKET	(-1)
#  define	SOCKET_ERROR	(-1)
#  define	closesocket(s)	close(s)
typedef	int	SOCKET;
typedef struct	sockaddr_in	SOCKADDR_IN;
typedef struct	sockaddr	SOCKADDR;
typedef struct	in_addr		IN_ADDR;
# endif

#include	<stdexcept>

enum e_type
  {
    TCP,
    UDP
  };

class Socket
{
private:
  SOCKET	sock;
  SOCKADDR_IN	addr_in;
  socklen_t	length;

  bool		isCrude;
  int		af;
  int		type;
  int		protocol;
  void		setAddr(SOCKADDR *addr);

public:
  Socket(e_type	type = UDP);
  Socket(SOCKET const socket = INVALID_SOCKET);
  ~Socket();

  void		init();
  void		binds(unsigned short port = 0, std::string const &ip = "localhost");
  void		connects(std::string const &ip = "localhost", unsigned short port = 0);
  void		disconnects();
  void		accepts(Socket *peer);
  void		listens(int max = MAX);

  SOCKET	getSocket();
  SOCKADDR_IN	*getSocketAddress();
  socklen_t	*getSocklenPtr();

  void		setSock(SOCKET s);
  void		setIP(std::string const &ip = "localhost");
  void		setPort(unsigned short port);

  template <typename T>
  int		sendData(T const *data, unsigned int quantity = 1)
  {
    int		ret;
    ret =  send(sock, data, sizeof(T) * quantity, 0);
    if (ret <= 0)
      {
	this->disconnects();
	throw std::invalid_argument("socket disconnect");
      }
    return (ret);
  }

  template <typename T>
  int		receiveData(T *data, unsigned int quantity = 1)
  {
    int		ret;
    ret =  recv(sock, data, sizeof(T) * quantity, 0);
    if (ret <= 0)
      {
	this->disconnects();
	throw std::invalid_argument("socket disconnect");
      }
    data[ret] = 0;
    return (ret);
  }
};

#endif	/*	SOCKET_HH_	*/

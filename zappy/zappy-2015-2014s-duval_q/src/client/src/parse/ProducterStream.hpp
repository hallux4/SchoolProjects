//
// ProducterStream.hpp for codeworker in /home/duval_q//Documents/piscine/codeworker/codeworker_d00-2014s-duval_q
// 
// Made by quentin duval
// Login   <duval_q@epitech.net>
// 
// Started on  Mon Jun  4 11:02:41 2012 quentin duval
// Last update Thu Jul  5 23:08:05 2012 quentin duval
//

#ifndef		PRODUCTERSTREAM_H_
# define	PRODUCTERSTREAM_H_

# include	<iostream>
# include	<fstream>
# include	<string>

# include	"Network.hh"

enum	e_read_type
  {
    E_SOCKET,
    E_STDIN,
    E_FILE,
    E_NONE
  };

class ProducterStream
{
private:
  e_read_type	type;
  std::fstream	file;
  Socket	*sock;
public:
  ProducterStream();
  ~ProducterStream();
  std::string nextString();
  bool loadFile(char *path);
  bool loadStdin();
  bool loadSocket(Socket &s);
  std::string	readFromStdin();
  std::string	readFromFile();
  std::string	readFromSocket();
};

#endif	/*	PRODUCTERSTREAM_H_	*/

//
// ProducterStream.cpp for codeworker in /home/duval_q//Documents/piscine/codeworker/codeworker_d00-2014s-duval_q
// 
// Made by quentin duval
// Login   <duval_q@epitech.net>
// 
// Started on  Mon Jun  4 11:14:03 2012 quentin duval
// Last update Thu Jul  5 23:16:46 2012 quentin duval
//

#include	<stdexcept>

#include	"ProducterStream.hpp"

ProducterStream::ProducterStream()
  :type(E_NONE)
{
  
}

ProducterStream::~ProducterStream()
{

}

std::string ProducterStream::nextString()
{
  std::string	tmp;

  if (this->type == E_FILE)
    return (this->readFromFile());
  else if (this->type == E_STDIN)
    return (this->readFromStdin());
  else if (this->type == E_SOCKET)
    return (this->readFromSocket());
  else
    throw std::exception();
}

bool ProducterStream::loadFile(char *path)
{
  if (this->type == E_FILE)
    {
      this->file.close();
    }
  try
    {
      this->file.open(path);
      if (file.fail())
	return (false);
    }
  catch (...)
    {
      return (false);
    }
  this->type = E_FILE;
  return (true);
}

bool ProducterStream::loadStdin()
{
  this->type = E_STDIN;
  return (true);
}

bool	ProducterStream::loadSocket(Socket &s)
{
  this->type = E_SOCKET;
  this->sock = &s;
  return (true);
}

std::string   ProducterStream::readFromSocket()
{
  char          *noire = new char[1024];
  std::string   str;
  int		nbData;

  nbData = this->sock->receiveData<char>(noire, 1024);
  noire[nbData] = '\0';
  str = noire;
  std::cout << "***receive**** " << str << std::endl;
  delete [] noire;
  return (str);  
}

std::string   ProducterStream::readFromStdin()
{
  std::string	res;

  if (!std::cin.eof())
    std::getline(std::cin, res);
  else
    throw std::exception();
  if (res.empty())
    throw std::exception();
  return (res);
}

std::string   ProducterStream::readFromFile()
{
  char		*noire = new char[1024];
  std::string	str;

  if (!this->file.is_open() || this->file.eof())
    throw std::exception();
  file.read(noire, 1024);
  noire[file.gcount()] = '\0';
  str = noire;
  delete [] noire;
  return (str);
}

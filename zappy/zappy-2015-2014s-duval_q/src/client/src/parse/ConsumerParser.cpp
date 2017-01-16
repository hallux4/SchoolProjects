//
// ConsumerParser.cpp for codeworker in /home/duval_q//Documents/piscine/codeworker/codeworker_d00-2014s-duval_q
// 
// Made by quentin duval
// Login   <duval_q@epitech.net>
// 
// Started on  Mon Jun  4 13:54:10 2012 quentin duval
// Last update Mon Jun  4 22:09:38 2012 quentin duval
//

#include	"ConsumerParser.hpp"

ConsumerParser::ConsumerParser(ProducterStream &deGuerre)
  :hamster(deGuerre)
{

}

bool	ConsumerParser::readText(char *text)
{
  int	idx = 0;

  std::string	tmp;
  while (text[idx])
    {
      if (readChar(text[idx]))
	{
	  tmp.append(1, text[idx]);
	  idx++;
	}
      else
	{
	  this->reverse(tmp.size());
	  this->buffer = tmp.append(this->buffer);
	  return (false);
	}
    }
  return (true);
}

bool	ConsumerParser::readEOF()
{
  try
    {
      feedMe();
    }
  catch(...)
    {
      return (true);
    }
  return (false);
}

bool	ConsumerParser::readUntil(char c)
{
  std::string	tmp;
  try
    {
      while (!peekChar(c))
	{
	  this->feedMe();
          this->record(this->buffer.at(0));
	  tmp.append(buffer.substr(0, 1));
	  this->buffer = this->buffer.substr(1, this->buffer.size());
	}
    }
  catch (...)
    {
      this->reverse(tmp.size());      
      this->buffer = tmp.append(this->buffer);
      return (false);
    }
  this->record(this->buffer.at(0));
  this->buffer = this->buffer.substr(1, this->buffer.size());
  return (true);
}

bool	ConsumerParser::readUntilEOF()
{
  try
    {
      while (true)
	{
	  this->feedMe();
	  this->record(this->buffer.at(0));
	  this->buffer = this->buffer.substr(1, this->buffer.size());
	}
    }
  catch(...)
    {
      return (true);
    }
  return (false);
}

bool	ConsumerParser::readInteger()
{
  if (readRange('0', '9'))
    {
      while (readRange('0', '9'));
    }
  else
    {
      return (false);
    }
  return (true);
}

bool	ConsumerParser::readIdentifier()
{
  if (readRange('a', 'z') || readRange('A', 'Z') || readChar('_'))
    {
      while (readRange('a', 'z')
	     || readRange('A', 'Z')
	     || readChar('_')
	     || readRange('0', '9'));
    }
  else
    {
      return (false);
    }
  return (true);
}

void	ConsumerParser::reverse(int len)
{
  std::map<std::string, std::string>::iterator it;

  for ( it=this->capture.begin() ; it != this->capture.end(); it++)
    {
      std::string	tmp = (*it).second;
      (*it).second = tmp.substr(0, tmp.size() - len);
    }
}

void	ConsumerParser::record(char c)
{
  std::map<std::string, std::string>::iterator it;

  for ( it=this->capture.begin() ; it != this->capture.end(); it++)
    {
      std::string       tmp = (*it).second;
      (*it).second.append(1, c);
    }
}

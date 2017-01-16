//
// ConsumerParser.hpp for codeworker in /home/duval_q//Documents/piscine/codeworker/codeworker_d00-2014s-duval_q
// 
// Made by quentin duval
// Login   <duval_q@epitech.net>
// 
// Started on  Mon Jun  4 12:22:38 2012 quentin duval
// Last update Mon Jun  4 19:41:00 2012 quentin duval
//

#ifndef		CONSUMERPARSER_HPP_
# define	CONSUMERPARSER_HPP_

# include	<map>

# include	"ProducterStream.hpp"

class ConsumerParser
{
private:
  ProducterStream			&hamster;
  std::string				buffer;
  std::map<std::string, std::string>	capture;
public:
ConsumerParser(ProducterStream &);
inline bool peekChar(char c)
  {
    try
      {
	this->feedMe();
	if (this->buffer.at(0) != c)
	  return (false);
	else
	  return (true);
      }
    catch(...)
      {
	return (false);
      }
  }

inline bool readChar(char c)
  {
    if (!this->peekChar(c))
      return (false);
    else
      {
	this->record(c);
        this->buffer = this->buffer.substr(1, this->buffer.size());
        return (true);
      }
  }

inline bool readRange(char begin, char end)
  {
    char	c;

    try
      {
	this->feedMe();
	c = this->buffer.at(0);
	if (c >= begin && c <= end)
	  {
	    this->record(this->buffer.at(0));
	    this->buffer = this->buffer.substr(1, this->buffer.size());
	    return (true);
	  }
	else
	  return (false);
      }
    catch (...)
      {
	return (false);
      }
  }

bool readText(char *text);
bool readEOF();
bool readUntil(char c);
bool readUntilEOF();
bool readInteger();
bool readIdentifier();
  std::string getBuffer()
  {
    return this->buffer;
  }
inline bool beginCapture(std::string tag)
  {
    this->capture[tag] = "";
    return (true);
  }

inline bool endCapture(std::string tag, std::string& out)
  {
    out = this->capture[tag];
    this->capture[tag].erase();
    return (true);
  }

private:
inline void feedMe()
  {
    while (this->buffer.size() == 0)
      this->buffer = this->hamster.nextString();
  }
private:
  void	record(char c);
  void  reverse(int len);
};

#endif	/*	CONSUMERPARSER_HPP_	*/

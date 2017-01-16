#ifndef		PARSERZAPPYCLIENT_HPP_
# define	PARSERZAPPYCLIENT_HPP_

# include	"ConsumerParser.hpp"
# include	"ProducterStream.hpp"
# include       "Request.hpp"

class ParserZappyClient : public ConsumerParser
{
public:
  ParserZappyClient(ProducterStream &stream);
  bool	readRequest(Request &req);
private:
  bool	isAssert(Request &req);
  bool	isDead(Request &req);
  bool	isNumericList(Request &req);
  bool	isBienvenue(Request &req);
  bool	isInventoryOrView(Request &req);
  bool	isInventoryEntry(Request &req, std::string identifier);
  bool	isViewEntry(Request &req, std::string identifier);
};

#endif	/*	PARSERZAPPYCLIENT_HPP_	*/

#include	<sstream>

#include	"ParserZappyClient.hpp"

ParserZappyClient::ParserZappyClient(ProducterStream &stream)
  :ConsumerParser(stream)
{

}

bool	ParserZappyClient::readRequest(Request &req)
{
  std::string	test;
  this->beginCapture("debug");
  if (!isAssert(req)
      && !isDead(req)
      && !isNumericList(req)
      && !isBienvenue(req)
      && !isInventoryOrView(req))
    {
      this->readUntilEOF();
      this->endCapture("debug", test);
      std::cerr << "bad request : " << test << std::endl;
      return (false);
    }
  this->endCapture("debug", test);
  if (!readChar('\n'))
    {
      std::cerr << "request malformed" << std::endl;
      return (false);
    }
  std::cout << "received : " << test << std::endl;
  return (true);
}

bool	ParserZappyClient::isAssert(Request &req)
{
  if (this->readText((char *)"ok"))
    req.setType(REQ_ASSERT_OK);
  else if (this->readText((char *) "ko"))
    req.setType(REQ_ASSERT_KO);
  else
    return false;
  return (true);
}

bool	ParserZappyClient::isDead(Request &req)
{
  if (this->readText((char *)"mort"))
    {
      req.setType(REQ_DEATH);
      return (true);
    }
  return (false);
}

bool	ParserZappyClient::isNumericList(Request &req)
{
  std::string	numeric;
  this->beginCapture("numeric");
  if (this->readInteger())
    {
      req.setType(REQ_NUMERIC_LIST);
      this->endCapture("numeric", numeric);
      req.addNumeric(numeric);
      if (readChar(' '))
	this->isNumericList(req);
      return (true);
    }
  return (false);
}

bool	ParserZappyClient::isBienvenue(Request &req)
{
  req.setType(REQ_HELLO);
  return (this->readText((char *)"BIENVENUE"));
}

bool	ParserZappyClient::isInventoryOrView(Request &req)
{
  std::string	identifier;

  if (!readChar('{'))
    return (false);
  while (readChar(' '));
  while (!readChar('}'))
    {
      this->beginCapture("entry");
      this->readIdentifier();
      this->endCapture("entry", identifier);
      if (!isInventoryEntry(req, identifier))
	if (!isViewEntry(req, identifier))
	  return (false);
      while (readChar(' '));
      this->readChar(',');
    }
  return (true);
}

  bool    ParserZappyClient::isInventoryEntry(Request &req, std::string id)
{
  std::string		nb;
  std::stringstream	ss;
  int			res;

  while (this->readChar(' '));
  this->beginCapture("number");
  if (!this->readInteger())
    {
      this->endCapture("number", nb);
      return (false);
    }
  req.setType(REQ_INVENTORY);
  this->endCapture("number", nb);
  ss << nb;
  ss >> res;
  req.setInventoryEntry(id, res);
  return (true);
}

bool    ParserZappyClient::isViewEntry(Request &req, std::string id)
{
  (void)req;
  (void)id;
  req.setType(REQ_VIEW);
  return (true);
}

#include	<iostream>
#include	<string>
#include	<fstream>

#include	"Player.hh"
#include	"Network.hh"
#include	"Request.hh"
#include	"Parser.hh"

int	main()
{
  Socket	s(TCP);
  Request	req;
  ProducterStream stream;
  ParserZappyClient	parser(stream);
  Player        p(1, s, req, parser);
  std::fstream	streamIA("ZappyIADump.dot", std::fstream::out | std::fstream::trunc);

  streamIA << p.getIA();
  p.setLastRequest(req);
  s.init();
  s.connects("127.0.0.1", 3945);
  std::string   msg("toto\n");
  stream.loadSocket(s);
  s.sendData<char>(msg.c_str(), msg.length());
  stream.loadSocket(s);
  while (req.getType() != REQ_DEATH
	 && p.update());
  std::cout << "dead!" << std::endl;
  return (0);
}

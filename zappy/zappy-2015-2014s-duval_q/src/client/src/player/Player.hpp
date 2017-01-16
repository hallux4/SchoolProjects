#ifndef		PLAYER_HPP_
# define	PLAYER_HPP_

#include	<stdexcept>
#include	"Network.hh"
#include	"Entity.hh"
#include	"StateMachine.hh"
#include	"PlayerData.hh"
#include	"Request.hh"
#include	"Parser.hh"

class Player : public Entity
{
  Socket		&comm;
  Request               &lastRequest;
  ParserZappyClient	&parser;
  StateMachine<Player>	*sM;
  PlayerData		infos;
public:
  Player(int id, Socket &comm, Request &request, ParserZappyClient &parser);
  ~Player();
  bool	update();
  int	request(std::string &req);
  StateMachine<Player> &getIA();
  Request const   &getLastRequest() const;
  void		setLastRequest(Request &req);
};

#endif	/*	PLAYER_HPP	*/

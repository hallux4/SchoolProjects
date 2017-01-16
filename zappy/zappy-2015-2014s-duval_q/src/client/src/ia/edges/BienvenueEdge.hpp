#ifndef		BIENVENUEEDGE_HPP_
# define	BIENVENUEEDGE_HPP_

#include	"Edge.hh"
#include	"Request.hh"

class BienvenueEdge : public Edge<Player>
{
public:
  BienvenueEdge()
    :Edge<Player>(false, "server respond to connection")
  {

  }

  virtual bool operator()(Player const &player)
  {
    return (player.getLastRequest().getType() == REQ_HELLO);
  }
};

#endif	/*	BIENVENUEEDGE_HPP_	*/

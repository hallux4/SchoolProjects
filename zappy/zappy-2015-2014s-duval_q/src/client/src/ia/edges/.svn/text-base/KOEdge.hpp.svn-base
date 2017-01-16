#ifndef		KOEDGE_HPP_
# define	KOEDGE_HPP_

#include	"Request.hh"
#include	"Edge.hh"

class KOEdge : public Edge<Player>
{
public:
  KOEdge()
    :Edge<Player>(false, "Action failed")
  {
  }
  virtual bool operator()(Player const &player)
  {
    return (player.getLastRequest().getType() == REQ_ASSERT_KO);
  }
};

#endif	/*	KOEDGE_HPP_	*/

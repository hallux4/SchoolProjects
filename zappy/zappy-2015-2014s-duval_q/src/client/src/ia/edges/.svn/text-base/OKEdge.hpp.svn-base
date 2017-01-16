#ifndef		OKEDGE_HPP_
# define	OKEDGE_HPP_

#include	"Edge.hh"

class OKEdge : public Edge<Player>
{
public:
  OKEdge()
    :Edge<Player>(false, "Action success")
  {
  }

  virtual bool operator()(Player const &player)
  {
    return (player.getLastRequest().getType() == REQ_ASSERT_OK);
  }
};

#endif	/*	OKEDGE_HPP_	*/

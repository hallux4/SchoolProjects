#ifndef		NUMERICEDGE_HPP_
# define	NUMERICEDGE_HPP_

#include	"Request.hh"
#include	"Edge.hh"

class NumericEdge : public Edge<Player>
{
public:
  NumericEdge()
    :Edge<Player>(false, "server sent numerical response")
  {
  }

  virtual bool operator()(Player const &player)
  {
    return (player.getLastRequest().getType() == REQ_NUMERIC_LIST);
  }
};

#endif	/*	NUMERICEDGE_HPP_	*/

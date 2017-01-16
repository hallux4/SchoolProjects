#ifndef		FOREVEREDGE_HPP_
# define	FOREVEREDGE_HPP_

#include	"Edge.hh"

class ForeverEdge : public Edge<Player>
{
public:
  ForeverEdge()
    :Edge<Player>(false, "always")
  {
  }

  virtual bool operator()(Player const &player)
  {
    (void)player;
    
    return (true);
  }
};

#endif	/*	FOREVEREDGE_HPP_	*/

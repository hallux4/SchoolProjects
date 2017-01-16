#ifndef		COMPOSITEEDGE_HPP_
# define	COMPOSITEEDGE_HPP_

#include	<list>
#include	"Edge.hh"

enum edge_comportment
  {
    EDGE_AND,
    EDGE_OR
  };

template <typename T>
class CompositeEdge : public Edge<T>
{
private:
  edge_comportment		comportment;
  std::list<Edge<T> *>		edges;
public:
  
  CompositeEdge()
    :comportment(EDGE_AND)
  {
  }

  void	addEdge(Edge<T> *edge)
  {
    edges.push_back(edge);
  }

  void	isAndEdge()
  {
    this->comportment = EDGE_AND;
  }

  void	isOrEdge()
  {
    this->comportment = EDGE_OR;
  }

  virtual bool operator()(Player const &player)
  {
    bool	condition = (comportment == EDGE_AND);
    typename std::list<Edge<T> *>::iterator it;

    for ( it=edges.begin() ; it != edges.end(); it++ )
      {
	if (comportment == EDGE_AND)
	  condition = condition && (**it)(player);
	else if (comportment == EDGE_OR)
	  condition = condition || (**it)(player);
      }
    return (condition);
  }
};

#endif	/*	COMPOSITEEDGE_HPP_	*/

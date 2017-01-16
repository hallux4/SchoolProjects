#ifndef		RELATION_HPP_
# define	RELATION_HPP_

#include	"Edge.hpp"
#include	"State.hpp"

template <typename T>
class State;

template <typename T>
class Relation
{
private:
  Edge<T>		*edge;
  State<T>		*state;
public:
  Relation(Edge<T> *edge, State<T> *state)
    :edge(edge)
    ,state(state)
  {}
  
  bool	isMatching(T &data)
  {
    return ((*this->edge)(data));
  }

  State<T>	*getRelated()
  {
    return (this->state);
  }

  std::string const &getRelationName()
  {
    return (this->edge->getName());
  }
};

template <typename T>
std::fstream &operator<<(std::fstream &stream, Relation<T> const *state)
{
  stream << state->getRelationDescription()
	 << " [label="
	 << state->getRelated().getName()
	 << "];";
  return (stream);
}

#endif	/*	RELATION_HPP_	*/

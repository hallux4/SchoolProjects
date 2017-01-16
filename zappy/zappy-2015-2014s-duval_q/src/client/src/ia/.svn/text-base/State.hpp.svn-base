#ifndef		STATE_HPP_
# define	STATE_HPP_

#include	<list>
#include	<string>

#include	"Relation.hpp"

template <typename T>
class Relation;

template <typename T>
class State
{
private:
  bool				final;
  std::string			name;
  std::list<Relation<T> *>	links;
public:
  State(std::string const &name, bool final = false)
    :final(final)
    ,name(name)
  {}

  virtual ~State(){}

  bool	isFinal()
  {
    return (this->final);
  }

  std::list<Relation<T> *>	const &getLinks() const
  {
    return (this->links);
  }

  std::string const &getName() const
  {
    return (this->name);
  }

  void	addLink(Edge<T> *edge, State<T> *next)
  {
    Relation<T>	*rel = new Relation<T>(edge, next);
    this->links.push_back(rel);
  }

  State<T>	*getNextState(T *data)
  {
    typename
    std::list<Relation<T> *>::iterator linkIt = this->links.begin();

    while (linkIt != links.end())
      {
	if ((*linkIt)->isMatching(*data))
	  {
	    return ((*linkIt)->getRelated());
	  }
	linkIt++;
      }
    return (NULL);
  }

  virtual void begin(T *target) = 0;
  virtual void execute(T *target) = 0;
  virtual void end(T *target) = 0;
};

template <typename T>
std::fstream &operator<<(std::fstream &stream, State<T> const *state)
{
  typename std::list<Relation<T> *> const &links = state->getLinks();
  int	prio = 0;

  for (typename std::list<Relation<T> *>::const_iterator it = links.begin(); it != links.end(); it++)
    {
      std::cout << "    ->"
	        << (*it)->getRelated()->getName()
		<< " if "
		<< (*it)->getRelationName()
		<< std::endl; 
      stream << "\""
	     << state->getName()
	     << "\" -> \""
	     << (*it)->getRelated()->getName()
	     << "\" [label=\""
	     << (*it)->getRelationName()
	     <<" priority : "
	     << prio++
	     <<"\"]"
	     << std::endl;
    }
  return (stream);
}

#endif	/*	STATE_HPP_	*/

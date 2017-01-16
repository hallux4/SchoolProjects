#ifndef		EDGE_HPP_
# define	EDGE_HPP_

#include	<string>

template <typename T>
class	Edge
{
private:
  bool	lambdaEdge;
  std::string	name;
public:
  virtual ~Edge(){}
  Edge(bool lambda = false, std::string const &name = "unknow")
    :lambdaEdge(lambda)
    ,name(name)
  {}
  std::string const &getName() const
  {
    return (this->name);
  }
  virtual bool operator()(T const &data) = 0;
  bool isLambdaEdge(void) const
  {
    return (this->lambdaEdge);
  }
};

#endif

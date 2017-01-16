//
// Edge.cpp for  in /home/pincho_m//projet/rush/purgatory/etape3
// 
// Made by mathieu pinchon
// Login   <pincho_m@epitech.net>
// 
// Started on  Sat Dec 15 17:17:26 2012 mathieu pinchon
// Last update Sat Dec 15 23:11:25 2012 mathieu pinchon
//

#ifndef	EDGE_HPP
#define EDGE_HPP

class Edge
{
  char	val;
public:
  Edge(const char c)
  {
    val = c;
  }
  ~Edge()
  {
  }

  template<typename T>
  void	add(T& conteneur) const
  {
    conteneur.assign(val);
  }

  bool	compare(const char c) const
  {
    if (c == val)
      return true;
    return false;
  }
 
  bool	operator==(const char c) const
  {
    if (c == val)
      return (true);
    return false;
  }

  bool	operator==(const Edge& enter) const
  {
    return (enter.compare(val));
  } 

  bool	operator()(const char c) const
  {
    if (c == val)
      return (true);
    return false;
  }
};

#endif

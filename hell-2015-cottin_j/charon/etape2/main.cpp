//
// main.cpp for  in /home/pincho_m//projet/rush/hell/etape1
// 
// Made by mathieu pinchon
// Login   <pincho_m@epitech.net>
// 
// Started on  Fri Dec 14 20:00:44 2012 mathieu pinchon
// Last update Sat Dec 15 17:59:48 2012 mathieu pinchon
//

#include	<string>
#include	<iostream>
#include	<boost/bind.hpp>
#include	"Function.hpp"

class retest
{
public:
  retest()
    {
    }
  ~retest()
  {
  }
  void	operator()(const char c) const
  {
    std::cout << "second objet " << c << std::endl;
  }
};

class test
{
public:
  test()
  {
  }
  ~test()
  {
  }
  void	operator()(const char c) const
  {
    std::cout << "premier object " << c << std::endl;
  }
};

int	second(const char c)
{
  std::cout << "Seconde " << c << std::endl;
  return (0);
}

int	onefunction(const char c)
{
  std::cout << "first " <<c << std::endl;
  return (0);
}

int	main()
{
  Function<int (char)> f = &onefunction;
  Function<int (char)> c = boost::bind(&onefunction, _1);
  test	toto;
  retest titi;
  Function<void (char)> i = toto;
  f('c');
  c('o');
  i('u');
  f = &second;
  c = boost::bind(&second, _1);
  i = titi;
  f('c');
  c('o');
  i('u');
}

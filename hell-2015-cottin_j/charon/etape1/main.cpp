//
// main.cpp for  in /home/pincho_m//projet/rush/hell/etape1
// 
// Made by mathieu pinchon
// Login   <pincho_m@epitech.net>
// 
// Started on  Fri Dec 14 20:00:44 2012 mathieu pinchon
// Last update Sat Dec 15 17:56:06 2012 mathieu pinchon
//

#include	<string>
#include	<iostream>
#include "FunctionSignature.hpp"

int	fiftFunction(const std::string& test, const int a, const char c, const char e)
{
  std::cout << "test avec 4 param " << test << " " << a << " " << c << e << std::endl;
  return 0;
}

int	fourthfunction(const std::string& test, const int a, const char c)
{
  std::cout << "test avec 3 param " << test << " " << a << " " << c << std::endl;
  return 0;
}

int	thirdfunction(const std::string& test, const int a)
{
  std::cout << "test avec 2 param " << test << " " << a << std::endl;
  return 0;
}

int	secondfunction(const std::string& test)
{
  std::cout << "test avec 1 parametre " << test << std::endl;
  return 0;
}

int	onefunction()
{
  std::cout << "test sans parametre" <<std::endl;
  return 0;
}

int	main()
{
  FunctionSignature<int (void)>::type a = &onefunction;
  FunctionSignature<int (const std::string& test)>::type b = &secondfunction;
  FunctionSignature<int (const std::string& test, int a)>::type c = &thirdfunction;
  FunctionSignature<int (const std::string& , int, char)>::type d = &fourthfunction;
  FunctionSignature<int (const std::string& , int, char, char)>::type e = &fiftFunction;
  a();
  b("coucou");
  c("re coucou", 42);
  d("re coucou", 42, 'a');
  e("re coucou", 42, 'a', 'b');
  return 0;
}

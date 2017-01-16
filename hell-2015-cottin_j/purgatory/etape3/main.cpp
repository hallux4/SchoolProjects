//
// main.cpp for  in /home/pincho_m//projet/rush/purgatory/etape1
// 
// Made by mathieu pinchon
// Login   <pincho_m@epitech.net>
// 
// Started on  Sat Dec 15 14:41:31 2012 mathieu pinchon
// Last update Sun Dec 16 01:31:55 2012 mathieu pinchon
//

#include	<iostream>
#include	<string>
#include	"Matcher.hpp"

int	main(int ac, char **av)
{
  FSA	machine;
  Matcher	match(machine);

  match.find("");
  match.find("mecmechant");
  match.find("echant");
  match.find("mechant");
  match.find("hhmechantegewg");
}

//
// Machine.hpp for  in /home/pincho_m//projet/rush/purgatory/etape1
// 
// Made by mathieu pinchon
// Login   <pincho_m@epitech.net>
// 
// Started on  Sat Dec 15 10:42:40 2012 mathieu pinchon
// Last update Sat Dec 15 16:33:01 2012 mathieu pinchon
//

#ifndef	MACHINE_HPP
#define MACHINE_HPP

#define STATE_MAX 8
#define	EDGE_MAX  8

enum eState
  {
    S0 = 0,
    S1 = 1,
    S2 = 2,
    S3 = 3,
    S4 = 4,
    S5 = 5,
    S6 = 6,
    S7 = 7,
    STATE_ERROR = 8
  };

enum eAction
  {
    MA,
    HR,
    ACTION_ERROR
  };

extern enum eAction gActionTable[STATE_MAX][STATE_MAX];
extern enum eState gStateTable[EDGE_MAX][EDGE_MAX];


#endif

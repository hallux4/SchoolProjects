//
// Machine.cpp for  in /home/pincho_m//projet/rush/purgatory/etape1
// 
// Made by mathieu pinchon
// Login   <pincho_m@epitech.net>
// 
// Started on  Sat Dec 15 10:56:57 2012 mathieu pinchon
// Last update Sat Dec 15 17:13:49 2012 mathieu pinchon
//

#include	"Machine.hpp"




enum eAction gActionTable[STATE_MAX][STATE_MAX] = {
{MA          , ACTION_ERROR ,  ACTION_ERROR ,  ACTION_ERROR,  ACTION_ERROR,  ACTION_ERROR ,  ACTION_ERROR,  ACTION_ERROR},
{ACTION_ERROR, MA           ,  ACTION_ERROR ,  ACTION_ERROR,  ACTION_ERROR,  ACTION_ERROR ,  ACTION_ERROR,  ACTION_ERROR},
{ACTION_ERROR, MA           ,  MA           ,  ACTION_ERROR,  ACTION_ERROR,  ACTION_ERROR ,  ACTION_ERROR,  ACTION_ERROR},
{ACTION_ERROR, ACTION_ERROR ,  ACTION_ERROR ,  MA          ,  ACTION_ERROR,  ACTION_ERROR ,  ACTION_ERROR,  ACTION_ERROR},
{ACTION_ERROR, ACTION_ERROR ,  ACTION_ERROR ,  ACTION_ERROR,  MA          ,  ACTION_ERROR ,  ACTION_ERROR,  ACTION_ERROR},
{ACTION_ERROR, ACTION_ERROR ,  ACTION_ERROR ,  ACTION_ERROR,  ACTION_ERROR,  MA           ,  ACTION_ERROR,  ACTION_ERROR},
{ACTION_ERROR, ACTION_ERROR ,  ACTION_ERROR ,  ACTION_ERROR,  ACTION_ERROR,  ACTION_ERROR ,  MA          ,  ACTION_ERROR},
{HR          , HR           ,  HR           ,  HR          ,  HR          ,  HR           ,  HR          , HR}
};

enum eState gStateTable[EDGE_MAX][EDGE_MAX] ={
  {S1         , STATE_ERROR, STATE_ERROR, STATE_ERROR, STATE_ERROR, STATE_ERROR, STATE_ERROR, STATE_ERROR},
  {STATE_ERROR,		 S2, STATE_ERROR, STATE_ERROR, STATE_ERROR, STATE_ERROR, STATE_ERROR, STATE_ERROR},
  {STATE_ERROR,          S2,	      S3, STATE_ERROR, STATE_ERROR, STATE_ERROR, STATE_ERROR, STATE_ERROR},
  {STATE_ERROR, STATE_ERROR, STATE_ERROR,	   S4, STATE_ERROR, STATE_ERROR, STATE_ERROR, STATE_ERROR},
  {STATE_ERROR, STATE_ERROR, STATE_ERROR, STATE_ERROR,		S5, STATE_ERROR, STATE_ERROR, STATE_ERROR},
  {STATE_ERROR, STATE_ERROR, STATE_ERROR, STATE_ERROR, STATE_ERROR, S6	       , STATE_ERROR, STATE_ERROR},
  {STATE_ERROR, STATE_ERROR, STATE_ERROR, STATE_ERROR, STATE_ERROR, STATE_ERROR, S7	    , STATE_ERROR},
  {STATE_ERROR, STATE_ERROR, STATE_ERROR, STATE_ERROR, STATE_ERROR, STATE_ERROR, STATE_ERROR, STATE_ERROR}
};

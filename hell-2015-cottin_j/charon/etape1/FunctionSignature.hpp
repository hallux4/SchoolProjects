//
// FunctionSignature.hpp for  in /home/pincho_m//projet/rush/hell/etape1
// 
// Made by mathieu pinchon
// Login   <pincho_m@epitech.net>
// 
// Started on  Fri Dec 14 19:42:49 2012 mathieu pinchon
// Last update Sat Dec 15 00:12:05 2012 mathieu pinchon
//

#ifndef	FUCTIONSIGNATURE_HPP
#define FUCTIONSIGNATURE_HPP

template<typename T>
class FunctionSignature;

template<typename T>
struct FunctionSignature <T()>
{
  typedef T (*type)();

  FunctionSignature()
  {
  }
  ~FunctionSignature()
  {
  }
};

template<typename T, typename arg1>
struct FunctionSignature <T(arg1)>
{
  typedef T (*type)(arg1);

  FunctionSignature()
  {
  }
  ~FunctionSignature()
  {
  }
};

template<typename T, typename arg1, typename arg2>
struct FunctionSignature <T(arg1, arg2)>
{
  typedef T (*type)(arg1, arg2);

  FunctionSignature()
  {
  }

  ~FunctionSignature()
  {
  }
};

template<typename T, typename arg1, typename arg2, typename arg3>
struct FunctionSignature <T(arg1, arg2, arg3)>
{
  typedef T (*type)(arg1, arg2, arg3);

  FunctionSignature()
  {
  }

  ~FunctionSignature()
  {
  }
};

template<typename T, typename arg1, typename arg2, typename arg3, typename arg4>
struct FunctionSignature <T(arg1, arg2, arg3, arg4)>
{
  typedef T (*type)(arg1, arg2, arg3, arg4);

  FunctionSignature()
  {
  }

  ~FunctionSignature()
  {
  }
};

#endif

/* 
 * File:   Stack.cpp
 * Author: lukior
 * 
 * Created on 9 février 2012, 16:59
 */

#include <iostream>
#include "Stack.hpp"
#include "error.hpp"

Stack::Stack()
{
}

Stack::~Stack()
{
  IOperand* tmp;
  while (!mem.empty())
    {
      tmp = mem.back();
      mem.pop_back();
      delete tmp;
    }
}

IOperand* Stack::pop()
{
  if (mem.empty() == true)
    throw error("stack is empty");
  IOperand *tmp = mem.back();
  mem.pop_back();
  return tmp;
}

void Stack::push(IOperand* item)
{
  mem.push_back(item);
}

long unsigned int Stack::getSize()
{
  return mem.size();
}

void printElem(IOperand* elem)
{
  std::cout << elem->toString() << std::endl;
}

void Stack::dump()
{
  std::for_each(mem.rbegin(), mem.rend(), printElem);
}

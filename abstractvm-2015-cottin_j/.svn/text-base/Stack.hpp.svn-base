/* 
 * File:   Stack.h
 * Author: lukior
 *
 * Created on 9 février 2012, 16:59
 */

#ifndef STACK_H
#define	STACK_H

#include  <deque>
#include  <algorithm>
#include  <iostream>
#include  "IStack.hpp"

class   Stack
:public IStack
{
public:
 Stack();
 virtual ~Stack();

 virtual void push(IOperand *);
 virtual IOperand * pop();
 virtual void       dump();
 virtual long unsigned int getSize();
 
private:
 std::deque<IOperand *>  mem;
 
};

#endif	/* STACK_H */


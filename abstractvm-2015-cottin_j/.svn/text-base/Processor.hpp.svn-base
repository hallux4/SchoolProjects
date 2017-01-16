/* 
 * File:   Processor.hpp
 * Author: lukior
 *
 * Created on 12 février 2012, 12:02
 */

#ifndef PROCESSOR_HPP
#define	PROCESSOR_HPP

#include  "IStack.hpp"
#include  "IOperand.hpp"

class   Processor
{
private:
 IStack*  memory;

 IOperand*  createOperand(const eOperandType&, const std::string &);
public:
 Processor();
 ~Processor();

 void push(eOperandType, std::string);
 void pop();
 void dump();
 void assert(eOperandType, std::string);
 void add();
 void sub();
 void mul();
 void div();
 void mod();
 void print();
 void endOfProgram();
};

#endif	/* PROCESSOR_HPP */


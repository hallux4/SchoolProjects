/* 
 * File:   IOperand.hpp
 * Author: lukior
 *
 * Created on 9 février 2012, 16:11
 */

#ifndef IOPERAND_HPP
#define	IOPERAND_HPP

#include  <sstream>
#include  <string>
#include  <cstdlib>

enum  eOperandType
{
 INT8,
 INT16,
 INT32,
 FLOAT,
 DOUBLE
};

class IOperand
{
public:
  virtual ~IOperand() {}

  virtual std::string const toString() const = 0;
  
  virtual int       getPrecision() const = 0;
  virtual const eOperandType & getType() const = 0;
  
  virtual IOperand* operator+(IOperand &) const = 0;
  virtual IOperand* operator-(IOperand &) const = 0;
  virtual IOperand* operator/(IOperand &) const = 0;
  virtual IOperand* operator*(IOperand &) const = 0;
  virtual IOperand* operator%(IOperand &) const = 0;
};

#endif	/* IOPERAND_HPP */

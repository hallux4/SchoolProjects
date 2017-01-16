/* 
 * File:   Operand.hpp
 * Author: lukior
 *
 * Created on 9 février 2012, 18:43
 */

#ifndef OPERAND_HPP
#define	OPERAND_HPP

#include  <cmath>
#include  "IOperand.hpp"

template<typename T>
class   Operand
:public IOperand
{
 private:
  T     value;
  eOperandType  type;

 public:
  Operand(eOperandType _type, T  _value)
    :type(_type), value(_value)
  {
  }
  
  virtual ~Operand()
  {
  }
  
  std::string const toString() const
  {
    std::stringstream ss;
    ss << value;
    return ss.str();
  }
  
  virtual int getPrecision() const
  {
    return (int)type;
  }
  
  virtual const eOperandType &  getType() const
  {
    return type;
  }
  
  IOperand*   operator+(IOperand & ref) const
  {
    T      nbr;
    std::stringstream ss(ref.toString());
    ss >> nbr;
    return (new Operand(this->getType(), value + nbr));
  }
  
  IOperand*   operator-(IOperand & ref) const
  {
    T      nbr;
    std::stringstream ss(ref.toString());
    ss >> nbr;
    return (new Operand(this->getType(), value - nbr));
  }
  
  IOperand*   operator*(IOperand & ref) const
  {
    T      nbr;
    std::stringstream ss(ref.toString());
    ss >> nbr;
    return (new Operand(this->getType(), value * nbr));
  }
  
  IOperand*   operator/(IOperand & ref) const
  {
    T      nbr;
    std::stringstream ss(ref.toString());
    ss >> nbr;
    return (new Operand(this->getType(), value / nbr));
  }

  IOperand*   operator%(IOperand & ref) const
  {
    T      nbr;
    std::stringstream ss(ref.toString());
    ss >> nbr;
    return (new Operand(this->getType(), fmod(value, nbr)));
  }
};

#endif	/* OPERAND_HPP */

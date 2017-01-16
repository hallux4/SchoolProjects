
#include  "Processor.hpp"
#include "IStack.hpp"
#include  "Operand.hpp"
#include  "Stack.hpp"
#include	"error.hpp"

Processor::Processor()
{
  this->memory = new Stack;
}

Processor::~Processor()
{
  delete memory;
}

void	Processor::push(eOperandType type, std::string value)
{
  memory->push(createOperand(type, value));
}

void	Processor::pop()
{
  delete memory->pop();
}

void	Processor::dump()
{
  memory->dump();
}

void	Processor::assert(eOperandType type, std::string value)
{
  IOperand* tmp = memory->pop();
  if (type != tmp->getType() || value != tmp->toString())
    throw error("assert instruction return false");
  memory->push(tmp);
}

void	Processor::add()
{
  if (memory->getSize() < 2)
    throw error("not enough operands in stack");

  IOperand* operand1 = memory->pop();
  IOperand* operand2 = memory->pop();
  IOperand* tmp;

  if (operand2->getPrecision() < operand1->getPrecision())
    {
      tmp = createOperand(operand1->getType(), operand2->toString());
      delete operand2;
      operand2 = tmp;
    }
  else if (operand2->getPrecision() > operand1->getPrecision())
    {
      tmp = createOperand(operand2->getType(), operand1->toString());
      delete operand1;
      operand1 = tmp;
    }

  IOperand* result = (*operand2 + *operand1);

  delete operand1;
  delete operand2;

  memory->push(result);
}

void	Processor::sub()
{
  if (memory->getSize() < 2)
    throw error("not enough operands in stack");
  IOperand* operand1 = memory->pop();
  IOperand* operand2 = memory->pop();
  IOperand* tmp;

  if (operand2->getPrecision() < operand1->getPrecision())
    {
      tmp = createOperand(operand1->getType(), operand2->toString());
      delete operand2;
      operand2 = tmp;
    }
  else if (operand2->getPrecision() > operand1->getPrecision())
    {
      tmp = createOperand(operand2->getType(), operand1->toString());
      delete operand1;
      operand1 = tmp;
    }

  IOperand* result = (*operand2 - *operand1);

  delete operand1;
  delete operand2;

  memory->push(result);
}

void	Processor::mul()
{
  if (memory->getSize() < 2)
    throw error("not enough operands in stack");
  IOperand* operand1 = memory->pop();
  IOperand* operand2 = memory->pop();
  IOperand* tmp;

  if (operand2->getPrecision() < operand1->getPrecision())
    {
      tmp = createOperand(operand1->getType(), operand2->toString());
      delete operand2;
      operand2 = tmp;
    }
  else if (operand2->getPrecision() > operand1->getPrecision())
    {
      tmp = createOperand(operand2->getType(), operand1->toString());
      delete operand1;
      operand1 = tmp;
    }

  IOperand* result = (*operand2 * *operand1);

  delete operand1;
  delete operand2;

  memory->push(result);
}

void	Processor::div()
{
  if (memory->getSize() < 2)
    throw error("not enough operands in stack");
  IOperand* operand1 = memory->pop();
  IOperand* operand2 = memory->pop();
  IOperand* tmp;

  if (!operand1->toString().compare("0"))
    throw error("DO NOT DIVIDE BY ZERO!!\n");
  if (operand2->getPrecision() < operand1->getPrecision())
    {
      tmp = createOperand(operand1->getType(), operand2->toString());
      delete operand2;
      operand2 = tmp;
    }
  else if (operand2->getPrecision() > operand1->getPrecision())
    {
      tmp = createOperand(operand2->getType(), operand1->toString());
      delete operand1;
      operand1 = tmp;
    }

  IOperand* result = (*operand2 / *operand1);

  delete operand1;
  delete operand2;

  memory->push(result);
}

void	Processor::mod()
{
  if (memory->getSize() < 2)
    throw error("not enough operands in stack\n");
  IOperand* operand1 = memory->pop();
  IOperand* operand2 = memory->pop();
  IOperand* tmp;

  if (!operand1->toString().compare("0"))
    throw error("DO NOT DIVIDE BY ZERO!!\n");
  if (operand2->getPrecision() < operand1->getPrecision())
    {
      tmp = createOperand(operand1->getType(), operand2->toString());
      delete operand2;
      operand2 = tmp;
    }
  else if (operand2->getPrecision() > operand1->getPrecision())
    {
      tmp = createOperand(operand2->getType(), operand1->toString());
      delete operand1;
      operand1 = tmp;
    }

  IOperand* result = (*operand2 % *operand1);

  delete operand1;
  delete operand2;

  memory->push(result);
}

IOperand* Processor::createOperand(const eOperandType & type, const std::string & value)
{
  switch (type)
    {
    case INT8:
      return new Operand<char>(type, atoi(value.c_str()));
    case INT16:
      return new Operand<short>(type, atoi(value.c_str()));
    case INT32:
      return new Operand<int>(type, atoi(value.c_str()));
    case FLOAT:
      return new Operand<float>(type, atof(value.c_str()));
    case DOUBLE:
      return new Operand<double>(type, atof(value.c_str()));
    }
  return NULL;
}

void Processor::print()
{
  IOperand* tmp = memory->pop();

  if (tmp->getType() != INT8)
    throw error("operand not of type Int8");
  std::cout << tmp->toString().c_str() << std::endl;
  memory->push(tmp);
}

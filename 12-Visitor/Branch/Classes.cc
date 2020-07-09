#include "Classes.h"

Interpreter::Interpreter()
{
  std::cout << "Interpreter.constructor()" << std::endl;
};

Interpreter::~Interpreter()
{
  std::cout << "Interpreter.destructor()" << std::endl;
};

Number::Number(int value_):
  value(value_)
{
  std::cout << "Number.constructor()" << std::endl;
};

Number::~Number()
{
  std::cout << "Number.destructor()" << std::endl;
};

int Number::evaluate()
{
  return(value);
};

int Number::getValue()
{
  return(value);
};

void Number::print(Visitor *visitor)
{
  visitor->printNumber(this);
};

Sum::Sum(Interpreter *left_, Interpreter *right_):
  left(left_), right(right_)
{
  std::cout << "Sum.constructor()" << std::endl;
};

Sum::~Sum()
{
  std::cout << "Sum.destructor()" << std::endl;
};

int Sum::evaluate()
{
  return(left->evaluate() + right->evaluate());
};

void Sum::print(Visitor *visitor)
{
  visitor->printSum(this);
};

Interpreter * Sum::getLeft()
{
  return(left);
};

Interpreter * Sum::getRight()
{
  return(right);
};

Subtraction::Subtraction(Interpreter *left_, Interpreter *right_):
  left(left_), right(right_)
{
  std::cout << "Subtraction.constructor()" << std::endl;
};

Subtraction::~Subtraction()
{
  std::cout << "Subtraction.destructor()" << std::endl;
};

int Subtraction::evaluate()
{
  return(left->evaluate() - right->evaluate());
};

void Subtraction::print(Visitor *visitor)
{
  visitor->printSubtraction(this);
};

Interpreter * Subtraction::getLeft()
{
  return(left);
};

Interpreter * Subtraction::getRight()
{
  return(right);
};

Visitor::Visitor()
{
  std::cout << "Visitor.constructor()" << std::endl;
};

Visitor::~Visitor()
{
  std::cout << "Visitor.destructor()" << std::endl;
};
  
void Visitor::printNumber(Number *number)
{
  std::cout << number->getValue();
};

void Visitor::printSum(Sum *sum)
{
  std::cout << "(";

  sum->getLeft()->print(this);
  
  std::cout << " + ";

  sum->getRight()->print(this);
    
  std::cout << ")";
};

void Visitor::printSubtraction(Subtraction *subtraction)
{
  std::cout << "(";

  subtraction->getLeft()->print(this);
  
  std::cout << " - ";

  subtraction->getRight()->print(this);
    
  std::cout << ")";
};

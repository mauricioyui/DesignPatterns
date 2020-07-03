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

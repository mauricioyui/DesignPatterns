#include "Constants.h"
#include "Classes.h"

Context::Context(int value_): value(value_)
{
  std::cout << "Context.constructor(): assign context.value = " << value << std::endl;
};

Context::~Context()
{
  std::cout << "Context.destructor()" << std::endl;
};

int Context::getValue()
{
  return(value);
};

Decorator::Decorator(): next(NULL)
{
  std::cout << "Decorator.constructor(): default" << std::endl;
};

Decorator::Decorator(Decorator *next_): next(next_)
{
  std::cout << "Decorator.constructor(): assign next" << std::endl;
};

Decorator::~Decorator()
{
  std::cout << "Decorator.destructor()" << std::endl;
};

Decorator1::Decorator1(): Decorator()
{
  std::cout << "Decorator1.constructor(): default" << std::endl;
};

Decorator1::Decorator1(Decorator *next_): Decorator(next_)
{
  std::cout << "Decorator1.constructor(): assign next" << std::endl;
};

Decorator1::~Decorator1()
{
  std::cout << "Decorator1.destructor()" << std::endl;
};

int Decorator1::run(Context &context)
{
  if(next == NULL)
    return(10);

  return(context.getValue() * 10 + next->run(context));
}

Decorator2::Decorator2(): Decorator()
{
  std::cout << "Decorator2.constructor(): default" << std::endl;
};

Decorator2::Decorator2(Decorator *next_): Decorator(next_)
{
  std::cout << "Decorator2.constructor(): assign next" << std::endl;
};

Decorator2::~Decorator2()
{
  std::cout << "Decorator2.destructor()" << std::endl;
};

int Decorator2::run(Context &context)
{
  if(next == NULL)
    return(20);

  return(context.getValue() * 20 + next->run(context));
}

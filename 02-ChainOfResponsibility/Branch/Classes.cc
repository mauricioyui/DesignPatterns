#include <iostream>

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

Chain::Chain(): next(NULL)
{
  std::cout << "Chain.constructor()" << std::endl;
};

Chain::~Chain()
{
  std::cout << "Chain.destructor()" << std::endl;
};

Chain1::Chain1()
{
  std::cout << "Chain1.constructor()" << std::endl;
};

Chain1::~Chain1()
{
  std::cout << "Chain1.destructor()" << std::endl;
};

void Chain1::run(Context &context)
{
  if(context.getValue() < 10)
    std::cout << "Chain1.run(): context.getValue() is less than 10" << std::endl;
  else if(next != NULL)
    next->run(context);
  else
    std::cout << "Chain1.run(): context.getValue() is equal or more than 10" << std::endl;
};

void Chain1::setNext(Chain *next_)
{
  next = next_;
};

Chain2::Chain2()
{
  std::cout << "Chain2.constructor()" << std::endl;
};

Chain2::~Chain2()
{
  std::cout << "Chain2.destructor()" << std::endl;
};

void Chain2::run(Context &context)
{
  if(context.getValue() < 20)
    std::cout << "Chain2.run(): context.getValue() is less than 20" << std::endl;
  else if(next != NULL)
    next->run(context);
  else
    std::cout << "Chain2.run(): context.getValue() is equal or more than 20" << std::endl;
};

void Chain2::setNext(Chain *next_)
{
  next = next_;
};

Analyzer::Analyzer()
{
  std::cout << "Analyzer.constructor()" << std::endl;
};

Analyzer::~Analyzer()
{
  std::cout << "Analyzer.destructor()" << std::endl;
};

void Analyzer::run(Context &context)
{
  Chain1 chain1;
  Chain2 chain2;

  chain1.setNext(&chain2);

  std::cout << std::endl;
  chain1.run(context);
  std::cout << std::endl;
};

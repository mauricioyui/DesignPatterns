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

Benchmark::Benchmark()
{
  std::cout << "Benchmark.constructor()" << std::endl;
};

Benchmark::~Benchmark()
{
  std::cout << "Benchmark.destructor()" << std::endl;
};

BenchmarkTemplate::BenchmarkTemplate()
{
  std::cout << "BenchmarkTemplate.constructor()" << std::endl;
};

BenchmarkTemplate::~BenchmarkTemplate()
{
  std::cout << "BenchmarkTemplate.destructor()" << std::endl;
};

void BenchmarkTemplate::run(Context &context)
{
  std::cout << "BenchmarkTemplate.run()" << std::endl;
  if(condition(context))
    return(process1(context));
  else
    return(process2(context));
};

Benchmark1::Benchmark1()
{
  std::cout << "Benchmark1.constructor()" << std::endl;
};

Benchmark1::~Benchmark1()
{
  std::cout << "Benchmark1.destructor()" << std::endl;
};

bool Benchmark1::condition(Context &context)
{
  if(context.getValue() < STANDARD1)
    return(true);

  return(false);
};

void Benchmark1::process1(Context &context)
{
  std::cout << "Benchmark1.process1(): context.getValue() is "
            << context.getValue()
            << " which is less than "
            << STANDARD1
            << std::endl;
};

void Benchmark1::process2(Context &context)
{
  std::cout << "Benchmark1.process2(): context.getValue() is "
            << context.getValue()
            << " which is equal or greater than "
            << STANDARD1
            << std::endl;
};

Benchmark2::Benchmark2()
{
  std::cout << "Benchmark2.constructor()" << std::endl;
};

Benchmark2::~Benchmark2()
{
  std::cout << "Benchmark2.destructor()" << std::endl;
};

void Benchmark2::easterEgg(Context &context)
{
  std::cout << "Benchmark2.specialCondition(): context.getValue() is "
            << context.getValue()
            << " which is equal to the MAGIC VALUE "
            << MAGICVALUE
            << std::endl;
};

bool Benchmark2::condition(Context &context)
{
  if(context.getValue() < STANDARD2)
    return(true);

  return(false);
};

void Benchmark2::process1(Context &context)
{
  std::cout << "Benchmark2.process1(): context.getValue() is "
            << context.getValue()
            << " which is less than "
            << STANDARD2
            << std::endl;
};

void Benchmark2::process2(Context &context)
{
  if(context.getValue() == MAGICVALUE)
    easterEgg(context);
  else
    std::cout << "Benchmark2.process2(): context.getValue() is "
              << context.getValue()
              << " which is equal or greater than "
              << STANDARD2
              << std::endl;
};

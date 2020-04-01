#include "Classes.h"
#include "Constants.h"

Context::Context(int value_): value(value_)
{
  std::cout << "Context.constructor(): assign context.value = " << value << std::endl;
}

Context::~Context()
{
  std::cout << "Context.destructor()" << std::endl;
}

int Context::getValue()
{
  return(value);
}

Strategy::Strategy()
{
  std::cout << "Strategy.constructor()" << std::endl;
}

Strategy::~Strategy()
{
  std::cout << "Strategy.destructor()" << std::endl;
}

Strategy1::Strategy1()
{
  std::cout << "Strategy1.constructor()" << std::endl;
}

Strategy1::~Strategy1()
{
  std::cout << "Strategy1.destructor()" << std::endl;
}

void Strategy1::run(Context &context)
{
  std::cout << "Strategy1.run(): context.getValue() * 1 = "
            << context.getValue() * FACTOR1
            << std::endl;
};

Strategy2::Strategy2()
{
  std::cout << "Strategy2.constructor()" << std::endl;
}

Strategy2::~Strategy2()
{
  std::cout << "Strategy2.destructor()" << std::endl;
}

void Strategy2::run(Context &context)
{
  std::cout << "Strategy2.run(): context.getValue() * 2 = "
            << context.getValue() * FACTOR2
            << std::endl;
};

Strategy3::Strategy3()
{
  std::cout << "Strategy3.constructor()" << std::endl;
}

Strategy3::~Strategy3()
{
  std::cout << "Strategy3.destructor()" << std::endl;
}

void Strategy3::run(Context &context)
{
  std::cout << "Strategy3.run(): context.getValue() * 3 = "
            << context.getValue() * FACTOR3
            << std::endl;
};

Linker::Linker()
{
  std::cout << "Linker.constructor()" << std::endl;
}

Linker::~Linker()
{
  std::cout << "Linker.destructor()" << std::endl;
}

void Linker::run(Context &context, Strategy *strategy)
{
  std::cout << "Linker.run()" << std::endl;
  strategy->run(context);
};

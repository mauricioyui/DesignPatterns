#include "Classes.h"

Context::Context(int id_):
  id(id_)
{
  std::cout << "Context.constructor()" << std::endl;
};

Context::~Context()
{
  std::cout << "Context.destructor()" << std::endl;
};

int Context::getId()
{
  std::cout << "Context.getId()" << std::endl;
  std::cout << "  id: " << id << std::endl;
  return(id);
};

ContextFactory::ContextFactory():
  idGenerator(0)
{
  std::cout << "ContextFactory.constructor()" << std::endl;
};

ContextFactory::~ContextFactory()
{
  std::cout << "ContextFactory.destructor()" << std::endl;
};

Context * ContextFactory::getContext()
{
  Context *context = new Context(++idGenerator);
  return(context);
};

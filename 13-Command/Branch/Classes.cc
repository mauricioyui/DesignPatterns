#include "Classes.h"

Context::Context():
  status(NEW)
{
  std::cout << "Context.constructor()" << std::endl;
};

Context::~Context()
{
  std::cout << "Context.destructor()" << std::endl;
};

void Context::process()
{
  std::cout << "Context.process()" << std::endl;
  status = PROCESS;
};

void Context::finish()
{
  std::cout << "Context.finish()" << std::endl;
  status = FINISH;
};

Status Context::getStatus()
{
  return(status);
};

Command::Command()
{
  std::cout << "Command.constructor()" << std::endl;
};

Command::~Command()
{
  std::cout << "Command.destructor()" << std::endl;
};


ProcessContext::ProcessContext(Context *context_):
  context(context_)
{
  std::cout << "ProcessContext.constructor()" << std::endl;
};

ProcessContext::~ProcessContext()
{
  std::cout << "ProcessContext.destructor()" << std::endl;
};

void ProcessContext::run()
{
  std::cout << "ProcessContext.run()" << std::endl;
  context->process();
};

FinishContext::FinishContext(Context *context_):
  context(context_)
{
  std::cout << "FinishContext.constructor()" << std::endl;
};

FinishContext::~FinishContext()
{
  std::cout << "FinishContext.destructor()" << std::endl;
};

void FinishContext::run()
{
  std::cout << "FinishContext.run()" << std::endl;
  context->finish();
};

ContextContainer::ContextContainer()
{
  std::cout << "ContextContainer.constructor()" << std::endl;
};

ContextContainer::~ContextContainer()
{
  std::cout << "ContextContainer.destructor()" << std::endl;
  for(std::vector<Command*>::iterator it = commandsList.begin(); it != commandsList.end(); it++)
  {
    delete(*it);
  }
};

void ContextContainer::add(Command *command)
{
  std::cout << "ContextContainer.add()" << std::endl;
  commandsList.push_back(command);
};

void ContextContainer::process()
{
  std::cout << "ContextContainer.process()" << std::endl;
  for(std::vector<Command*>::iterator it = commandsList.begin(); it != commandsList.end(); it++)
  {
    (*it)->run();
  }
};

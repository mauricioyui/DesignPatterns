#include "Classes.h"

Context::Context(int intAttribute_, float floatAttribute_, 
  std::string stringAttribute_):
  intAttribute(intAttribute_), floatAttribute(floatAttribute_), 
  stringAttribute(stringAttribute_)
{
  std::cout << "Context.constructor():" << std::endl;
  
  std::cout << "  Create all startup actions: " << std::endl;  
  std::vector<StartupActions*> startupActions;
  StartupAction1 startupAction1;
  StartupAction2 startupAction2;
  StartupAction3 startupAction3;
  
  startupActions.push_back(&startupAction1);
  startupActions.push_back(&startupAction2);
  startupActions.push_back(&startupAction3);

  std::cout << "  Run all startup actions: " << std::endl;  
  for(std::vector<StartupActions*>::iterator it = startupActions.begin(); 
    it != startupActions.end(); it++)
    (*it)->run(this);
};

Context::~Context()
{
  std::cout << "Context.destructor()" << std::endl;
};

int Context::getIntAttribute(void)
{
  return(intAttribute);
};

float Context::getFloatAttribute(void)
{
  return(floatAttribute);
};

std::string Context::getStringAttribute(void)
{
  return(stringAttribute);
};

StartupActions::StartupActions()
{
  std::cout << "StartupActions.constructor()" << std::endl;
};

StartupActions::~StartupActions()
{
  std::cout << "StartupActions.destructor()" << std::endl;
};

StartupAction1::StartupAction1()
{
  std::cout << "StartupAction1.constructor()" << std::endl;
};

StartupAction1::~StartupAction1()
{
  std::cout << "StartupAction1.destructor()" << std::endl;
};

void StartupAction1::run(Context *context)
{
  std::cout << "StartupAction1.run(): " << std::endl;
  std::cout << "  intAttribute: " << context->getIntAttribute() << std::endl;
};

StartupAction2::StartupAction2()
{
  std::cout << "StartupAction2.constructor()" << std::endl;
};

StartupAction2::~StartupAction2()
{
  std::cout << "StartupAction2.destructor()" << std::endl;
};

void StartupAction2::run(Context *context)
{
  std::cout << "StartupAction2.run(): " << std::endl;
  std::cout << "  floatAttribute: " << context->getFloatAttribute() << std::endl;
};

StartupAction3::StartupAction3()
{
  std::cout << "StartupAction3.constructor()" << std::endl;
};

StartupAction3::~StartupAction3()
{
  std::cout << "StartupAction3.destructor()" << std::endl;
};

void StartupAction3::run(Context *context)
{
  std::cout << "StartupAction3.run(): " << std::endl;
  std::cout << "  stringAttribute: " << context->getStringAttribute() << std::endl;
};

#include "Classes.h"

ContextBuilder::ContextBuilder()
{
  std::cout << "ContextBuilder::constructor()" << std::endl;
};

ContextBuilder::~ContextBuilder()
{
  std::cout << "ContextBuilder::destructor()" << std::endl;
};

void ContextBuilder::setIntAttribute(int intAttribute_)
{
  std::cout << "ContextBuilder::setIntAttribute()" << std::endl;
  
  intAttribute = intAttribute_;
  
  std::cout << "  intAttribute: " << intAttribute << std::endl;
};

void ContextBuilder::setFloatAttribute(float floatAttribute_)
{
  std::cout << "ContextBuilder::setFloatIntAttribute()" << std::endl;
  
  floatAttribute = floatAttribute_;
  
  std::cout << "  floatAttribute: " << floatAttribute << std::endl;
};

void ContextBuilder::setStringAttribute(std::string stringAttribute_)
{
  std::cout << "ContextBuilder::setStringAttribute()" << std::endl;
  
  stringAttribute = stringAttribute_;
  
  std::cout << "  stringAttribute: " << stringAttribute << std::endl;
};

Context * ContextBuilder::buildContext(void)
{
  return(new Context(intAttribute, floatAttribute, stringAttribute));
};


Context::Context()
{
  std::cout << "Context::constructor()" << std::endl;
  std::cout << "  Default values will be assigned to attributes" << std::endl;
  
  intAttribute = 11;
  floatAttribute = 22.22;
  stringAttribute = "default context string";
  
  std::cout << "    intAttribute   : " << intAttribute << std::endl;
  std::cout << "    floatAttribute : " << floatAttribute << std::endl;
  std::cout << "    stringAttribute: " << stringAttribute << std::endl;
};

Context::Context(int intAttribute_, 
  float floatAttribute_, std::string stringAttribute_):
  intAttribute(intAttribute_), floatAttribute(floatAttribute_), 
  stringAttribute(stringAttribute_)
{
  std::cout << "Context::constructor()" << std::endl;
  std::cout << "  Custom values will be assigned to attributes" << std::endl;
  
  std::cout << "    intAttribute   : " << intAttribute << std::endl;
  std::cout << "    floatAttribute : " << floatAttribute << std::endl;
  std::cout << "    stringAttribute: " << stringAttribute << std::endl;
};

Context::~Context()
{
  std::cout << "Context::destructor()" << std::endl;
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

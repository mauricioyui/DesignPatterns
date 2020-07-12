#include "Classes.h"

Singleton::Singleton()
{
  std::cout << "singleton.constructor()" << std::endl;
  value = 0;
};

Singleton::~Singleton()
{
  std::cout << "singleton.destructor()" << std::endl;
};

Singleton * Singleton::getInstance()
{
  if(instance == NULL)
    instance = new Singleton;
    
  return(instance);
};

int Singleton::getValue()
{
  return(value);
};
  
void Singleton::setValue(int value_)
{
  value = value_;
  std::cout << "singleton.setValue: " << value << std::endl;
};

void Singleton::free()
{
  std::cout << "singleton.free()" << std::endl;
  delete(instance);
  instance = NULL;
};

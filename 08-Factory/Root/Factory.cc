#include "Classes.h"

int main()
{
  std::cout << "Start Design Pattern Demonstration: Factory" << std::endl;

  std::cout << std::endl;
  ContextFactory contextFactory;

  std::cout << std::endl;
  Context *context = contextFactory.getContext();
  context->getId();
  delete(context);

  std::cout << std::endl;  
  context = contextFactory.getContext();
  context->getId();
  
  std::cout << std::endl;
  std::cout << "End Design Pattern Demonstration: Factory" << std::endl;
  return(0);
}

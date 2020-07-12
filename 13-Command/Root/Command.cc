#include "Classes.h"

int main()
{
  std::cout << "Start Design Pattern Demonstration: Command" << std::endl;

  Context context1, context2;
  ContextContainer contextContainer;
  
  std::cout << std::endl;
  
  contextContainer.add(new ProcessContext(&context1));
  contextContainer.add(new ProcessContext(&context2));
  contextContainer.add(new FinishContext(&context1));
  
  std::cout << std::endl;
  contextContainer.process();

  std::cout << std::endl;
  std::cout << "contex1 final status: " << context1.getStatus() << std::endl;
  std::cout << "contex2 final status: " << context2.getStatus() << std::endl;

  std::cout << std::endl;
  std::cout << "End Design Pattern Demonstration: Command" << std::endl;
  return(0);
}

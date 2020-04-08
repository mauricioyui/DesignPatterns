#include "Classes.h"

int main()
{
  std::cout << "Start Design Pattern Demonstration: State" << std::endl;

  int initialValue = 0;
  while(1)
  {
    std::cout << std::endl;
    std::cout << "Please enter an initial value of integer type:" << std::endl;
    std::cin >> initialValue;
    
    if(std::cin.good())
      break;

    std::cout << "The parameter input is not an integer..." << std::endl;
    
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }

  std::cout << std::endl;
  Context context(initialValue);
  
  std::cout << std::endl;
  context.run();
  
  std::cout << std::endl;
  context.toState1();
  context.run();
  
  std::cout << std::endl;
  context.toState2();
  context.run();
  
  std::cout << std::endl;
  context.toStateFinal();
  context.run();
  
  std::cout << std::endl;
  std::cout << "End Design Pattern Demonstration: State" << std::endl;
  return(0);
}

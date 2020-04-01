#include "Classes.h"

int main()
{
  std::cout << std::endl;
  std::cout << "Start Design Pattern Demonstration: Strategy" << std::endl;

  int initialValue = 0;
  while(1)
  {
    std::cout << std::endl;
    std::cout << "Please enter an initial value of integer type:" << std::endl;
    std::cin >> initialValue;
    
    if(std::cin.good())
      break;

    std::cout << "The parameter input is not an integer..." << std::endl;
    
    // Clear std::cin error flags
    std::cin.clear();
    
    // Clear std::cin buffer
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
  std::cout << std::endl;
  
  Context context(initialValue);
  Linker linker;

  std::cout << std::endl;
  Strategy *strategy = new Strategy1;
  linker.run(context, strategy);
  delete(strategy);

  std::cout << std::endl;
  Strategy2 strategy2;
  strategy = &strategy2;
  linker.run(context, strategy);

  {
    std::cout << std::endl;
    Strategy3 strategy3;
    strategy = &strategy3;
    linker.run(context, &strategy3);
  }

  std::cout << std::endl;
  std::cout << "End Design Pattern Demonstration: Strategy" << std::endl;
  return(0);
}

#include "Classes.h"


int main()
{
  std::cout << "Start Design Pattern Demonstration: Decorator" << std::endl;

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
  Decorator2 *pDecorator2 = new Decorator2();
  std::cout << std::endl;
  Decorator1 decorator1(pDecorator2);
  
  int result = decorator1.run(context);

  std::cout << std::endl;
  std::cout << "result: " << result << std::endl;

  std::cout << std::endl;
  delete(pDecorator2);

  std::cout << std::endl;
  std::cout << "End Design Pattern Demonstration: Decorator" << std::endl;
  return(0);
}

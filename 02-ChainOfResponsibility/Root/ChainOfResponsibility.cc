#include "Classes.h"

int main()
{
  std::cout << "Start Design Pattern Demonstration: Chain of Responsibility" << std::endl;

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
  Analyzer analyzer;

  std::cout << std::endl;
  analyzer.run(context);

  std::cout << std::endl;
  std::cout << "End Design Pattern Demonstration: Chain of Responsibility" << std::endl;
  return(0);
}

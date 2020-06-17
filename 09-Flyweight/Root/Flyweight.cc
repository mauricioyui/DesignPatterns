#include "Classes.h"

int main()
{
  std::cout << "Start Design Pattern Demonstration: Flyweight" << std::endl;

  DigitsContainer digitsContainer;
  int initialValue = 0;
  
  while(1)
  {
    std::cout << std::endl;
    std::cout << "Please enter an initial value of integer type:" << std::endl;
    std::cin >> initialValue;
    
    if(std::cin.good())
      break;
      
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "The parameter input is not an integer..." << std::endl;
  }

  int divider = 10;
  while(initialValue > divider)
    divider *= 10;

  std::cout << std::endl;
  std::cout << "You have entered: " << initialValue << " (";
  while(initialValue > 0)
  {
    divider /= 10;
    std::cout << digitsContainer.getString(initialValue / divider) << " ";
    initialValue %= divider;
  }
  std::cout << "\b)" << std::endl;
  
  std::cout << std::endl;
  std::cout << "End Design Pattern Demonstration: Flyweight" << std::endl;
  return(0);
}

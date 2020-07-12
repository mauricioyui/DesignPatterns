#include "Classes.h"

/* Initialize instance to NULL */
Singleton * Singleton::instance = NULL;

int main()
{
  std::cout << "Start Design Pattern Demonstration: Singleton" << std::endl;

  int finalValue = 0;
  
  while(1)
  {
    std::cout << std::endl;
    std::cout << "Please enter a final value of integer type:" << std::endl;
    std::cin >> finalValue;
    
    if(std::cin.good())
      break;
      
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "The parameter input is not an integer..." << std::endl;
  }

  std::cout << std::endl;
  Singleton *singleton1, *singleton2;
  singleton1 = singleton1->getInstance();
  singleton2 = singleton2->getInstance();

  std::cout << std::endl;
  std::cout << "Initial value: " << std::endl;
  std::cout << "singleton1->getValue(): " << singleton1->getValue() << std::endl;
  std::cout << "singleton2->getValue(): " << singleton2->getValue() << std::endl;
  
  std::cout << std::endl;
  std::cout << "Final value: " << std::endl;
  singleton1->setValue(finalValue);
  std::cout << "singleton1->getValue(): " << singleton2->getValue() << std::endl;
  std::cout << "singleton2->getValue(): " << singleton2->getValue() << std::endl;
  
  singleton1->free();
  
  std::cout << std::endl;
  std::cout << "End Design Pattern Demonstration: Singleton" << std::endl;
  return(0);
}

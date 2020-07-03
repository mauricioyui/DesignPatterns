#include "Classes.h"

int main()
{
  std::cout << "Start Design Pattern Demonstration: Interpreter" << std::endl;

  int firstInt = 0, secondInt = 0, thirdInt = 0;
  
  while(1)
  {
    std::cout << std::endl;
    std::cout << "Please enter a value for the first integer:" << std::endl;
    std::cin >> firstInt;
    
    if(std::cin.good())
      break;

    std::cout << "The parameter input is not an integer..." << std::endl;
    
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
  
  while(1)
  {
    std::cout << std::endl;
    std::cout << "Please enter a value for the second integer:" << std::endl;
    std::cin >> secondInt;
    
    if(std::cin.good())
      break;

    std::cout << "The parameter input is not an integer..." << std::endl;
    
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
  
  while(1)
  {
    std::cout << std::endl;
    std::cout << "Please enter a value for the third integer:" << std::endl;
    std::cin >> thirdInt;
    
    if(std::cin.good())
      break;

    std::cout << "The parameter input is not an integer..." << std::endl;
    
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }

  Number firstNumber(firstInt), secondNumber(secondInt), thirdNumber(thirdInt);
  Sum sum(&firstNumber, &secondNumber);
  Subtraction subtraction(&sum, &thirdNumber);
  
  std::cout << std::endl;
  
  std::cout << "main: sum.evaluate: " << sum.evaluate() << std::endl;
  std::cout << "main: subtraction.evaluate: " << subtraction.evaluate() << std::endl;

  std::cout << std::endl;
  std::cout << "End Design Pattern Demonstration: Interpreter" << std::endl;
  return(0);
}

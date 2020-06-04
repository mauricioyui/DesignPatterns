#include "Classes.h"

int main()
{
  std::cout << "Start Design Pattern Demonstration: Observer" << std::endl;
  std::cout << std::endl;

  int intAttribute = 0;
  float floatAttribute = 0;
  std::string stringAttribute = "Initial customized string";
  
  while(1)
  {
    std::cout << std::endl;
    std::cout << "Please enter an initial value of integer type:" << std::endl;
    std::cin >> intAttribute;
    
    if(std::cin.good())
      break;
      
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "The parameter input is not an integer..." << std::endl;
  }
  
  while(1)
  {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    std::cout << std::endl;
    std::cout << "Please enter an initial value of float type:" << std::endl;
    std::cin >> floatAttribute;
    
    if(std::cin.good())
      break;

    std::cout << "The parameter input is not a float..." << std::endl;
  }
  
  {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    std::cout << std::endl;
    std::cout << "Please enter a word:" << std::endl;
    std::cin >> stringAttribute;
  }

  std::cout << std::endl;
  Context context(intAttribute, floatAttribute, stringAttribute);
  
  std::cout << std::endl;
  std::cout << "End Design Pattern Demonstration: Observer" << std::endl;
  return(0);
}

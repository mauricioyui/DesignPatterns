#include "Classes.h"

int main()
{
  std::cout << "Start Design Pattern Demonstration: Builder" << std::endl;

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
  ContextBuilder contextBuilder;
   
  contextBuilder.setIntAttribute(intAttribute);
  contextBuilder.setFloatAttribute(floatAttribute);
  contextBuilder.setStringAttribute(stringAttribute);

  std::cout << std::endl;
  Context * context = contextBuilder.buildContext();
  
  std::cout << std::endl;
  std::cout << "context->intAttribute   : " << context->getIntAttribute() << std::endl;
  std::cout << "context->floatAttribute : " << context->getFloatAttribute() << std::endl;
  std::cout << "context->stringAttribute: " << context->getStringAttribute() << std::endl;

  std::cout << std::endl;
  intAttribute++;
  contextBuilder.setIntAttribute(intAttribute);
  floatAttribute += 0.5;
  contextBuilder.setFloatAttribute(floatAttribute);

  std::cout << std::endl;  
  delete(context);

  std::cout << std::endl;
  Context * context2;
  context2 = contextBuilder.buildContext();
  std::cout << std::endl;
  std::cout << "context2->intAttribute   : " << context2->getIntAttribute() << std::endl;
  std::cout << "context2->floatAttribute : " << context2->getFloatAttribute() << std::endl;
  std::cout << "context2->stringAttribute: " << context2->getStringAttribute() << std::endl;
  
  std::cout << std::endl;
  std::cout << "End Design Pattern Demonstration: Builder" << std::endl;
  return(0);
}

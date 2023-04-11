#include "Classes.h"

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <typeinfo>

int main()
{
  std::cout << std::endl;
  std::cout << "Program start" << std::endl;

  {
    Train train;
    int v1 = 123;
    int v2 = 456;
    char c1= 'g';
    uint16_t s1 = 0xFFFE;

    std::cout << std::endl;
    train.set("myInt", v1);
    std::cout << std::endl;
    train.set("myChar", c1);
    std::cout << std::endl;
    train.set("myShort", s1);
    std::cout << std::endl;

    std::cout << "Variables allocated" << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Print char : " << train.get< char >("myChar")      << std::endl;
    std::cout << "Print short: " << train.get< uint16_t >("myShort") << std::endl;
    std::cout << "Print int  : " << train.get< int >("myInt")        << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Set new integer value" << std::endl;
    train.set("myInt", v2);
    std::cout << "Print int  : " << train.get< int >("myInt") << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
  }

  std::cout << "Program end" << std::endl;
  return(0);
}

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
    train.set("int1", v1);
    std::cout << std::endl;
    train.set("char1", c1);
    std::cout << std::endl;
    train.set("short1", s1);
    std::cout << std::endl;

    std::cout << "Variables allocated" << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Print char1: " << train.get< char >("char1") << std::endl;
    std::cout << "Print short1: " << train.get< uint16_t >("short1") << std::endl;
    std::cout << "Print int1: " << train.get< int >("int1") << std::endl;
    train.set("int1", v2);
    std::cout << "Print int1: " << train.get< int >("int1") << std::endl;

    train.clear< int >("int1");
    std::cout << std::endl;
    train.clear< uint16_t >("short1");
    std::cout << std::endl;
    train.clear< char >("char1");
    std::cout << std::endl;
  }

  std::cout << "Program end" << std::endl;
  return(0);
}

#include "Classes.h"

int main()
{
  std::cout << "Start Design Pattern Demonstration: Facade" << std::endl;

  std::cout << std::endl;
  ShapeContainer shapeContainer;
  
  std::cout << std::endl;
  shapeContainer.drawCircle();
  shapeContainer.drawTriangle();
  shapeContainer.drawSquare();

  std::cout << std::endl;
  std::cout << "End Design Pattern Demonstration: Facade" << std::endl;
  return(0);
}

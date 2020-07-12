#include "Classes.h"

ShapeContainer::ShapeContainer()
{
  std::cout << "ShapeContainer.constructor()" << std::endl;
};

ShapeContainer::~ShapeContainer()
{
  std::cout << "ShapeContainer.destructor()" << std::endl;
};

Shape::Shape()
{
  std::cout << "Shape.constructor()" << std::endl;
};

Shape::~Shape()
{
  std::cout << "Shape.destructor()" << std::endl;
};


Circle::Circle()
{
  std::cout << "Circle.constructor()" << std::endl;
};

Circle::~Circle()
{
  std::cout << "Circle.destructor()" << std::endl;
};

void Circle::draw()
{
  std::cout << "Circle.draw()" << std::endl;
};

Triangle::Triangle()
{
  std::cout << "Triangle.constructor()" << std::endl;
};

Triangle::~Triangle()
{
  std::cout << "Triangle.destructor()" << std::endl;
};

void Triangle::draw()
{
  std::cout << "Triangle.draw()" << std::endl;
};

Square::Square()
{
  std::cout << "Square.constructor()" << std::endl;
};

Square::~Square()
{
  std::cout << "Square.destructor()" << std::endl;
};

void Square::draw()
{
  std::cout << "Square.draw()" << std::endl;
};

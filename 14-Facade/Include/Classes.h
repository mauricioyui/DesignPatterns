#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>
#include <limits>

class Shape
{
public:
  Shape();
  virtual ~Shape();
  
  virtual void draw() = 0;
};

class Circle: public Shape
{
public:
  Circle();
  ~Circle();
  
  void draw();
};

class Triangle: public Shape
{
public:
  Triangle();
  ~Triangle();
  
  void draw();
};

class Square: public Shape
{
public:
  Square();
  ~Square();
  
  void draw();
};

class ShapeContainer
{
private:
  Circle circle;
  Triangle triangle;
  Square square;

public:
  ShapeContainer();
  ~ShapeContainer();
  
  void drawCircle()
  {
    circle.draw();
  };
  
  void drawTriangle()
  {
    triangle.draw();
  };
  
  void drawSquare()
  {
    square.draw();
  };
};

#endif

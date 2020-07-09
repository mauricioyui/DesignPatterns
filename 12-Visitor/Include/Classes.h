#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>
#include <limits>

class Visitor;
class Number;
class Sum;
class Subtraction;

class Interpreter
{
public:
  Interpreter();
  virtual ~Interpreter();

  virtual int evaluate() = 0;
  virtual void print(Visitor *visitor) = 0;
};

class Visitor
{
public:
  Visitor();
  ~Visitor();
  
  void printNumber(Number *number);
  void printSum(Sum *sum);
  void printSubtraction(Subtraction *subtraction);
};

class Number: public Interpreter
{
protected:
  int value;

public:
  Number(int value_);
  ~Number();
  
  int evaluate();
  int getValue();
  void print(Visitor *visitor);
};

class Sum: public Interpreter
{
protected:
  Interpreter *left;
  Interpreter *right;

public:
  Sum(Interpreter *left_, Interpreter *right_);
  ~Sum();
  
  int evaluate();
  void print(Visitor *visitor);
  Interpreter * getLeft();
  Interpreter * getRight();
};

class Subtraction: public Interpreter
{
protected:
  Interpreter *left;
  Interpreter *right;

public:
  Subtraction(Interpreter *left_, Interpreter *right_);
  ~Subtraction();
  
  int evaluate();
  void print(Visitor *visitor);
  Interpreter * getLeft();
  Interpreter * getRight();
};

#endif


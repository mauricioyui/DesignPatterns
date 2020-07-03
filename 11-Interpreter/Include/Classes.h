#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>
#include <limits>

class Interpreter
{
public:
  Interpreter();
  virtual ~Interpreter();

  virtual int evaluate() = 0;
};

class Number: public Interpreter
{
protected:
  int value;

public:
  Number(int value_);
  ~Number();
  
  int evaluate();
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
};
#endif

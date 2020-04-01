#ifndef CLASSES_H
#define CLASSES_H

#include <iostream>
#include <limits>

class Context
{
private:
  int value;

public:
  Context(int value_ = 1);
  ~Context();

  int getValue();
};

class Decorator
{
protected:
  Decorator *next;

public:
  Decorator();
  Decorator(Decorator *next_);
  virtual ~Decorator();

  virtual int run(Context &context) = 0;
};

class Decorator1: public Decorator
{
public:
  Decorator1();
  Decorator1(Decorator *next_);
  ~Decorator1();

  int run(Context &context);
};

class Decorator2: public Decorator
{
public:
  Decorator2();
  Decorator2(Decorator *next_);
  ~Decorator2();

  int run(Context &context);
};

#endif

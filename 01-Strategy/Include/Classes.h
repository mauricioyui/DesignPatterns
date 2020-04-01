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

class Strategy
{
public:
  Strategy();
  virtual ~Strategy();

  virtual void run(Context &context) = 0;
};

class Strategy1: public Strategy
{
public:
  Strategy1();
  ~Strategy1();

  void run(Context &context);
};

class Strategy2: public Strategy
{
public:
  Strategy2();
  ~Strategy2();

  void run(Context &context);
};

class Strategy3: public Strategy
{
public:
  Strategy3();
  ~Strategy3();

  void run(Context &context);
};

class Linker
{
public:
  Linker();
  ~Linker();

  void run(Context &context, Strategy *strategy);
};

#endif

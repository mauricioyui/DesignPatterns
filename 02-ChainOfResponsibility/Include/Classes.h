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

class Chain
{
protected:
  Chain *next;

public:
  Chain();
  virtual ~Chain();

  virtual void run(Context &context) = 0;
  virtual void setNext(Chain *netx_) = 0;
};

class Chain1: public Chain
{
public:
  Chain1();
  ~Chain1();

  void run(Context &context);
  void setNext(Chain *next_);
};

class Chain2: public Chain
{
public:
  Chain2();
  ~Chain2();

  void run(Context &context);
  void setNext(Chain *next_);
};

class Analyzer
{
public:
  Analyzer();
  ~Analyzer();

  void run(Context &context);
};

#endif

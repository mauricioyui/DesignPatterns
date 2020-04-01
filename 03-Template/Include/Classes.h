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

class Benchmark
{
public:
  Benchmark();
  virtual ~Benchmark();

  virtual void run(Context &context) = 0;
};

class BenchmarkTemplate: public Benchmark
{
public:
  BenchmarkTemplate();
  virtual ~BenchmarkTemplate();

  virtual bool condition(Context &context) = 0;
  virtual void process1(Context &context) = 0;
  virtual void process2(Context &context) = 0;

  void run(Context &context);
};

class Benchmark1: public BenchmarkTemplate
{
public:
  Benchmark1();
  ~Benchmark1();

  bool condition(Context &context);
  void process1(Context &context);
  void process2(Context &context);
};

class Benchmark2: public BenchmarkTemplate
{
  void easterEgg(Context &context);

public:
  Benchmark2();
  ~Benchmark2();

  bool condition(Context &context);
  void process1(Context &context);
  void process2(Context &context);
};

#endif

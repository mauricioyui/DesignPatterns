#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <limits>

class Context;

class State
{
public:
  State();
  virtual ~State();

  virtual void run(Context *context) = 0;
  virtual void toState1(Context *context) = 0;
  virtual void toState2(Context *context) = 0;
  virtual void toStateFinal(Context *context) = 0;
};

class State0: public State
{
public:
  State0();
  ~State0();
  
  void run(Context *context);
  void toState1(Context *context);
  void toState2(Context *context);
  void toStateFinal(Context *context);
};

class State1: public State
{
public:
  State1();
  ~State1();
  
  void run(Context *context);
  void toState1(Context *context);
  void toState2(Context *context);
  void toStateFinal(Context *context);
};

class State2: public State
{
public:
  State2();
  ~State2();
  
  void run(Context *context);
  void toState1(Context *context);
  void toState2(Context *context);
  void toStateFinal(Context *context);
};

class StateSuccess: public State
{
public:
  StateSuccess();
  ~StateSuccess();
  
  void run(Context *context);
  void toState1(Context *context);
  void toState2(Context *context);
  void toStateFinal(Context *context);
};

class StateFail: public State
{
public:
  StateFail();
  ~StateFail();
  
  void run(Context *context);
  void toState1(Context *context);
  void toState2(Context *context);
  void toStateFinal(Context *context);
};

class Context
{
protected:
  int value;
  State *state;

public:
  Context(int value_);
  ~Context();

  void setValue(int value_);
  int getValue();
  
  void setState(State *state_);

  void run();
  void toState1();
  void toState2();
  void toStateFinal();
};

#endif

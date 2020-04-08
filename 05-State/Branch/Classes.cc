#include "Classes.h"

State::State()
{
  std::cout << "State::constructor()" << std::endl;
};

State::~State()
{
  std::cout << "State::destructor()" << std::endl;
};

State0::State0()
{
  std::cout << "State0::constructor()" << std::endl;
};

State0::~State0()
{
  std::cout << "State0::destructor()" << std::endl;
};

void State0::run(Context *context)
{
  std::cout << "State0::run(): context.value: " << context->getValue() << std::endl;
};

void State0::toState1(Context *context)
{
  std::cout << "State 0: raising context to State1" << std::endl;

  context->setState(new State1());
  delete(this);
};

void State0::toState2(Context *context)
{
  std::cout << "State0: can not raise context to State2" << std::endl;
};

void State0::toStateFinal(Context *context)
{
  std::cout << "State0: can not raise context to StateFinal" << std::endl;
};

State1::State1()
{
  std::cout << "State1::constructor()" << std::endl;
};

State1::~State1()
{
  std::cout << "State1::destructor()" << std::endl;
};

void State1::run(Context *context)
{
  int value = context->getValue();
  context->setValue(value * 10);
  
  std::cout << "State1::run(): context.value: " << context->getValue() << std::endl;
};

void State1::toState1(Context *context)
{
  std::cout << "State 1: context already in State1" << std::endl;
};

void State1::toState2(Context *context)
{
  std::cout << "State1: raising context to State2" << std::endl;
  
  context->setState(new State2());
  delete(this);
};

void State1::toStateFinal(Context *context)
{
  std::cout << "State1: can not raise context to StateFinal" << std::endl;
};

State2::State2()
{
  std::cout << "State2::constructor()" << std::endl;
};

State2::~State2()
{
  std::cout << "State2::destructor()" << std::endl;
};

void State2::run(Context *context)
{
  int value = context->getValue();
  context->setValue(value * 20);
  
  std::cout << "State2::run(): context.value: " << context->getValue() << std::endl;
};

void State2::toState1(Context *context)
{
  std::cout << "State 2: context can not lower to State1" << std::endl;
};

void State2::toState2(Context *context)
{
  std::cout << "State 2: context already in State2" << std::endl;
};

void State2::toStateFinal(Context *context)
{
  std::cout << "State2: raise context to StateFinal" << std::endl;
  
  if(context->getValue() > 5000)
    context->setState(new StateSuccess());
  else
    context->setState(new StateFail());
  
  delete(this);
};

StateSuccess::StateSuccess()
{
  std::cout << "StateSuccess::constructor()" << std::endl;
};

StateSuccess::~StateSuccess()
{
  std::cout << "StateSuccess::destructor()" << std::endl;
};

void StateSuccess::run(Context *context)
{
  std::cout << "StateSuccess::run(): context.value: " << context->getValue() << std::endl;
};

void StateSuccess::toState1(Context *context)
{
  std::cout << "StateSuccess: context can not lower to State1" << std::endl;
};

void StateSuccess::toState2(Context *context)
{
  std::cout << "StateSuccess: context can not lower to State2" << std::endl;
};

void StateSuccess::toStateFinal(Context *context)
{
  std::cout << "StateSuccess: context already in StateFinal" << std::endl;
};

StateFail::StateFail()
{
  std::cout << "StateFail::constructor()" << std::endl;
};

StateFail::~StateFail()
{
  std::cout << "StateFail::destructor()" << std::endl;
};

void StateFail::run(Context *context)
{
  std::cout << "StateFail::run(): context.value: " << context->getValue() << std::endl;
};

void StateFail::toState1(Context *context)
{
  std::cout << "StateFail: context can not lower to State1" << std::endl;
};

void StateFail::toState2(Context *context)
{
  std::cout << "StateFail: context can not lower to State2" << std::endl;
};

void StateFail::toStateFinal(Context *context)
{
  std::cout << "StateFail: context already in StateFinal" << std::endl;
};

void Context::setValue(int value_)
{
  value = value_;
};

int Context::getValue()
{
  return value;
};

void Context::setState(State *state_)
{
  state = state_;
};

void Context::run()
{
  std::cout << "Context.run()" << std::endl;
  state->run(this);
};

void Context::toState1()
{
  std::cout << "Context.toState1()" << std::endl;
  state->toState1(this);
};

void Context::toState2()
{
  std::cout << "Context.toState2()" << std::endl;
  state->toState2(this);
};

void Context::toStateFinal()
{
  std::cout << "Context.toStateFinal()" << std::endl;
  state->toStateFinal(this);
};

Context::Context(int value_):
  value(value_),
  state(new State0)
{
};

Context::~Context()
{
  delete(state);
};

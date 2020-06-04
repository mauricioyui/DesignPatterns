#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>
#include <limits>
#include <vector>

class Context
{
private:
  int intAttribute;
  float floatAttribute;
  std::string stringAttribute;
  
public:
  Context(int intAttribute_, 
          float floatAttribute_, 
          std::string stringAttribute_);
  ~Context();
  
  int getIntAttribute(void);
  float getFloatAttribute(void);
  std::string getStringAttribute(void);
};

class StartupActions
{
public:
  StartupActions();
  virtual ~StartupActions();
  
  virtual void run(Context *context) = 0;
};

class StartupAction1 : public StartupActions
{
public:
  StartupAction1();
  ~StartupAction1();
  
  void run(Context *context);
};

class StartupAction2 : public StartupActions
{
public:
  StartupAction2();
  ~StartupAction2();
  
  void run(Context *context);
};

class StartupAction3 : public StartupActions
{
public:
  StartupAction3();
  ~StartupAction3();
  
  void run(Context *context);
};

#endif

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>
#include <limits>
#include <map>

class Context;

class ContextBuilder
{
private:
  int intAttribute;
  float floatAttribute;
  std::string stringAttribute;
  
public:
  ContextBuilder();
  ~ContextBuilder();

  void setIntAttribute(int intAttribute_);
  void setFloatAttribute(float floatAttribute_);
  void setStringAttribute(std::string stringAttribute_);
  
  Context * buildContext(void);
};

class Context
{
private:
  int intAttribute;
  float floatAttribute;
  std::string stringAttribute;
  
public:
  Context();
  Context(int intAttribute_, 
          float floatAttribute_, 
          std::string stringAttribute_);
  ~Context();
  
  int getIntAttribute(void);
  float getFloatAttribute(void);
  std::string getStringAttribute(void);
};

#endif

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>
#include <limits>

class Context
{
private:
  int id;

public:
  Context(int id_);
  ~Context();
  
  int getId();
};

class ContextFactory
{
private:
  int idGenerator;
  
public:
  ContextFactory();
  virtual ~ContextFactory();
  
  Context * getContext();
};

#endif

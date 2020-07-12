#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>
#include <limits>

class Singleton
{
private:
  static Singleton *instance;
  int value;
  
  /* Private constructor so that no objects can be created */
  Singleton();
  ~Singleton();
  
public:
  static Singleton * getInstance();
  
  int getValue();
  void setValue(int value_);
  void free();
};
#endif

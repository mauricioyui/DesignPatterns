#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <curses.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <limits>

class Context
{
protected:
  char character;

public:
  Context();
  Context(char character_);
  ~Context();
  
  char getCharacter(void);
  void setCharacter(char character_);

  Context * saveContext();
};

class ContextHistory
{
private:
  std::vector<Context *> contextHistory;

public:
  ContextHistory();
  ~ContextHistory();
  
  Context * get(int index);
  void add(Context *context);
  void show(void);
};

#endif

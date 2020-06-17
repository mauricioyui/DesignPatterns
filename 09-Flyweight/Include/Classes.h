#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <map>

class Digit2String
{
public:
  Digit2String();
  virtual ~Digit2String();
  
  virtual std::string getString() = 0;
};

class Zero: public Digit2String
{
public:
  Zero();
  ~Zero();
  
  std::string getString();
};

class One: public Digit2String
{
public:
  One();
  ~One();
  
  std::string getString();
};

class Two: public Digit2String
{
public:
  Two();
  ~Two();
  
  std::string getString();
};

class Three: public Digit2String
{
public:
  Three();
  ~Three();
  
  std::string getString();
};

class Four: public Digit2String
{
public:
  Four();
  ~Four();
  
  std::string getString();
};

class Five: public Digit2String
{
public:
  Five();
  ~Five();
  
  std::string getString();
};

class Six: public Digit2String
{
public:
  Six();
  ~Six();
  
  std::string getString();
};

class Seven: public Digit2String
{
public:
  Seven();
  ~Seven();
  
  std::string getString();
};

class Eight: public Digit2String
{
public:
  Eight();
  ~Eight();
  
  std::string getString();
};

class Nine: public Digit2String
{
public:
  Nine();
  ~Nine();
  
  std::string getString();
};

class Context
{
private:
  int id;

public:
  Context(int id_);
  ~Context();
  
  int getId();
};

class DigitsContainer
{
private:
  std::map<int, Digit2String*>  digitsContainer;
  
public:
  DigitsContainer();
  ~DigitsContainer();
  
  std::string getString(int i);
};

#endif

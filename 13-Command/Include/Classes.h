#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <ctime>

enum Status
{
  NEW,
  PROCESS,
  FINISH
};

class Context
{
private:
  Status status;
  std::time_t date;

public:
  Context();
  ~Context();
  
  Status getStatus();
  void run();
  void process();
  void finish();
};

class Command
{
public:
  Command();
  virtual ~Command();

  virtual void run() = 0;
};

class ProcessContext: public Command
{
private: 
  Context *context;
  
public:
  ProcessContext(Context *context_);
  ~ProcessContext();
  
  void run();
};

class FinishContext: public Command
{
private:
  Context *context;

public:
  FinishContext(Context *context_);
  ~FinishContext();
  
  void run();
};

class ContextContainer
{
private:
   std::vector<Command*> commandsList;

public:
  ContextContainer();
  ~ContextContainer();

  void add(Command *command);
  void process();
};


#endif


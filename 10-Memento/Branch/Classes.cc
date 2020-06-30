#include "Classes.h"

Context::Context()
{
  std::cout << "Context.constructor() " << std::endl;
};

Context::Context(char character_):
  character(character_)
{
};

Context::~Context()
{
  std::cout << "Context.destructor() " << std::endl;
  std::cout << "  character: ";
  {
    if((32 < character) && (character < 127)) 
      std::cout << "'" << character << std::endl;
    else
      std::cout << "0x" << std::setw(2) << std::setfill('0') << (unsigned int) character << std::endl;
  }
};

char Context::getCharacter()
{
  return character;
};

void Context::setCharacter(char character_)
{
  character = character_;
};

Context * Context::saveContext()
{
  return(new Context(character));
}

ContextHistory::ContextHistory()
{
  std::cout << "ContextHistory.constructor() " << std::endl;
};

ContextHistory::~ContextHistory()
{
  for(std::vector<Context *>::iterator it = contextHistory.begin(); it != contextHistory.end(); it++)
    delete(*it);
  
  contextHistory.clear();
  
  std::cout << "ContextHistory.destructor() " << std::endl;
};
  
Context * ContextHistory::get(int index)
{
  return(contextHistory[index]);
};

void ContextHistory::add(Context *context)
{
  contextHistory.push_back(context);
};

void ContextHistory::show()
{
  std::cout << "Typed characters history:" << std::endl;
  std::cout << std::hex;
  for(std::vector<Context *>::iterator it = contextHistory.begin(); it != contextHistory.end(); it++)
  {
    if((32 < (*it)->getCharacter()) && ((*it)->getCharacter() < 127)) 
      std::cout << "\'" << (*it)->getCharacter() << "\' ";
    else
      std::cout << "0x" << std::setw(2) << std::setfill('0') << (unsigned int) (*it)->getCharacter() << " ";
  }
  std::cout << std::dec;
  std::cout << std::endl;
};

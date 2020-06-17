#include "Classes.h"

Digit2String::Digit2String()
{
  std::cout << "Digit2String.constructor()" << std::endl;
};

Digit2String::~Digit2String()
{
  std::cout << "Digit2String.destructor()" << std::endl;
};

Zero::Zero()
{
  std::cout << "Zero.constructor()" << std::endl;
};

Zero::~Zero()
{
  std::cout << "Zero.destructor()" << std::endl;
};

std::string Zero::getString()
{
  return("zero");
}

One::One()
{
  std::cout << "One.constructor()" << std::endl;
};

One::~One()
{
  std::cout << "One.destructor()" << std::endl;
};

std::string One::getString()
{
  return("one");
}

Two::Two()
{
  std::cout << "Two.constructor()" << std::endl;
};

Two::~Two()
{
  std::cout << "Two.destructor()" << std::endl;
};

std::string Two::getString()
{
  return("two");
}

Three::Three()
{
  std::cout << "Three.constructor()" << std::endl;
};

Three::~Three()
{
  std::cout << "Three.destructor()" << std::endl;
};

std::string Three::getString()
{
  return("three");
}

Four::Four()
{
  std::cout << "Four.constructor()" << std::endl;
};

Four::~Four()
{
  std::cout << "Four.destructor()" << std::endl;
};

std::string Four::getString()
{
  return("four");
}

Five::Five()
{
  std::cout << "Five.constructor()" << std::endl;
};

Five::~Five()
{
  std::cout << "Five.destructor()" << std::endl;
};

std::string Five::getString()
{
  return("five");
}

Six::Six()
{
  std::cout << "Six.constructor()" << std::endl;
};

Six::~Six()
{
  std::cout << "Six.destructor()" << std::endl;
};

std::string Six::getString()
{
  return("six");
}

Seven::Seven()
{
  std::cout << "Seven.constructor()" << std::endl;
};

Seven::~Seven()
{
  std::cout << "Seven.destructor()" << std::endl;
};

std::string Seven::getString()
{
  return("seven");
}

Eight::Eight()
{
  std::cout << "Eight.constructor()" << std::endl;
};

Eight::~Eight()
{
  std::cout << "Eight.destructor()" << std::endl;
};

std::string Eight::getString()
{
  return("eight");
}

Nine::Nine()
{
  std::cout << "Nine.constructor()" << std::endl;
};

Nine::~Nine()
{
  std::cout << "Nine.destructor()" << std::endl;
};

std::string Nine::getString()
{
  return("nine");
}

DigitsContainer::DigitsContainer()
{
  std::cout << "DigitsContainer.constructor()" << std::endl;
  
  digitsContainer.insert(std::pair<int, Digit2String*>(0, new Zero ));
  digitsContainer.insert(std::pair<int, Digit2String*>(1, new One  ));
  digitsContainer.insert(std::pair<int, Digit2String*>(2, new Two  ));
  digitsContainer.insert(std::pair<int, Digit2String*>(3, new Three));
  digitsContainer.insert(std::pair<int, Digit2String*>(4, new Four ));
  digitsContainer.insert(std::pair<int, Digit2String*>(5, new Five ));
  digitsContainer.insert(std::pair<int, Digit2String*>(6, new Six  ));
  digitsContainer.insert(std::pair<int, Digit2String*>(7, new Seven));
  digitsContainer.insert(std::pair<int, Digit2String*>(8, new Eight));
  digitsContainer.insert(std::pair<int, Digit2String*>(9, new Nine ));
};

DigitsContainer::~DigitsContainer()
{
  std::map<int, Digit2String*>::iterator it;
  for(it = digitsContainer.begin(); it != digitsContainer.end(); it++)
    delete it->second;
  
  std::cout << "DigitsContainer.destructor()" << std::endl;
  
  digitsContainer.clear();
};

std::string DigitsContainer::getString(int idx)
{
  return(digitsContainer[idx]->getString());
};

#ifndef BASE__H
#define BASE__H

#include <iostream>

class Base
{

protected:

  int x;

public:

  virtual void f() const
  {
    std::cout << "Base::f()" << std::endl;
  }

  virtual ~Base() 
  {
    std::cout << "Base dtor" << std::endl; 
  }

  // pure virtual, ''abstract'':
  // virtual void g() = 0;

};

class Der: public Base
{

public:

  virtual void f() const
  {
    std::cout << "Der::f()" << std::endl;
  }

  virtual ~Der() 
  {
    std::cout << "Der dtor" << std::endl; 
  }

};

#endif
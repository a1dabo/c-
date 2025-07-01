#include "base.h"
#include <iostream>
#include <vector>

void fun( Base& );

struct X: Base
{

  X() { x = 3; }

  int a, b, c;

  virtual void f() const
  {
    Base::f();
    std::cout << "X::f() " << x << std::endl;
  }

  virtual ~X() 
  {
    std::cout << "X dtor" << std::endl; 
  }

};

int main()
{
  Base* p = 0;
  p = new Base();
  fun( *p );
  p->f();
  delete p;
  p = new Der();
  fun( *p );
  p->f();
  delete p;
  p = new X();
  fun( *p );
  p->f();
  delete p;
  Base b;
  b.f();
  Der d;
  d.f();
  X x;
  x.f();
}
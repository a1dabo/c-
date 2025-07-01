#include <iostream>
#include <cmath>

class complex
{

  double re, im;

public:

  /*explicit*/ complex( double r = 0., double i = 0. )
  {
    re = r;
    im = i;
  }


  void print() const
  {
    std::cout << re << " + "
              << im << " i"
              << std::endl;
  }


  double abs() const
  {
    return std::sqrt( re * re + im * im );
  }


  double get_re() const
  {
    return re;
  }


  double get_im() const
  {
    return im;
  }

};

complex operator+( const complex& lhs, const complex& rhs )
{
  std::cout << "Hello from operator+" << std::endl;
  return complex( lhs.get_re() + rhs.get_re(), lhs.get_im() + rhs.get_im() );
}


bool operator==( const complex& lhs, const complex& rhs )
{
  return lhs.get_re() == rhs.get_re() &&
         lhs.get_im() == rhs.get_im();
}

void f( const complex& c )
{
  std::cout << c.abs() << std::endl;
}

int main()
{
  complex c;
  c.print();
  complex i( 0., 1. );
  i.print();
  const complex d( 2.4 );
  d.print();
  f( -1.6 ); // f( complex( -1.6 ) )
  f( 1.7 );
  complex s = d + i; // operator+( d, i )
  s.print();
  complex t = i + d; // operator+( d, i )
  t.print();
  complex u = t + 2.8; // operator+( t, complex( 2.8 ) )
  u.print();
  complex v = 2.8 + t; // operator+( complex( 2.8 ), t )
  v.print();
  if ( u == v )
  {
    std::cout << "u == v" << std::endl;
  }
  if( 2.4 == d )
  {
    std::cout << "OK" << std::endl;
  }
}
#include <iostream>

void inc( int i )
{
  ++i;
}

void inc_ptr( int* p )
{
  if( p )
  {
    ++( *p );
  }
}


void inc_ref( int& p )
{
  p++;
}


int main()
{
  int s = 5;

  inc( s );
  std::cout << s << std::endl;

  inc_ptr( 0 );

  inc_ptr( &s );
  std::cout << s << std::endl;

  inc_ref( s );
  std::cout << s << std::endl;

    for (int i = 0; i < 4; ++i)
    {
    std::cout << i << std::endl;
    }
    
}
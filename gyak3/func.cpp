#include <iostream>

void f( int );
void g( int& );
void h( const int& );

int main()
{
  int x = 3;

  f( 2 );
  f( x );
  f( x + 5 );
  f( x++ );
  f( ++x );

  // g( 4 ); // ford. hiba
  g( x );
  // g( x + 3 ); // ford. hiba
  // g( x++ ); // ford. hiba
  g( ++x );

  h( 1 );
  h( x );
  h( x + 4 );
  h( x++ );
  h( ++x );

}
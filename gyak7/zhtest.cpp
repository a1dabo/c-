#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

template<class T>
class array_util {
public:
    std::vector<T*> array;

    array_util(T *inar, int size) {
        for (int i = 0; i < size; i++) {
            array.push_back(&inar[i]);  // Csak mutatót tárolunk, nem másolunk
        }
    }

    ~array_util() {
        // Üres destruktor: nem szabadítunk fel, mert nem birtokoljuk az elemeket
    }

    array_util& copy(const array_util& other) {
        size_t min_size = std::min(array.size(), other.array.size());
        for (size_t i = 0; i < min_size; i++) {
            *array[i] = *other.array[i];  // Értékek másolása, nem mutatók
        }
        return *this;
    }

    array_util& operator=(const array_util& other) {
        size_t min_size = std::min(array.size(), other.array.size());
        for (size_t i = 0; i < min_size; i++) {
            *array[i] = *other.array[i];  // Értékek másolása, nem mutatók
        }
        return *this;
    }

    bool equals(const array_util& other) const {
        if (array.size() != other.array.size()) {
            return false;
        }
        for (size_t i = 0; i < array.size(); i++) {
            if (*array[i] != *other.array[i]) {
                return false;
            }
        }
        return true;
    }

};



const int max = 1000;

int main()
{
  int your_mark = 1;
  // 2-es
  int a[] = {7, 1, 9, 2};
  int b[] = {3, 8, 1};
  int c[] = {5, 3, 1};
  int d[] = {9, 1, 3};

  array_util<int> au( a, sizeof( a ) / sizeof( a[ 0 ] ) );
  array_util<int> bu( b, sizeof( b ) / sizeof( b[ 0 ] ) );
  const array_util<int> cu( c, sizeof( c ) / sizeof( c[ 0 ] ) );
  array_util<int> du( d, sizeof( d ) / sizeof( d[ 0 ] ) );

  du.copy( au );
  bu.copy( cu );

  std::string e[] = { "Hello", "World" };
  std::string f[] = { "Hello", "World" };
  std::string g[] = { "Goodbye", "Cruel", "World" };
  array_util<std::string> eu( e, sizeof( e ) / sizeof( e[ 0 ] ) );
  array_util<std::string> fu( f, sizeof( f ) / sizeof( f[ 0 ] ) );
  array_util<std::string> gu( g, sizeof( g ) / sizeof( g[ 0 ] ) );

  gu.copy( eu );

  int m[ max ];
  array_util<int> mu( m, sizeof( m ) / sizeof( m[ 0 ] ) );

  if ( eu.equals( fu ) && "World" == g[ 2 ] &&
       !gu.equals( fu ) && "Hello" == g[ 0 ] &&
       bu.equals( cu ) && 3 == b[ 1 ] && 9 == d[ 2 ] &&
       !cu.equals( du ) &&  !mu.equals( au ) )
  {
    your_mark = a[ 0 ] - b[ 0 ];
  }
  
  /* 3-as
  g[ 1 ].clear();
  mu = au;
  gu = eu;
  std::swap( f[ 0 ], f[ 1 ] );
  std::swap( c[ 0 ], c[ 2 ] );

  if ( fu.permutation( eu ) && !fu.equals( eu ) &&
       "World" == g[ 1 ] && cu.permutation( bu ) &&
       !cu.equals( bu ) && !mu.equals( au ) &&
       !mu.permutation( au ) && !bu.permutation( du ) )
  {
    your_mark = m[ 1 ] + m[ 3 ];
  }*/
  
  /* 4-es
  std::vector<int> v( m, m + max );
  array_util<int> vu( v );
  std::vector<std::string> s;
  s.push_back( "I" );
  s.push_back( "<3" );
  s.push_back( "C++" );
  const array_util<std::string> su( s );
  gu = su;

  std::vector<int> vm( max );
  array_util<int> vmu( vm );
  vmu = au;

  if ( mu == vu && su == gu && "<3" == g[ 1 ] &&
       !( fu == eu ) && 7 == vm[ 0 ] && 1 == vm[ 1 ] )
  {
    your_mark = g[ 0 ].length() + g[ 2 ].length();
  }
  */
  /* 5-os
  int x[] = {3, 8, 5};
  array_util<int> xu( x );

  std::vector<std::string> msgs;
  msgs.push_back( "Hello" );
  msgs.push_back( "World" );

  std::vector<int> vx;
  vx.push_back( 8 );
  vx.push_back( 5 );
  vx.push_back( 3 );

  if ( ( vx *= xu ) && !( vx == xu ) && ( fu *= eu ) &&
       !( su == fu ) && !( su *= fu) &&
       !( v *= au ) && !( v == au ) )
  {
    your_mark += ( msgs *= eu );
  }
  */
  std::cout << "Your mark is " << your_mark;
  std::endl( std::cout );
}

#ifndef ARRAY_H

#define ARRAY_H

#include <array>

template <class T, class size>
class Array
{
private:
    std::array<T *, size> cvec;

public:
    Array()
};

#endif
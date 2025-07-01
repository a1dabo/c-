#ifndef GAPBUFFER_H
#define GAPBUFFER_H

#include <algorithm>
#include <stdexcept>

template <typename T>
class gap_buffer
{
    T *buffer;
    int capacity;
    int gap_start;
    int gap_end;

public:
    gap_buffer(T *external, int size, int gap_size)
        : buffer(external), capacity(size)
    {
        if (gap_size >= size)
            throw std::runtime_error("Gap size too large");

        gap_start = 0;
        gap_end = gap_size;
        // Semmit nem írunk be, feltételezzük, hogy külső kódban ' ' van kitöltve
    }

    void insert(const T &value)
    {
        if (gap_start == gap_end)
            return; // gap megtelt
        buffer[gap_start++] = value;
    }

    void right()
    {
        if (gap_end >= capacity)
            return; // nem tud jobbra menni
        if (gap_start == 0)
            return; // semmit nem lehet áthelyezni
        buffer[gap_start] = buffer[gap_end];
        ++gap_start;
        ++gap_end;
    }

    void left()
    {
        if (gap_start == 0)
            return; // nem tud balra menni
        --gap_start;
        --gap_end;
        buffer[gap_end] = buffer[gap_start];
    }

    T &at(int index)
    {
        if (index < gap_start)
            return buffer[index];
        return buffer[index + (gap_end - gap_start)];
    }

    const T &at(int index) const
    {
        if (index < gap_start)
            return buffer[index];
        return buffer[index + (gap_end - gap_start)];
    }

    T &operator[](int index) { return at(index); }
    const T &operator[](int index) const { return at(index); }

    // Ehhez szükséges lehet később:
    void erase()
    {
        if (gap_end == capacity)
            return;
        ++gap_end;
    }

    gap_buffer<T> &operator+=(const T *str)
    {
        while (*str != 0)
        {
            insert(*str);
            ++str;
        }
        return *this;
    }
};

#endif

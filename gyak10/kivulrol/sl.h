#ifndef SL__H
#define SL__H

#include <list>
#include <functional>
#include <algorithm>

template <class T, class Comp = std::less<T>>
class SortedList
{

    std::list<T> c;
    Comp comp;

public:
    void insert(const T &t)
    {
        c.insert(std::lower_bound(c.begin(), c.end(), t, Comp()), t);
    }

    int size() const
    {
        return c.size();
    }

    const T &front() const
    {
        return c.front();
    }

    const T &back() const
    {
        return c.back();
    }

    void remove(const T &t)
    {
        std::pair<typename std::list<T>::iterator, typename std::list<T>::iterator> p = std::equal_range(c.begin(), c.end(), t, Comp());
        c.erase(p.first, p.second);
    }
};

#endif
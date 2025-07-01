#ifndef SL_H
#define SL_H

#include <list>
#include <functional>

template <class T, class Compare = std::less<T>>
class SortedList
{

    std::list<T> clist;

public:
    SortedList() {}

    SortedList(const SortedList &other)
    {
        for (const auto &data : other.clist)
        {
            clist.push_back(data);
        }
    }

    void insert(const T &n)
    {
        clist.push_back(n);
        clist.sort(Compare());
    }

    void remove(const T &n)
    {
        clist.remove(n);
    }

    const int size() const
    {
        return clist.size();
    }

    const T &front() const
    {
        return clist.front();
    }

    const T &back() const
    {
        return clist.back();
    }

    typename std::list<T>::const_iterator begin() const
    {
        return clist.begin();
    }

    typename std::list<T>::const_iterator end() const
    {
        return clist.end();
    }
};

#endif
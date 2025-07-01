#ifndef LISTVIEW_H

#define LISTVIEW_H

#include <list>

template <class T, typename Iter>
class array_view
{
    Iter data;

public:
    template <class cont>
    array_view(cont &a)
    {
        for (auto it = a.begin(); it != a.end(); it++)
        {
            data.push_back(it);
        }
    }

    const T &at(int idx) const
    {
        return *data[idx];
    }

    T &at(int idx)
    {
        return *data[idx];
    }

    T &operator[](int idx)
    {
        return *data[idx];
    }
};

#endif
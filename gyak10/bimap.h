#ifndef BIMAP_H
#define BIMAP_H

#include <map>

template <class T>
class BidirectionalMap
{
    typedef typename std::map<T, T> ttm;
    ttm inmap;

public:
    BidirectionalMap() {}

    template <class Iter>
    BidirectionalMap(Iter beg, Iter end)
    {
        auto it = beg;
        while (it != end)
        {
            inmap[it->first] = it->second;
            ++it;
        }
    }

    void insert(const T &t1, const T &t2)
    {
        inmap[t1] = t2;
    }

    const T &at(const T &key) const
    {
        for (auto it = inmap.begin(); it != inmap.end(); ++it)
        {
            if (it->first == key)
                return it->second;
            if (it->second == key)
                return it->first;
        }
    }

    void erase(const T &key)
    {
        for (auto it = inmap.begin(); it != inmap.end(); ++it)
        {
            if (it->first == key || it->second == key)
            {
                inmap.erase(it->first);
                return;
            }
        }
    }

    int size() const
    {
        return inmap.size();
    }

    int count(const T &key) const
    {
        int retval = 0;
        for (auto it = inmap.begin(); it != inmap.end(); ++it)
        {
            if (it->first == key)
                retval++;
            if (it->second == key)
                retval++;
        }
        return retval;
    }

    const auto begin() const
    {
        return inmap.begin();
    }

    const auto end() const
    {
        return inmap.end();
    }
};
#endif
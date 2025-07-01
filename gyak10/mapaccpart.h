#ifndef MAPACCPART_H
#define MAPACCPART_H

#include <map>

template <
    class Key,
    class T,
    class Compare = std::less<Key>,
    class Allocator = std::allocator<std::pair<const Key, T>>>
class map_accumulate_partition
{

    std::map<const Key, T *, Compare, Allocator> prmap;
    std::map<const Key, T, Compare> origval;
    Key current;

public:
    map_accumulate_partition(std::map<Key, T, Compare> &inmap)
    {

        for (auto &pair : inmap)
        {
            prmap[pair.first] = &pair.second;
            origval[pair.first] = pair.second;
        }
    }

    void reset()
    {
        for (auto &pair : origval)
        {
            *prmap[pair.first] = pair.second;
        }
    }

    void set_partition_key(const Key &key)
    {

        if (prmap.count(key) > 0)
        {
            current = key;
            reset();
            T sum = T();
            for (auto &pair : prmap)
            {
                if (pair.first == key)
                    return;
                sum = sum + *pair.second;
                *prmap[pair.first] = sum;
            }
        }
    }

    map_accumulate_partition &operator++(int)
    {
        auto it = prmap.find(current);
        if (it != prmap.begin() && it != prmap.end())
        {
            ++it;
            set_partition_key(it->first);
        }
        return *this;
    }

    map_accumulate_partition &operator--(int)
    {
        auto it = prmap.find(current);
        if (it != prmap.begin() && it != prmap.end())
        {
            --it;
            set_partition_key(it->first);
        }
        return *this;
    }

    map_accumulate_partition &operator++()
    {
        auto it = prmap.find(current);
        if (it != prmap.begin() && it != prmap.end())
        {
            ++it;
            set_partition_key(it->first);
        }
        return *this;
    }

    map_accumulate_partition &operator--()
    {
        auto it = prmap.find(current);
        if (it != prmap.begin() && it != prmap.end())
        {
            --it;
            set_partition_key(it->first);
        }
        return *this;
    }
};

#endif
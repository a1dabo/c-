#include <map>
#include <iostream>

#ifndef MAPACCPART_H
#define MAPACCPART_H

template<
    class Key,
    class T,
    class Compare = std::less<Key>,
    class Allocator = std::allocator<std::pair<const Key, T>>>
class map_accumulate_partition{
private: 
    std::map<Key, T> backup;
    std::map<Key*, T*> partioned;
public:
    map_accumulate_partition(const std::map<Key,T> inmap)
    {
        for (auto const& [key,value] : inmap) {
            backup[*key] = *value;
            partioned[key] = value;
        }
    }



};

#endif // !MAPACCPART_H

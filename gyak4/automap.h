#include <map>
#include <stdexcept>

#ifndef AUTOMAP_H
#define AUTOMAP_H

template<class Key,class T>
class auto_map{

    std::map<Key*,T*> map;

    public:

    auto_map() 
    {}

    auto_map(const auto_map& other) {
        for (const auto& [k, v] : other.map) {
            map[new Key(*k)] = new T(*v);
        }
    }


    ~auto_map()
    {
        for(auto& pair:map)
        {
            delete pair.second;
            delete pair.first;
        }
        
    }

    void insert(Key* key,T* value)
    {
        map[key]=value;
    }

    int size()
    {
        return map.size();
    }

    T& at(const Key& key) const
    {
        for (auto& [k, v] : map) 
    {
    if (*k == key) return *v;
    }
    throw std::out_of_range("Nincs ilyen kulcs");
    }
    

};

#endif
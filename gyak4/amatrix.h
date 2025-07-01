#include <map>

#ifndef AMATRIX_H
#define AMATRIX_H

template<class Key,class T>
class AssocMatrix{

    std::map<Key*,T*> mymap;

    public:
    AssocMatrix(){}

    AssocMatrix(const AssocMatrix* other) const
    {
        for (const auto& [k, v] : other.map) {
            map[new Key(*k)] = new T(*v);
        }
    }

    


};

#endif
#ifndef CONTFIND_H
#define CONTFIND_H
#include <vector>
#include <algorithm>

template <class container>
class container_finder
{
    typedef std::vector<container *> myvec;
    myvec invec;

public:
    container_finder &add_container(container &cont)
    {
        invec.push_back(&cont);
        return *this;
    }

    // pointereken végig megyunk a vectoron ami tárolja az összes tagjának cimét
    template <class It>
    container *which(const It &it)
    {
        for (auto &iter : invec)
        {
            for (auto first = iter->begin(); first != iter->end(); ++first)
                if (first == it)
                    return iter;
        }
        return nullptr;
    }

    container_finder &operator-=(container &cont)
    {
        auto ptr = which(cont.begin()); // container* típusú
        if (!ptr)
            return *this; // nem volt benne

        // keresd meg, hogy hol van a pointer a vektorban
        auto it = std::find(invec.begin(), invec.end(), ptr);
        if (it != invec.end())
            invec.erase(it);

        return *this;
    }

    container_finder &operator+=(container &cont)
    {
        invec.push_back(&cont);
        return *this;
    }

    container &operator[](container &cont)
    {
        return invec[cont];
    }
};

#endif

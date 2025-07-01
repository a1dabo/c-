#include <vector>
#include <algorithm>
#include <iostream>

#ifndef CTVTOR_H
#define CTVTOR_H

template<class T> class ctvtor;

template<class T>
bool operator==(const ctvtor<T>& lhs, const ctvtor<T>& rhs) {
    return lhs.voriginal == rhs.voriginal;
}

template<class T>
class ctvtor{
    public:
    std::vector<T> voriginal;
    std::vector<T*> vecpt;
    
    void append(T* arr,int size)
    {
        for (int i = 0; i < size; i++)
        {
            voriginal.push_back(arr[i]);
            vecpt.push_back(&arr[i]);

        }
        
    }

    void append(std::vector<T>& invec)
    {

        for(int i=0;i<invec.size();i++)
        {
        voriginal.push_back(invec[i]);
        vecpt.push_back(&invec[i]);     //cimet rak el
        }
        
    }

    //sort a pointereken keresztül átadott értékhez
    void sort() {
        std::sort(vecpt.begin(), vecpt.end(), [](T* a, T* b) {return *a < *b;}); 
    }


    void rew()
    {
        for (int i = 0; i < vecpt.size(); i++)
        {
            *vecpt[i]=voriginal[i];
        }
        
    }

    ctvtor& operator+=(int n)
    {
        for (size_t i = 0; i < vecpt.size(); i++)
        {
            *vecpt[i]+=n;
        }
        return *this;        
    }

    //postfix

    ctvtor& operator++(int)
    {
        for (size_t i = 0; i < vecpt.size(); i++)
        {
            ++*vecpt[i];
        }
        return *this;        
    }

    //prefix

    ctvtor& operator++()
    {
        for (size_t i = 0; i < vecpt.size(); i++)
        {
            ++*vecpt[i];
        }
        return *this;        
    }

    T get(int index)
    {
        return *vecpt[index];
    }
    
    std::ostream& operator<<(std::ostream& o) const
    {
        o<<"faszomat bele az egészbe"<<std::endl;
        return o;
    }


    void print()
    {
        for (size_t i = 0; i < vecpt.size(); i++)
        {
            std::cout<<*vecpt[i]<<' ';
        }
        std::cout<<std::endl;
    }

};


#endif
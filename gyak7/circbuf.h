#ifndef CIRCBUF_H
#define CIRCBUF_H

#include <vector>

template <class T>
class circular_buffer
{

    std::vector<T *> invec;

public:
    circular_buffer(T *ar, int size)
    {
        for (int i = 0; i < size; i++)
        {
            invec.push_back(&ar[i]);
        }
    }

    ~circular_buffer()
    {
        for (auto &data : invec)
        {
            delete data;
        }
    }

    void insert(T n)
    {
        if (invec[invec.size() - 1] != nullptr)
        {
            invec.push_back(new T(n));
            return;
        }

        for (int i = 0; i < invec.size(); i++)
        {
            if (invec[i] == nullptr)
            {
                invec[i] == new T(n);
                return;
            }
        }
    }

    int size()
    {
        return invec.size();
    }
};

#endif
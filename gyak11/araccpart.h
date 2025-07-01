#ifndef ARACCPART_H
#define ARACCPART_H

#include <vector>

template <class T>
class array_accumulate_partition
{

    std::vector<T *> ptrvec;
    std::vector<T> ovalue;

    int curkeyidx;

public:
    array_accumulate_partition(T *t, int size)
    {
        curkeyidx = 0;
        for (int i = 0; i < size; i++)
        {
            ptrvec.push_back(&t[i]);
            ovalue.push_back(t[i]);
        }
    }

    void reset()
    {
        for (int i = 0; i < ptrvec.size(); i++)
        {
            *ptrvec[i] = ovalue[i];
        }
    }

    void set_partition_idx(int idx)
    {
        reset();
        if (idx > 0)
        {
            T sum = T();
            for (size_t i = 0; i < idx; i++)
            {
                sum += ovalue[i];
                *ptrvec[i] = sum;
            }
            curkeyidx = idx;
        }
    }

    array_accumulate_partition &operator>>(int n)
    {
        int nsize = curkeyidx + n;
        if (nsize > ptrvec.size())
        {
            set_partition_idx(ptrvec.size());
        }
        else
        {
            set_partition_idx(nsize);
        }
        return *this;
    }

    array_accumulate_partition &operator<<(int n)
    {
        int nsize = curkeyidx - n;
        if (nsize < 0)
        {
            set_partition_idx(1);
        }
        else
        {
            set_partition_idx(nsize);
        }
        return *this;
    }
};

template <class T>
array_accumulate_partition<T> &operator<<(int n, array_accumulate_partition<T> &ap)
{
    return ap >> n;
}

template <class T>
array_accumulate_partition<T> &operator>>(int n, array_accumulate_partition<T> &ap)
{
    return ap << n;
}

#endif

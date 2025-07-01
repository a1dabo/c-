#ifndef ARVIOPS_H
#define ARVIOPS_H

#include <vector>
#include <algorithm>
#include <functional>

template <class T>
class array_view_operations
{
    std::vector<T *> ptrvec; // Eredeti tömb elemeinek címei
    std::vector<T> origin;   // Eredeti értékek, reset() miatt

public:
    // Konstruktor: elmenti a címeket és az eredeti értékeket
    array_view_operations(T *arr, int size)
    {
        for (int i = 0; i < size; ++i)
        {
            ptrvec.push_back(&arr[i]);
            origin.push_back(arr[i]);
        }
    }

    // Alternatív konstruktor: automatikus méret (tömb referencia alapján)
    template <size_t N>
    array_view_operations(T (&arr)[N]) : array_view_operations(arr, N) {}

    // Visszafordítja az értékek sorrendjét (címeket nem változtat)
    void reverse()
    {
        std::vector<T> temp;
        for (T *p : ptrvec)
            temp.push_back(*p);

        std::reverse(temp.begin(), temp.end());

        for (int i = 0; i < ptrvec.size(); ++i)
            *ptrvec[i] = temp[i];
    }

    // Visszaállítja az eredeti értékeket
    void reset()
    {
        for (int i = 0; i < ptrvec.size(); ++i)
            *ptrvec[i] = origin[i];
    }

    // Körkörös eltolás n pozícióval
    void shift(int n)
    {
        int size = ptrvec.size();
        if (size == 0)
            return;

        n = ((n % size) + size) % size; // negatív is kezelve

        std::vector<T> temp;
        for (T *p : ptrvec)
            temp.push_back(*p);

        for (int i = 0; i < size; ++i)
            *ptrvec[i] = temp[(i - n + size) % size];
    }

    // Rendezés alapértelmezett < szerint
    void sort()
    {
        std::vector<T> temp;
        for (T *p : ptrvec)
            temp.push_back(*p);

        std::sort(temp.begin(), temp.end());

        for (int i = 0; i < ptrvec.size(); ++i)
            *ptrvec[i] = temp[i];
    }

    // Rendezés adott predikátum szerint
    template <typename Comp>
    void sort(Comp comp)
    {
        std::vector<T> temp;
        for (T *p : ptrvec)
            temp.push_back(*p);

        std::sort(temp.begin(), temp.end(), comp);

        for (int i = 0; i < ptrvec.size(); ++i)
            *ptrvec[i] = temp[i];
    }

    // Visszaadja az első indexet, amelyre a predikátum igaz, vagy -1-et ha nincs
    template <typename Predicate>
    int get_first_index_if(Predicate pred)
    {
        for (int i = 0; i < ptrvec.size(); ++i)
        {
            if (pred(*ptrvec[i]))
                return i;
        }
        return -1;
    }
};

#endif

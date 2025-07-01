#ifndef AUTOSET_H
#define AUTOSET_H

#include <set>

template <typename T, typename Compare>
struct PtrCompare
{
    Compare cmp;
    PtrCompare() = default;
    PtrCompare(const Compare &c) : cmp(c) {}
    bool operator()(const T *a, const T *b) const
    {
        return cmp(*a, *b);
    }
};

template <class T, class Compare = std::less<T>>
class auto_set
{
    std::set<T *, PtrCompare<T, Compare>> inset;

public:
    auto_set(const Compare &comp = Compare()) : inset(PtrCompare<T, Compare>(comp)) {}

    // Másoló konstruktor (deep copy!)
    auto_set(const auto_set &other)
    {
        for (auto ptr : other.inset)
            inset.insert(new T(*ptr));
    }

    // Másoló értékadó (deep copy!)
    auto_set &operator=(const auto_set &other)
    {
        if (this != &other)
        {
            for (auto ptr : inset)
                delete ptr;
            inset.clear();
            for (auto ptr : other.inset)
                inset.insert(new T(*ptr));
        }
        return *this;
    }

    ~auto_set()
    {
        for (auto dk : inset)
            delete dk;
    }

    void insert(const T *t)
    {
        for (auto &value : inset)
        {
            if (*value == *t)
            {
                delete t;
                return;
            }
        }
        inset.insert(new T(*t));
        delete t;
    }

    int size() const
    {
        return inset.size();
    }

    void erase(const T &t)
    {
        for (auto it = inset.begin(); it != inset.end(); ++it)
        {
            if (**it == t)
            {
                delete *it;
                inset.erase(it);
                return;
            }
        }
    }

    void erase(typename std::set<T *>::const_iterator first, typename std::set<T *>::const_iterator last)
    {
        auto it = first;
        while (it != last)
        {
            delete *it;
            it = inset.erase(it); // erase visszaadja a következő érvényes iterátort
        }
    }

    auto begin() const { return inset.begin(); }
    auto end() const { return inset.end(); }
};

#endif
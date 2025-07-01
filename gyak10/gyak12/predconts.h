#ifndef PREDCONTS_H
#define PREDCONTS_H

#include <algorithm>
#include <deque>
#include <list>
#include <vector>
#include <string>

template <typename Container, typename Predicate, typename T = typename Container::value_type>
class predicate_containers
{
private:
    Container &c_true;
    Container &c_false;
    Predicate pred;

public:
    predicate_containers(Container &ct, Container &cf, Predicate p = Predicate())
        : c_true(ct), c_false(cf), pred(p)
    {
        ct.clear();
        cf.clear();
    }

    predicate_containers &insert(const T &value)
    {
        if (pred(value))
        {
            c_true.push_back(value);
        }
        else
        {
            c_false.push_back(value);
        }
        return *this;
    }

    template <typename InputIterator>
    void insert(InputIterator first, InputIterator last)
    {
        for (; first != last; ++first)
        {
            insert(*first);
        }
    }

    predicate_containers &erase(const T &value)
    {
        remove_from_container(c_true, value);
        remove_from_container(c_false, value);
        return *this;
    }

    size_t size() const
    {
        return c_true.size() + c_false.size();
    }

    predicate_containers &operator+=(const predicate_containers &other)
    {
        insert(other.c_true.begin(), other.c_true.end());
        insert(other.c_false.begin(), other.c_false.end());
        return *this;
    }

private:
    void remove_from_container(Container &c, const T &value)
    {
        c.erase(std::remove(c.begin(), c.end(), value), c.end());
    }
};

#endif
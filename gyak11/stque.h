#ifndef STQUE_H
#define STQUE_H

#include <stack>
#include <queue>
#include <type_traits>

template <class T, bool isStack, class Container = std::deque<T>>
class StackQueue
{

    using InConLib = typename std::conditional<isStack, std::stack<T, Container>, std::queue<T, Container>>::type;

    InConLib instl;

public:
    void push(const T &t)
    {
        instl.push(t);
    }

    T &get()
    {
        if constexpr (isStack)
        {
            return instl.top();
        }
        else
        {
            return instl.front();
        }
    }

    const T &get() const
    {
        if constexpr (isStack)
        {
            return instl.top();
        }
        else
        {
            return instl.front();
        }
    }

    int size() const
    {
        return instl.size();
    }

    bool empty()
    {
        return instl.empty();
    }

    void pop()
    {
        instl.pop();
    }
};

#endif
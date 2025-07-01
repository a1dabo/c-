#ifndef PSTACK_H
#define PSTACK_H

#include <map>
#include <stack>

template <class T, class Pr = int, class Compare = std::less<Pr>>
class priority_stack
{
    std::map<Pr, std::stack<T>, Compare> invec;

public:
    void push(const Pr &pr, const T &t)
    {
        invec[pr].push(t);
    }

    const int size(const Pr &pr) const
    {
        for (auto &pair : invec)
        {
            if (pair.first == pr)
                return pair.second.size();
        }
        return 0;
    }

    int size() const
    {
        int count = 0;
        for (auto &pair : invec)
        {
            count += pair.second.size();
        }
        return count;
    }

    T &top()
    {
        return invec.rbegin()->second.top();
    }
    const T &top() const
    {
        return invec.rbegin()->second.top();
    }

    void pop()
    {
        if (invec.empty())
            return;
        auto it = std::prev(invec.end()); // legnagyobb prioritású stack
        it->second.pop();
        if (it->second.empty())
            invec.erase(it);
    }
};

#endif
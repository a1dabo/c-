#define BIMAP_H
#include <map>

template <class Key, class T>
class BidirectionalMap
{
    std::map<Key, T> KeyAndT;
    std::map<T, Key> TAndKey;

public:
    void insert(const Key &key, const T &t)
    {
        KeyAndT[key] = t;
        TAndKey[t] = key;
    }

    const Key &at(const T &t) const
    {
        for (const auto &pair : KeyAndT)
        {
            if (pair.second == t)
                return pair.first;
        }
    }

    const T &at(const Key &key) const
    {
        for (auto &pair : KeyAndT)
        {
            if (pair.first == key)
                return pair.second;
        }
    }

    int size() const
    {
        return KeyAndT.size();
    }

    int count(const Key &key) const
    {
        return KeyAndT.count(key);
    }

    int count(const T &t) const
    {
        return TAndKey.count(t);
    }

    T &operator[](const Key &key)
    {
        return KeyAndT[key];
    }

    Key &operator[](const T &t)
    {
        return TAndKey[t];
    }
};

template <>
class BidirectionalMap<int, int>
{
    std::map<int, int> KeyAndT;
    std::map<int, int> TAndKey;

public:
    void insert(const int &key, const int &t)
    {
        KeyAndT[key] = t;
        TAndKey[t] = key;
    }

    const int &at(const int &t) const
    {
        for (const auto &pair : KeyAndT)
        {
            if (pair.second == t)
                return pair.first;
            if (pair.first == t)
                return pair.second;
        }
    }

    int size() const
    {
        return KeyAndT.size();
    }

    int count(const int &key) const
    {
        return (KeyAndT.count(key) + TAndKey.count(key));
    }

    const int &operator[](const int &key) const
    {
        for (auto &pair : KeyAndT)
        {
            if (pair.second == key)
            {

                return pair.first;
            }
            if (pair.first == key)
                return pair.second;
        }
    }

    auto begin() const { return KeyAndT.begin(); }
    auto end() const { return KeyAndT.end(); }
};
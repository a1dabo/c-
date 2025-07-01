#ifndef AUTOLIST_H
#define AUTOLIST_H

#include <vector>

template<class T>
class auto_list {
    std::vector<T*> ves;

public:
    auto_list() = default;

    // Másoló konstruktor: mély másolat!
    auto_list(const auto_list& other) {
        for (T* ptr : other.ves) {
            ves.push_back(new T(*ptr)); // új példány másolással
        }
    }

    // Destruktor: felszabadítja az összes példányt
    ~auto_list() {
        for (T* ptr : ves) {
            delete ptr;
        }
    }

    void push_front(T* in) {
        ves.insert(ves.begin(), in);
    }

    void push_back(T* in) {
        ves.push_back(in);
    }

    T& front() {
        return *ves[0];
    }

    int size() const {
        return ves.size();
    }
};

#endif

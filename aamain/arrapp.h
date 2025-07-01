#ifndef ARRAPP_H
#define ARRAPP_H

#include <vector>

template<class T>
class array_appender {
private:
    std::vector<const T*> array;

public:
    array_appender(const T* inar, int size) {
        for (int i = 0; i < size; ++i) {
            array.push_back(inar[i]);
        }
    }

    void append(const T* inar, int size) {
        for (int i = 0; i < size; ++i) {
            array.push_back(inar[i]);
        }
    }

    T& at(int index) {
        return array.at(index);
    }

    const T& at(int index) const {
        return array.at(index);
    }

    int size() {
        return array.size();
    }

    int size() const {
        return array.size();
    }

    T& operator[](int index) {
        return array[index];
    }

    const T& operator[](int index) const {
        return array[index];
    }

    typename std::vector<T>::iterator begin() { return array.begin(); }
    typename std::vector<T>::iterator end() { return array.end(); }

    typename std::vector<T>::const_iterator begin() const { return array.begin(); }
    typename std::vector<T>::const_iterator end() const { return array.end(); }
};

#endif

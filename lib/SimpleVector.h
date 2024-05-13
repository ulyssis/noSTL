// SimpleVector.h
#pragma once

#include <cstddef> // for size_t

class SimpleVector
{
private:
    int *array;
    size_t capacity;
    size_t current; // current size of the vector, it is also the index of the next element to be added

public:
    SimpleVector() : array(nullptr), capacity(0), current(0) {}

    ~SimpleVector()
    {
        delete[] array;
    }

    void push_back(const int &item);
    int &operator[](size_t index);
    size_t size() const;
    size_t get_capacity() const;
    bool is_empty() const;
    int pop_back();
    void clear();
    // Additional member functions...
};
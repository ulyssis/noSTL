// SimpleVector.h
#pragma once

#include <cstddef> // for size_t
#include "ErrorCode.h"

template <typename T>
class SimpleVector
{
private:
    T *array;
    size_t capacity;
    size_t current; // current size of the vector, it is also the index of the next element to be added

public:
    SimpleVector() : array(nullptr), capacity(0), current(0) {}

    ~SimpleVector()
    {
        delete[] array;
    }

    void push_back(const T &item);
    T &operator[](size_t index);
    size_t size() const;
    size_t get_capacity() const;
    bool is_empty() const;
    int pop_back();
    void clear();
    // Additional member functions...
};

template <typename T>
void SimpleVector<T>::push_back(const T &item)
{
    if (current >= capacity)
    {
        size_t newCapacity = capacity == 0 ? 1 : capacity * 2;
        T *newArray = new T[newCapacity];
        for (size_t i = 0; i < current; i++)
        {
            newArray[i] = array[i];
        }
        newArray[current++] = item;
        delete[] array;
        array = newArray;
        capacity = newCapacity;
    }
    else
    {
        array[current++] = item;
    }
}

template <typename T>
T &SimpleVector<T>::operator[](size_t index)
{
    return array[index]; // Add bounds checking in production code
}

template <typename T>
size_t SimpleVector<T>::size() const
{
    return current;
}

template <typename T>
size_t SimpleVector<T>::get_capacity() const
{
    return capacity;
}

template <typename T>
bool SimpleVector<T>::is_empty() const
{
    return size() == 0;
}

template <typename T>
int SimpleVector<T>::pop_back()
{
    if (current == 0)
    {
        // throw std::out_of_range("Vector is empty");
        return static_cast<int>(ErrorCode::OutOfRange);
    }
    return array[--current];
}

template <typename T>
void SimpleVector<T>::clear()
{
    current = 0;
}

// SimpleVector.cpp
#include <cstddef> // for size_t
#include <iostream>
#include "SimpleVector.h"
#include "ErrorCode.h"

void SimpleVector::push_back(const int &item)
{
    if (current >= capacity)
    {
        size_t newCapacity = capacity == 0 ? 1 : capacity * 2;
        int *newArray = new int[newCapacity];
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

int &SimpleVector::operator[](size_t index)
{
    return array[index]; // Add bounds checking in production code
}

size_t SimpleVector::size() const
{
    return current;
}

size_t SimpleVector::get_capacity() const
{
    return capacity;
}

bool SimpleVector::is_empty() const
{
    return size() == 0;
}

// // More functions can be added as needed
// pop_back(): Removes the last element from the vector, which is useful for stack-like behavior.

int SimpleVector::pop_back()
{
    if (current == 0)
    {
        // throw std::out_of_range("Vector is empty");
        return static_cast<int>(ErrorCode::OutOfRange);
    }
    return array[--current];
}
// clear(): Removes all elements from the vector, resetting its size to zero without reducing its capacity.

void SimpleVector::clear()
{
    current = 0;
}
// resize(size_t newSize, int defaultValue = int()): Changes the size of the vector to newSize, initializing new elements with defaultValue if it grows.
// shrink_to_fit(): Reduces the capacity of the vector to fit its current size, potentially freeing up memory.
// front() and back(): Provides access to the first and last element, respectively.
// insert(size_t index, const int& item): Inserts item at the specified index.
// erase(size_t index): Removes the element at the specified index.
// find(const int& item): Returns the index of item if found, or some indicator (like the vector size) if not.
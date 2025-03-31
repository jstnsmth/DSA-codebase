#ifndef ARRAY_STATIC_H
#define ARRAY_STATIC_H

#include <algorithm>
#include <initializer_list>
#include <stdexcept>

template <typename T>
class StaticArray {
public:
    StaticArray(int capacity)
        : arr (new T[capacity])
        , capacity (capacity)
        {}

    StaticArray(std::initializer_list<T> list)
        : StaticArray(static_cast<int>(list.size()))
    {
         std::size_t index = 0;
        for (const T& value : list) {
            arr[index++] = value;
        }
    }

    StaticArray(const StaticArray& rhs) {
        arr = new T[capacity];

        for (int i = 0; i < capacity; i++) {
            arr[i] = rhs.arr[i];
        }
    }

    ~StaticArray() {
        delete[] arr;
    }

    T& operator[](const int index) {
        if (index < 0 || index >= capacity) {
            throw std::out_of_range("Index is out of bounds");
        }
        return arr[index];
    }

    bool isEmpty() const {
        return capacity == 0;
    }

    T& get(const int index) {
        if (index < 0 || index >= capacity) {
            throw std::out_of_range("Index is out of range");
        }
        return arr[index];
    }

    int getCapacity() const {
        return capacity;
    }

private:
    T* arr{};
    int capacity{};
};

#endif

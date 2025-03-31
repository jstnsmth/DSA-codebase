#ifndef ARRAY_STATIC_H
#define ARRAY_STATIC_H

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

    StaticArray(const StaticArray& rhs)
        : arr(new T[rhs.capacity])
        , capacity(rhs.capacity)
    {
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

    StaticArray& operator=(const StaticArray& rhs) {
        if (this == &rhs) return *this;

        delete[] arr;

        arr = new T[rhs.capacity];
        capacity = rhs.capacity;
        size = rhs.size;

        for (int i = 0; i < size; i++) {
            arr[i] = rhs.arr[i];
        }
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const DynamicArray& rhs) {
        os << "[";
        for (int i = 0; i < rhs.size; i++) {
            os << rhs.arr[i];
            if (i != rhs.size-1) {
                os << ", ";
            }
        }
        os << "]\n";
        return os;
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

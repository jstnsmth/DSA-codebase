#ifndef ARRAY_DYNAMIC_H
#define ARRAY_DYNAMIC_H

#include <initializer_list>
#include <stdexcept>
#include <iostream>

// TODO: bug with copy constructor
// TODO: arr[i] = i; doesn't work. should work and increase size

template <typename T>
class DynamicArray {
public:
    DynamicArray(int capacity)
        : arr (new T[capacity])
        , capacity (capacity)
        , size (0)
        {}

    DynamicArray(std::initializer_list<T> list)
        : DynamicArray(static_cast<int>(list.size()))
    {
        for (const T& value : list) {
            push_back(value);
        }
    }

    DynamicArray(const DynamicArray& rhs) {
        arr = new T[capacity];
        capacity = rhs.capacity;

        for (int i = 0; i < rhs.size; i++) {
            push_back(rhs[i]);
        }
    }

    ~DynamicArray() {
        delete[] arr;
    }

    void push_back(const T& data) {
        if (size == capacity) {
            resize();
        }
        arr[size++] = data;
    }

    void pop_back() {
        if (size == 0) {
            throw std::out_of_range("Array is empty, nothing to pop.");
        }
        else {
            size--;
        }
    }

    T& operator[](const int index) {
        if (index < 0 || index >= capacity) {
            throw std::out_of_range("Index is out of bounds");
        }
        return arr[index];
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

    T& get(const int index) {
        if (index < 0 || index >= capacity) {
            throw std::out_of_range("Index is out of range");
        }
        return arr[index];
    }

    bool isEmpty() const {
        return size == 0;
    }

    int getSize() const {
        return size;
    }

    int getCapacity() const {
        return capacity;
    }

private:
    T* arr{};
    int capacity{};
    int size{};

    void resize() {
        capacity*=2;
        T* newArr = new T[capacity];
        for (int i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        std::cout << "resized.";
    }
};

#endif

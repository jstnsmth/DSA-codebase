#include <iostream>
#include "array_static.h"
#include "array_dynamic.h"

int main() {
    DynamicArray<int> arr(4);
    arr.push_back(1);

    std::cout << arr;

    DynamicArray<int> arr2 = arr;
    std::cout << arr2;
    arr2[0] = 1;
    std::cout << arr2[0];
}

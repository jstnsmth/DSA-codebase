#include <iostream>
#include "array_static.h"
#include "array_dynamic.h"

int main() {
    DynamicArray<int> arr(4);
    for (int i = 0; i < 4; i++) {;
        arr.push_back(i);
    }
    std::cout << arr;

    DynamicArray<int> arr2(4);
    arr2 = arr;
}

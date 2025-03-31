#include <iostream>
#include "array_static.h"
#include "array_dynamic.h"

int main() {
    StaticArray<int> arr = {1,2,3,4};
    std::cout << arr;
}

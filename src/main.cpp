#include <iostream>
#include "array_static.h"
#include "array_dynamic.h"
#include "singly_linkedlist.h"
#include "binarysearch.h"
#include "linearsearch.h"

int main() {
    StaticArray<int> arr = {1,2,3,4,5};
    std::cout << linearSearchArray(arr, 5);
}

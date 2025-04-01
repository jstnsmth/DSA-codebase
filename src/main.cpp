#include <iostream>
#include "array_static.h"
#include "array_dynamic.h"
#include "singly_linkedlist.h"
#include "binarysearch.h"
#include "mergesort.h"
#include "linearsearch.h"

int main() {
    StaticArray<int> arr = {5,8,7,9,1,2,6,1,3};
    mergeSort<StaticArray<int>, int>(arr, 0, arr.getSize()-1);
    std::cout << arr;
}

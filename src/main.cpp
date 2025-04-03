#include <iostream>
#include "array_static.h"
#include "array_dynamic.h"
#include "singly_linkedlist.h"
#include "binarysearch.h"
#include "mergesort.h"
#include "linearsearch.h"
#include "bubblesort.h"
#include "insertionsort.h"

int main() {
    DynamicArray<int> arr = {5,8,7,9,1,2,6,1,3};
    insertionSort<DynamicArray<int>, int>(arr);
    std::cout << arr;
}


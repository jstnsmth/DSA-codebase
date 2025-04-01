#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

template <typename ArrayType, typename T>
int binarySearch(ArrayType& arr, const T& target) {
    int left = 0;
    int right = arr.getSize() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

#endif

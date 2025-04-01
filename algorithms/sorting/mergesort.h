#ifndef MERGESORT_H
#define MERGESORT_H

#include "array_dynamic.h"

template <typename ArrayType, typename T>
void merge(ArrayType& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    DynamicArray<T> L(n1), R(n2);

    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }

    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + j + 1];
    }

    int i = 0, j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

template <typename ArrayType, typename T>
void mergeSort(ArrayType& arr, int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    mergeSort<ArrayType, T>(arr, left, mid);
    mergeSort<ArrayType, T>(arr, mid+1, right);
    merge<ArrayType, T>(arr, left, mid, right);
}

#endif

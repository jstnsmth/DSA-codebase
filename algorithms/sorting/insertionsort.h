#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

template <typename ArrayType, typename T>
void insertionSort(ArrayType& arr) {
    for (int i = 1; i < arr.getSize(); i++) {
        T key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

#endif

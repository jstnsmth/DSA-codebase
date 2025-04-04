#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

template <typename ArrayType, typename T>
void selectionSort(ArrayType& arr) {
    for (int i = 0; i < arr.getSize(); i++) {
        int min_index = i;
        for (int j = i+1; j < arr.getSize(); j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        T temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

#endif

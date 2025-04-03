#ifndef BUBBLESORT_H
#define BUBBLESORT_H

template <typename ArrayType, typename T>
void bubbleSort(ArrayType& arr) {
    int size = arr.getSize();
    for (int i = 0; i < size-1; i++) {
        bool swapped = false;
        for (int j = 0; j < size-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                T temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

#endif

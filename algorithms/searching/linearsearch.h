#ifndef LINEARSEARCH_H
#define LINEARSEARCH_H

template <typename ArrayType, typename T>
int linearSearchArray(ArrayType& arr, const T& target) {
    for (int i = 0; i < arr.getSize(); i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

template <typename ListType, typename T>
int linearSearchLinkedList(ListType& list, const T& target) {
    int currentIndex = 0;
    auto curr = list.getHead();

    while (curr != nullptr) {
        if (curr->data == target) {
            return currentIndex;
        }
        else {
            curr = curr->next;
            currentIndex++;
        }
    }
    return -1;
}

#endif

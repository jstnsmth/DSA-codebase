#include <iostream>
#include "array_static.h"
#include "array_dynamic.h"
#include "singly_linkedlist.h"

int main() {
    SinglyLinkedList<int> ll = {1,2,3,4};
    ll.reverse();
    ll.display();
}

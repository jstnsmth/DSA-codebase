#include <iostream>
#include "array_static.h"
#include "array_dynamic.h"
#include "singly_linkedlist.h"

int main() {
    SinglyLinkedList<int> ll;
    ll.addFirst(2);
    ll.add(4);
    ll.add(3);
    ll.display();
}

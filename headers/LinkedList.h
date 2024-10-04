#include "Node.h"

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class LinkedList{
private:
    Node* head;

public:
    LinkedList();
    void add(int data);
    void addFirst(int data);
    void remove(int data);
    bool contains(int data);
    bool isEmpty();
    void removeFirst();
    void removeLast();
    int size();
    // void sort();
    // toArray() -> Object[]
    int indexOf(int data);
    Node* get(int index);
    LinkedList* clone(LinkedList* linkedlist);
    void display();
    void reverse();
    // void clear();
    // void descendingIterator();

};

#endif
#include <iostream>
#include "LinkedList.h"
#include "Node.h"

LinkedList::LinkedList() {
    head = nullptr;
}

void LinkedList::add(int value) {
    Node* cur = head;
    Node* newNode = new Node(value);

    if (head == nullptr) {
        head = newNode;
    }
    else {
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        cur->next = newNode;
    }
}

void LinkedList::addFirst(int value) {
    Node* curr = head;
    Node* newNode = new Node(value);
    newNode->next = curr;
    head = newNode;
}

void LinkedList::remove(int value) {
    Node* curr = head;
    Node* prev = nullptr;
    if (head == nullptr) {
        return;
    }

    if (head->data == value) {
        Node* curr = head;
        head = head->next;
        delete head;
        return;
    }

    while (curr != nullptr) {
        if (curr->data == value) {
            prev->next = curr->next;
            delete curr;
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

void LinkedList::removeFirst() {
    if (head == nullptr) {
        return;
    }

    Node* curr = head;
    head = head->next;
    delete curr;
}

void LinkedList::removeLast() {
    if (head == nullptr) {
        return;
    }

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }
    Node* curr = head;
    while (curr->next->next != nullptr) {
        curr = curr->next;
    }
    delete curr->next;
    curr->next = nullptr;
}

bool LinkedList::contains(int value) {
    Node* curr = head;

    if (head == nullptr) {
        return false;
    }
    else {
        while (curr != nullptr) {
            if (curr->data == value) {
                return true;
            }
            curr = curr->next;
        }
    }
    return false;
}

int LinkedList::indexOf(int value) {
    Node* curr = head;
    int index = 0;
    
    while (curr != nullptr) {
        if (curr->data == value) {
            return index;
        }
        else {
            index++;
        }
    }
    return -1;
}

Node* LinkedList::get(int index) {
    Node* curr = head;
    int counter = 0;
    
    while (curr != nullptr) {
        if (counter == index) {
            return curr;
        }
        else {
            curr = curr->next;
            counter++;
        }
    }
    return nullptr;
}

bool LinkedList::isEmpty() {
    Node* curr = head;
    if (curr == nullptr) {
        return true;
    }
    return false;
}

int LinkedList::size() {
    Node* curr = head;
    int counter = 0;
    while (curr != nullptr) {
        curr = curr->next;
        counter++;
    }
    return counter;
}

void LinkedList::display() {
    Node* curr = head;

    if (head == nullptr) {
        std::cout << "Empty" << std::endl;
    }
    while (curr != nullptr) {
        std::cout << curr->data << " ";
        curr = curr->next;
    }
    std::cout << std::endl;
}

void LinkedList::reverse() {
    Node* prev = nullptr;
    Node* curr = head;
    Node* next;
    
    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

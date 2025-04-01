#ifndef SINGLY_LINKEDLIST_H
#define SINGLY_LINKEDLIST_H

#include <iostream>
#include <initializer_list>
#include "array_dynamic.h"

template <typename T>
class SinglyLinkedList {
private:
    struct Node {
        T data;
        Node* next;
    };
    Node* head;

    Node* newNode(const T& data) const {
        return new Node({data, nullptr});
    }

public:
    SinglyLinkedList()
    : head (nullptr)
    {}

    SinglyLinkedList(const T& data)
    : head (newNode(data))
    {}

    SinglyLinkedList(std::initializer_list<T> list)
    {
        head = nullptr;
        Node* curr = head;
        for (const T& value : list) {
            if (head == nullptr) {
                head = newNode(value);
                curr = head;
            }
            else {
                curr->next = newNode(value);
                curr = curr->next;
            }
        }
    }

    SinglyLinkedList(const SinglyLinkedList& rhs)
        : head (nullptr)
    {
        Node* rhs_curr = rhs.head;
        Node* lhs_curr = head;

        while (rhs_curr != nullptr) {
            if (head == nullptr) {
                head = newNode(rhs_curr->data);
                lhs_curr = head;
                rhs_curr = rhs_curr->next;
            }
            else {
                lhs_curr->next = newNode(rhs_curr->data);
                lhs_curr = lhs_curr->next;
                rhs_curr = rhs_curr->next;
            }
        }
    }

    ~SinglyLinkedList() {
        clear();
    }

    SinglyLinkedList& operator=(const SinglyLinkedList& rhs) {
        if (this == &rhs) return *this;

        clear();

        Node* rhs_curr = rhs.head;
        Node* lhs_curr = head;

        while (rhs_curr != nullptr) {
            if (head == nullptr) {
                head = newNode(rhs.head->data);
                lhs_curr = head;
                rhs_curr = rhs_curr->next;
            }
            else {
                lhs_curr->next = newNode(rhs_curr->data);
                lhs_curr = lhs_curr->next;
                rhs_curr = rhs_curr->next;
            }
        }
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const SinglyLinkedList& rhs) {
        if (rhs.head == nullptr) {
            os << "()\n";
        }
        else {
            Node* curr = rhs.head;
            os << "(";
            while (curr != nullptr) {
                os << curr->data;
                if (curr->next != nullptr) {
                    os << ", ";
                }
                curr = curr->next;
            }
            os << ")\n";
        }
        return os;
    }

    void add(const T& data) {
        if (head == nullptr) {
            head = newNode(data);
        }
        else {
            Node* curr = head;
            while (curr->next != nullptr) {
                curr = curr->next;
            }
            curr->next = newNode(data);
        }
    }

    void addFirst(const T& data) {
        Node* node = newNode(data);
        node->next = head;
        head = node;
    }

    void remove(const T& data) {
        if (head == nullptr) {
            std::cout << "List is empty.\n";
            return;
        }

        Node* curr = head;
        if (head->data == data) {
            head = head->next;
            delete curr;
            return;
        }

        while (curr->next != nullptr) {
            if (curr->next->data == data) {
                curr->next = curr->next->next;
                delete curr->next;
                return;
            }
            curr = curr->next;
        }
        std::cout << "Node does not exist.\n";
    }

    void removeFirst() {
        if (head == nullptr) return;

        Node* curr = head;
        head = head->next;
        delete curr;
    }

    void removeLast() {
        if (head == nullptr) return;

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        Node* curr = head;
        Node* prev = nullptr;
        while (curr->next != nullptr) {
            prev = curr;
            curr = curr->next;
        }
        delete curr;
        prev->next = nullptr;
    }

    DynamicArray<T> toArray() {
        DynamicArray<T> arr;
        Node* curr = head;

        while (curr != nullptr) {
            arr.push_back(curr->data);
            curr = curr->next;
        }
        return arr;
    }

    int size() const {
        if (head == nullptr) return 0;

        int size = 0;
        Node* curr = head;
        while (curr != nullptr) {
            size++;
            curr = curr->next;
        }
        return size;
    }

    int indexOf(const T& data) const {
        if (head == nullptr) return -1;

        int index = 0;
        Node* curr = head;
        while (curr != nullptr) {
            if (curr->data == data) {
                return index;
            }
            index++;
            curr = curr->next;
        }
        return -1;
    }

    Node* get(const int index) const {
        if (head == nullptr) return nullptr;

        Node* curr = head;
        int currentIndex = 0;
        while (curr != nullptr) {
            if (currentIndex == index) {
                return curr;
            }
            curr = curr->next;
        }
        return nullptr;
    }

    Node* getHead() {
        return head;
    }

    void reverse() {
        if (head == nullptr) return;

        Node* curr = head;
        Node* prev = nullptr;
        Node* temp = nullptr;

        while (curr != nullptr) {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        head = prev;
    }

    bool contains(const T& data) const {
        if (head == nullptr) return false;

        Node* curr = head;
        while (curr != nullptr) {
            if (curr->data == data) {
                return true;
            }
            curr = curr->next;
        }
        return false;
    }

    void clear() {
        if (head == nullptr) return;

        Node* curr = head;

        while (head != nullptr) {
            head = head->next;
            delete curr;
            curr = head;
        }
        head = nullptr;
    }

    bool isEmpty() const {
        return head == nullptr;
    }

    void display() const {
        if (head == nullptr) {
            std::cout << "()\n";
        }
        else {
            Node* curr = head;
            std::cout << "(";
            while (curr != nullptr) {
                std::cout << curr->data;
                if (curr->next != nullptr) {
                    std::cout << ", ";
                }
                curr = curr->next;
            }
            std::cout << ")\n";
        }
    }
};

#endif

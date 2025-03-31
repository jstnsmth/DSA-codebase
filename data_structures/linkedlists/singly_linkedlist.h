#ifndef SINGLY_LINKEDLIST_H
#define SINGLY_LINKEDLIST_H

#include <iostream>

template <typename T>
class SinglyLinkedList {
private:
    struct Node {
        T data;
        Node* next;
    };
    Node* head;

    Node* newNode(T data) {
        return new Node({data, nullptr});
    }

public:
    SinglyLinkedList()
    : head (nullptr)
    {}

    SinglyLinkedList(T data)
    : head (newNode(data))
    {}

    void add(T data) {
        if (head == nullptr) {
            head = newNode(data);
        }
        else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode(data);
        }
    }

    void addFirst(T data) {
        Node* node = newNode(data);
        node->next = head;
        head = node;
    }

    void remove(T data) {
        if (head == nullptr) {
            std::cout << "List is empty.\n";
            return;
        }

        if (head->data == data) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            if (temp->next->data == data) {
                temp->next = temp->next->next;
                delete temp->next;
                return;
            }
            temp = temp->next;
        }
        std::cout << "Node does not exist.\n";
    }

    bool contains(T data) const {
        if (head == nullptr) return false;

        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == data) {
                return true;
            }
            temp = temp->next;
        }
    }

    bool isEmpty() const {
        return head == nullptr;
    }

    void display() const {
        if (head == nullptr) {
            std::cout << "List is empty.\n";
        }
        else {
            Node* temp = head;
            std::cout << "(";
            while (temp != nullptr) {
                std::cout << temp->data;
                if (temp->next != nullptr) {
                    std::cout << ", ";
                }
                temp = temp->next;
            }
            std::cout << ")\n";
        }
    }
};

#endif

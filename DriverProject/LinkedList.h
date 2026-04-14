#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include "Driver.h"
using namespace std;

class LinkedList {
private:
    struct Node {
        Driver data;
        Node* prev;
        Node* next;

        Node(const Driver& value) : data(value), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int sz;

public:
    LinkedList();
    ~LinkedList();

    void insertAtBeginning(const Driver& value);
    void insertAtEnd(const Driver& value);
    bool insertAfterID(const string& targetID, const Driver& value);

    void displayList() const;
    bool isEmpty() const;
};

#endif
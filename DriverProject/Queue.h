#ifndef QUEUE_H
#define QUEUE_H

#include "Driver.h"

class Queue {
private:
    struct Node {
        Driver data;
        Node* next;

        Node(const Driver& d) : data(d), next(nullptr) {}
    };

    Node* front;
    Node* rear;

public:
    Queue();
    ~Queue();

    void enqueue(const Driver& d);
    Driver dequeue();
    bool isEmpty() const;
};

#endif
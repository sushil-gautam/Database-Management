#ifndef STACK_H
#define STACK_H

#include "Driver.h"

class Stack {
private:
    Driver* data;
    int capacity;
    int topIndex;

public:
    Stack(int cap = 200);
    ~Stack();

    bool isEmpty() const;
    bool isFull() const;

    void push(const Driver& d);
    Driver pop();
    Driver peek() const;
};

#endif
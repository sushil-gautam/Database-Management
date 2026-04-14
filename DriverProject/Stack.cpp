#include "Stack.h"
#include <iostream>
using namespace std;

Stack::Stack(int cap) {
    capacity = cap;
    data = new Driver[capacity];
    topIndex = -1;
}

Stack::~Stack() {
    delete[] data;
}

bool Stack::isEmpty() const {
    return topIndex == -1;
}

bool Stack::isFull() const {
    return topIndex == capacity - 1;
}

void Stack::push(const Driver& d) {
    if (isFull()) {
        cout << "Stack is full, cannot push.\n";
        return;
    }
    topIndex++;
    data[topIndex] = d;
}

Driver Stack::pop() {
    if (isEmpty()) {
        cout << "Stack is empty, cannot pop.\n";
        return Driver();
    }
    Driver temp = data[topIndex];
    topIndex--;
    return temp;
}

Driver Stack::peek() const {
    if (isEmpty()) {
        return Driver();
    }
    return data[topIndex];
}
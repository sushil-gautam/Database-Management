#include "Queue.h"
#include <iostream>
using namespace std;

Queue::Queue() {
    front = rear = nullptr;
}

Queue::~Queue() {
    while (!isEmpty()) {
        dequeue();
    }
}

void Queue::enqueue(const Driver& d) {
    Node* newNode = new Node(d);

    if (!rear) {
        front = rear = newNode;
        return;
    }

    rear->next = newNode;
    rear = newNode;
}

Driver Queue::dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return Driver();
    }

    Node* temp = front;
    Driver d = temp->data;

    front = front->next;
    if (!front)
        rear = nullptr;

    delete temp;
    return d;
}

bool Queue::isEmpty() const {
    return front == nullptr;
}
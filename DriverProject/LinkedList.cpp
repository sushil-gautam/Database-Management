#include "LinkedList.h"

LinkedList::LinkedList() {
    head = nullptr;
    tail = nullptr;
    sz = 0;
}

LinkedList::~LinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}

void LinkedList::insertAtBeginning(const Driver& value) {
    Node* newNode = new Node(value);

    if (head == nullptr) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    sz++;
}

void LinkedList::insertAtEnd(const Driver& value) {
    Node* newNode = new Node(value);

    if (head == nullptr) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    sz++;
}

bool LinkedList::insertAfterID(const string& targetID, const Driver& value) {
    Node* current = head;

    while (current != nullptr && current->data.getLicenseID() != targetID) {
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Driver ID not found.\n";
        return false;
    }

    Node* newNode = new Node(value);
    newNode->next = current->next;
    newNode->prev = current;

    if (current->next != nullptr) {
        current->next->prev = newNode;
    } else {
        tail = newNode;
    }

    current->next = newNode;
    sz++;
    return true;
}

void LinkedList::displayList() const {
    Node* current = head;
    while (current != nullptr) {
        current->data.display();
        cout << "--------------------------" << endl;
        current = current->next;
    }
}

bool LinkedList::isEmpty() const {
    return head == nullptr;
}
#include <iostream>
#include "HashTable.h"

using namespace std;

HashTable::HashTable(int cap) {
    capacity = cap;
    size = 0;

    table = new Node*[capacity];
    for (int i = 0; i < capacity; i++) {
        table[i] = nullptr;
    }
}

HashTable::~HashTable() {
    for (int i = 0; i < capacity; i++) {
        Node* current = table[i];
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
    delete[] table;
}

int HashTable::hashFunction(string key) const {
    int hash = 0;
    for (int i = 0; i < (int)key.length(); i++) {
        hash = (hash * 31 + key[i]) % capacity;
    }
    return hash;
}

void HashTable::insert(const Driver& driver) {
    string key = driver.getLicenseID();
    int index = hashFunction(key);

    Node* current = table[index];
    while (current != nullptr) {
        if (current->data.getLicenseID() == key) {
            current->data = driver;
            return;
        }
        current = current->next;
    }

    Node* newNode = new Node(driver);
    newNode->next = table[index];
    table[index] = newNode;
    size++;
}

Driver* HashTable::search(string licenseID) const {
    int index = hashFunction(licenseID);
    Node* current = table[index];

    while (current != nullptr) {
        if (current->data.getLicenseID() == licenseID) {
            return &(current->data);
        }
        current = current->next;
    }

    return nullptr;
}

bool HashTable::remove(string licenseID) {
    int index = hashFunction(licenseID);
    Node* current = table[index];
    Node* previous = nullptr;

    while (current != nullptr) {
        if (current->data.getLicenseID() == licenseID) {
            if (previous == nullptr) {
                table[index] = current->next;
            } else {
                previous->next = current->next;
            }

            delete current;
            size--;
            return true;
        }

        previous = current;
        current = current->next;
    }

    return false;
}

bool HashTable::isEmpty() const {
    return size == 0;
}

int HashTable::getSize() const {
    return size;
}

void HashTable::display() const {
    if (isEmpty()) {
        cout << "Hash table is empty." << endl;
        return;
    }

    for (int i = 0; i < capacity; i++) {
        Node* current = table[i];

        if (current != nullptr) {
            cout << "Index " << i << ":" << endl;

            while (current != nullptr) {
                current->data.display();
                cout << "--------------------------" << endl;
                current = current->next;
            }
        }
    }
}
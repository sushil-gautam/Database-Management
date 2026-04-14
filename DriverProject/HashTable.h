#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include "Driver.h"

using namespace std;

class HashTable {
private:
    struct Node {
        Driver data;
        Node* next;

        Node(const Driver& d) {
            data = d;
            next = nullptr;
        }
    };

    Node** table;
    int capacity;
    int size;

    int hashFunction(string key) const;

public:
    HashTable(int cap = 101);
    ~HashTable();

    void insert(const Driver& driver);
    bool remove(string licenseID);
    Driver* search(string licenseID) const;

    bool isEmpty() const;
    int getSize() const;

    void display() const;
};

#endif
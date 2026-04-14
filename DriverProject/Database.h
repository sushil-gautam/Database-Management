#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include "Driver.h"
#include "HashTable.h"
#include "LinkedList.h"
#include "Queue.h"
#include "Stack.h"

using namespace std;

class Database {
private:
    HashTable activeDrivers;
    LinkedList driverList;
    Stack newestStack;
    Queue oldestQueue;

public:
    Database();
    Database(int tableSize);

    void addDriver(const Driver& d);
    bool removeDriver(const std::string& licenseID);
    Driver* searchDriver(const std::string& licenseID) const;

    void displayAllDrivers() const;
    bool isEmpty() const;

    void loadFromFile(const std::string& filename);

    void showNewestDrivers(int n);
    void showOldestDrivers(int n);
};

#endif
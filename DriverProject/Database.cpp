#include "Database.h"
#include "Driver.h"
#include "Address.h"
#include "Date.h"

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

// ------------------ Safe conversion helper ------------------
int safeStoi(const string& token, int defaultValue = 0) {
    try {
        string trimmed = token;
        // remove leading/trailing whitespace
        trimmed.erase(0, trimmed.find_first_not_of(" \t\r\n"));
        trimmed.erase(trimmed.find_last_not_of(" \t\r\n") + 1);
        if (trimmed.empty()) return defaultValue;
        return stoi(trimmed);
    } catch (const std::exception&) {
        return defaultValue;
    }
}

// ------------------ Database class functions ------------------
Database::Database() : activeDrivers(101), newestStack(200) {}

Database::Database(int tableSize) : activeDrivers(tableSize), newestStack(200) {}

void Database::addDriver(const Driver& driver) {
    activeDrivers.insert(driver);
    driverList.insertAtEnd(driver);
    newestStack.push(driver);
    oldestQueue.enqueue(driver);
}

bool Database::removeDriver(const string& licenseID) {
    return activeDrivers.remove(licenseID);
}

Driver* Database::searchDriver(const string& licenseID) const {
    return activeDrivers.search(licenseID);
}

void Database::displayAllDrivers() const {
    activeDrivers.display();
}

bool Database::isEmpty() const {
    return activeDrivers.isEmpty();
}

// ------------------ Load drivers from file safely ------------------
void Database::loadFromFile(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Could not open file: " << filename << endl;
        return;
    }

    string line;
    int lineNumber = 0;

    while (getline(file, line)) {
        lineNumber++;
        if (line.empty()) continue;

        stringstream ss(line);
        string token;

        // String fields
        string licenseID, name, street, city, county, workCategory, medicalCondition, ticketLocation;
        // Numeric fields
        int dobDay = 1, dobMonth = 1, dobYear = 1970;
        int yearsOfExperience = 0;
        int issueDay = 1, issueMonth = 1, issueYear = 1970;
        bool hasTicket = false;

        try {
            getline(ss, licenseID, '|');
            getline(ss, name, '|');

            getline(ss, token, '|'); dobDay = safeStoi(token, 1);
            getline(ss, token, '|'); dobMonth = safeStoi(token, 1);
            getline(ss, token, '|'); dobYear = safeStoi(token, 1970);

            getline(ss, street, '|');
            getline(ss, city, '|');
            getline(ss, county, '|');
            getline(ss, workCategory, '|');

            getline(ss, token, '|'); yearsOfExperience = safeStoi(token, 0);
            getline(ss, medicalCondition, '|');

            getline(ss, token, '|'); issueDay = safeStoi(token, 1);
            getline(ss, token, '|'); issueMonth = safeStoi(token, 1);
            getline(ss, token, '|'); issueYear = safeStoi(token, 1970);

            getline(ss, ticketLocation, '|');
            hasTicket = (!ticketLocation.empty() && ticketLocation != "None");

            // Create objects
            Address addr(street, city, county);
            Date dob(dobDay, dobMonth, dobYear);
            Date issueDate(issueDay, issueMonth, issueYear);
            Date ticketDate = hasTicket ? Date(issueDay, issueMonth, issueYear) : Date();

            Driver d(
                licenseID, name, 0, workCategory, yearsOfExperience,
                medicalCondition, addr, dob, issueDate, hasTicket, ticketDate, ticketLocation
            );

            addDriver(d);

        } catch (...) {
            cout << "Error parsing line " << lineNumber << ": " << line << endl;
            continue; // skip bad lines
        }
    }

    file.close();
}

// ------------------ Show newest drivers ------------------
void Database::showNewestDrivers(int n) {
    Stack temp;
    for (int i = 0; i < n; i++) {
        if (newestStack.isEmpty()) break;
        Driver d = newestStack.pop();
        d.display();
        cout << "--------------------------" << endl;
        temp.push(d);
    }
    while (!temp.isEmpty()) {
        newestStack.push(temp.pop());
    }
}

// ------------------ Show oldest drivers ------------------
void Database::showOldestDrivers(int n) {
    Queue temp;
    for (int i = 0; i < n; i++) {
        if (oldestQueue.isEmpty()) break;
        Driver d = oldestQueue.dequeue();
        d.display();
        cout << "--------------------------" << endl;
        temp.enqueue(d);
    }
    while (!temp.isEmpty()) {
        oldestQueue.enqueue(temp.dequeue());
    }
}

#include <iostream>
#include "Database.h"

using namespace std;

int main() {
    Database db;
    db.loadFromFile("drivers.txt");

    int choice;
    string id;

    do {
        cout << "\n===== DRIVER DATABASE MENU =====\n";
        cout << "1. Display all drivers\n";
        cout << "2. Search driver by License ID\n";
        cout << "3. Remove driver by License ID\n";
        cout << "4. Show newest 3 drivers\n";
        cout << "5. Show oldest 3 drivers\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                db.displayAllDrivers();
                break;

            case 2: {
                cout << "Enter License ID: ";
                cin >> id;
                Driver* d = db.searchDriver(id);
                if (d != nullptr) {
                    d->display();
                } else {
                    cout << "Driver not found.\n";
                }
                break;
            }

            case 3:
                cout << "Enter License ID to remove: ";
                cin >> id;
                if (db.removeDriver(id)) {
                    cout << "Driver removed successfully.\n";
                } else {
                    cout << "Driver not found.\n";
                }
                break;

            case 4:
                db.showNewestDrivers(3);
                break;

            case 5:
                db.showOldestDrivers(3);
                break;

            case 0:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 0);

    return 0;
}
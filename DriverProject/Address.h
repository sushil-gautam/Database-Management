#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>
using namespace std;

class Address {
public:
    string street;
    string city;
    string county;

    Address();
    Address(string st, string ct, string cnty);

    void display() const;
};

#endif
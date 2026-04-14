#include "Address.h"
#include <iostream>
using namespace std;

Address::Address() {
    street = "";
    city = "";
    county = "";
}

Address::Address(string st, string ct, string cnty) {
    street = st;
    city = ct;
    county = cnty;
}

void Address::display() const {
    cout << "Address: " << street << ", " << city << ", " << county << endl;
}
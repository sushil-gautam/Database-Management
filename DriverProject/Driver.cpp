#include <iostream>
#include "Driver.h"

using namespace std;

Driver::Driver() {
    licenseID = "";
    name = "";
    age = 0;
    workCategory = "";
    yearsOfExperience = 0;
    medicalCondition = "";
    hasTicket = false;
    ticketLocation = "";
}

Driver::Driver(const string& id,
               const string& n,
               int a,
               const string& work,
               int exp,
               const string& medical,
               const Address& addr,
               const Date& dob,
               const Date& issueDate,
               bool ticketStatus,
               const Date& tDate,
               const string& tLocation) {
    licenseID = id;
    name = n;
    age = a;
    workCategory = work;
    yearsOfExperience = exp;
    medicalCondition = medical;
    address = addr;
    dateOfBirth = dob;
    licenseIssueDate = issueDate;
    hasTicket = ticketStatus;
    ticketDate = tDate;
    ticketLocation = tLocation;
}

void Driver::setLicenseID(const string& id) {
    licenseID = id;
}

void Driver::setName(const string& n) {
    name = n;
}

void Driver::setAge(int a) {
    age = a;
}

void Driver::setWorkCategory(const string& work) {
    workCategory = work;
}

void Driver::setYearsOfExperience(int exp) {
    yearsOfExperience = exp;
}

void Driver::setMedicalCondition(const string& medical) {
    medicalCondition = medical;
}

void Driver::setAddress(const Address& addr) {
    address = addr;
}

void Driver::setDateOfBirth(const Date& dob) {
    dateOfBirth = dob;
}

void Driver::setLicenseIssueDate(const Date& issueDate) {
    licenseIssueDate = issueDate;
}

void Driver::setTicketInfo(bool ticketStatus, const Date& tDate, const string& tLocation) {
    hasTicket = ticketStatus;
    ticketDate = tDate;
    ticketLocation = tLocation;
}

string Driver::getLicenseID() const {
    return licenseID;
}

string Driver::getName() const {
    return name;
}

int Driver::getAge() const {
    return age;
}

string Driver::getWorkCategory() const {
    return workCategory;
}

int Driver::getYearsOfExperience() const {
    return yearsOfExperience;
}

string Driver::getMedicalCondition() const {
    return medicalCondition;
}

Address Driver::getAddress() const {
    return address;
}

Date Driver::getDateOfBirth() const {
    return dateOfBirth;
}

Date Driver::getLicenseIssueDate() const {
    return licenseIssueDate;
}

bool Driver::getHasTicket() const {
    return hasTicket;
}

Date Driver::getTicketDate() const {
    return ticketDate;
}

string Driver::getTicketLocation() const {
    return ticketLocation;
}

string Driver::getAgeCategory() const {
    if (age >= 16 && age <= 28)
        return "Youth";
    else if (age > 28 && age <= 50)
        return "Middle-aged";
    else
        return "Senior/Old age";
}

string Driver::getExperienceCategory() const {
    if (yearsOfExperience >= 0 && yearsOfExperience <= 5)
        return "New driver";
    else if (yearsOfExperience > 5 && yearsOfExperience <= 15)
        return "Moderately experienced";
    else
        return "Highly experienced";
}

void Driver::display() const {
    cout << "License ID: " << licenseID << endl;
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Age Category: " << getAgeCategory() << endl;
    cout << "Work Category: " << workCategory << endl;
    cout << "Experience: " << yearsOfExperience << " years" << endl;
    cout << "Experience Category: " << getExperienceCategory() << endl;
    cout << "Medical Condition: " << medicalCondition << endl;

    cout << "Date of Birth: ";
    dateOfBirth.display();
    cout << endl;

    cout << "License Issue Date: ";
    licenseIssueDate.display();
    cout << endl;

    address.display();

    cout << "Has Ticket: " << (hasTicket ? "Yes" : "No") << endl;
    if (hasTicket) {
        cout << "Ticket Date: ";
        ticketDate.display();
        cout << endl;
        cout << "Ticket Location: " << ticketLocation << endl;
    }
}
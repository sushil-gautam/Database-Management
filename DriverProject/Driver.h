#ifndef DRIVER_H
#define DRIVER_H

#include <string>
#include "Date.h"
#include "Address.h"

class Driver {
private:
    std::string licenseID;
    std::string name;
    int age;
    std::string workCategory;
    int yearsOfExperience;
    std::string medicalCondition;
    Address address;
    Date dateOfBirth;
    Date licenseIssueDate;

    bool hasTicket;
    Date ticketDate;
    std::string ticketLocation;

public:
    Driver();

    Driver(const std::string& id,
           const std::string& n,
           int a,
           const std::string& work,
           int exp,
           const std::string& medical,
           const Address& addr,
           const Date& dob,
           const Date& issueDate,
           bool ticketStatus = false,
           const Date& tDate = Date(),
           const std::string& tLocation = "");

    void setLicenseID(const std::string& id);
    void setName(const std::string& n);
    void setAge(int a);
    void setWorkCategory(const std::string& work);
    void setYearsOfExperience(int exp);
    void setMedicalCondition(const std::string& medical);
    void setAddress(const Address& addr);
    void setDateOfBirth(const Date& dob);
    void setLicenseIssueDate(const Date& issueDate);
    void setTicketInfo(bool ticketStatus, const Date& tDate, const std::string& tLocation);

    std::string getLicenseID() const;
    std::string getName() const;
    int getAge() const;
    std::string getWorkCategory() const;
    int getYearsOfExperience() const;
    std::string getMedicalCondition() const;
    Address getAddress() const;
    Date getDateOfBirth() const;
    Date getLicenseIssueDate() const;
    bool getHasTicket() const;
    Date getTicketDate() const;
    std::string getTicketLocation() const;

    std::string getAgeCategory() const;
    std::string getExperienceCategory() const;

    void display() const;
};

#endif
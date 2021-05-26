#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "CommunityMember.h"

class Employee : public CommunityMember {
private: 
    string EmployeeNumber;
    string LocalPhoneNumber;
    string Rank;
    string AccountNumber;
public:
    Employee(string, string, bool, string, string, string, string, string, string);
    Employee();

    void setEmployeeNumber(string);
    string getEmployeeNumber();

    void setLocalPhoneNumber(string);
    string getLocalPhoneNumber();

    void setRank(string);
    string getRank();

    void setAccountNumber(string);
    string getAccountNumber();

    ~Employee();
};

#endif
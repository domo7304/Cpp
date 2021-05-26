#include <string>
#include "Employee.h"
using namespace std;

Employee::Employee(string name, string RegistrationNumber, bool Gender, string PhoneNumber, string Email, 
    string _EmployeeNumber, string _LocalPhoneNumber, string _Rank, string _AccountNumber)
    :CommunityMember(name, RegistrationNumber, Gender, PhoneNumber, Email)
{
    setEmployeeNumber(_EmployeeNumber);
    setLocalPhoneNumber(_LocalPhoneNumber);
    setRank(_Rank);
    setAccountNumber(_AccountNumber);
}
Employee::Employee() {}

void Employee::setEmployeeNumber(string EmployeeNumber) {
    this->EmployeeNumber = EmployeeNumber;
}

string Employee::getEmployeeNumber() {
    return EmployeeNumber;
}

void Employee::setLocalPhoneNumber(string LocalPhoneNumber) {
    this->LocalPhoneNumber = LocalPhoneNumber;
}

string Employee::getLocalPhoneNumber() {
    return LocalPhoneNumber;
}

void Employee::setRank(string Rank) {
    this->Rank = Rank;
}

string Employee::getRank() {
    return Rank;
}

void Employee::setAccountNumber(string AccountNumber) {
    this->AccountNumber = AccountNumber;
}

string Employee::getAccountNumber() {
    return AccountNumber;
}

Employee::~Employee() {}
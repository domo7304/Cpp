#include <string>
#include "Teacher.h"
using namespace std;

Teacher::Teacher(string name, string RegistrationNumber, bool Gender, string PhoneNumber, string Email, 
    string EmployeeNumber, string LocalPhoneNumber, string Rank, string AccountNumber, string _Department, 
    string _UniversityIssuanceDate, string _HomePageAddress, string _FinalEducation)
    : Employee(name, RegistrationNumber, Gender, PhoneNumber, Email, EmployeeNumber, LocalPhoneNumber, Rank, AccountNumber)
{
    setDepartment(_Department);
    setUniversityIssuanceDate(_UniversityIssuanceDate);
    setHomePageAddress(_HomePageAddress);
    setFinalEducation(_FinalEducation);
}
Teacher::Teacher() {}

void Teacher::setDepartment(string Department) {
    this->Department = Department;
}

string Teacher::getDepartment() {
    return Department;
}

void Teacher::setUniversityIssuanceDate(string UniversityIssuanceDate) {
    this->UniversityIssuanceDate = UniversityIssuanceDate;
}

string Teacher::getUniversityIssuanceDate() {
    return UniversityIssuanceDate;
}

void Teacher::setHomePageAddress(string HomePageAddress) {
    this->HomePageAddress = HomePageAddress;
}

string Teacher::getHomePageAddress() {
    return HomePageAddress;
}

void Teacher::setFinalEducation(string FinalEducation) {
    this->FinalEducation = FinalEducation;
}

string Teacher::getFinalEducation() {
    return FinalEducation;
}

Teacher::~Teacher() {}
#include <string>
#include "Staff.h"
using namespace std;

Staff::Staff(string name, string RegistrationNumber, bool Gender, string PhoneNumber, string Email,
	string EmployeeNumber, string LocalPhoneNumber, string Rank, string AccountNumber, string _Responsibilities)
	: Employee(name, RegistrationNumber, Gender, PhoneNumber, Email, EmployeeNumber, LocalPhoneNumber, Rank, AccountNumber)
{
	setResponsibilities(_Responsibilities);
}
Staff::Staff() {}

void Staff::setResponsibilities(string Responsibilities) {
	this->Responsibilities = Responsibilities;
}

string Staff::getResponsibilities() {
	return Responsibilities;
}

Staff::~Staff() {}
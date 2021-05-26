#ifndef STAFF_H
#define STAFF_H

#include "Employee.h"

class Staff : public Employee {
private:
	string Responsibilities;
public:
	Staff(string, string, bool, string, string, string, string, string, string, string);
	Staff();

	string type = "Staff";

	void setResponsibilities(string);
	string getResponsibilities();

	~Staff();
};

#endif
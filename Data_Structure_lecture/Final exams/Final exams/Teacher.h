#ifndef TEACHER_H
#define TEACHER_H

#include "Employee.h"

class Teacher : public Employee {
private:
    string Department;
    string UniversityIssuanceDate;
    string HomePageAddress;
    string FinalEducation;
public:
    Teacher(string, string, bool, string, string, string, string, string, string,
        string, string, string, string);
    Teacher();

    string type = "Teacher";

    void setDepartment(string);
    string getDepartment();

    void setUniversityIssuanceDate(string);
    string getUniversityIssuanceDate();

    void setHomePageAddress(string);
    string getHomePageAddress();

    void setFinalEducation(string);
    string getFinalEducation();

    ~Teacher();
};

#endif
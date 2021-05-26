#ifndef STUDENT_H
#define STUDENT_H

#include "CommunityMember.h"

class Student : public CommunityMember {
private:
    string StudentID;
    string Department;
    double Grade[3];
    bool CurrentStudentPresence;
public:
    Student(string, string, bool, string, string, string, string, int, int, int, bool);
    Student();

    double GradePointAverage;

    string type = "Student";

    void setStudentID(string);
    string getStudentID();

    void setDepartment(string);
    string getDepartment();

    void setGrade(int, int, int);
    double* getGrade();

    void setCurrentStudentPresence(bool);
    bool getCurrentStudentPresence();

    ~Student();
};

#endif
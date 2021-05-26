#include <string>
#include "Student.h"
using namespace std;

Student::Student(string name, string RegistrationNumber, bool Gender, string PhoneNumber, string Email, 
    string _StudentID, string _Department, int Korean, int English, int Math, bool _CurrentStudentPresence)
    : CommunityMember(name, RegistrationNumber, Gender, PhoneNumber, Email)
{
    setStudentID(_StudentID);
    setDepartment(_Department);
    setGrade(Korean, English, Math);
    setCurrentStudentPresence(_CurrentStudentPresence);
}
Student::Student() {}

void Student::setStudentID(string StudentID) {
    this->StudentID = StudentID;
}

string Student::getStudentID() {
    return StudentID;
}

void Student::setDepartment(string Department) {
    this->Department = Department;
}

string Student::getDepartment() {
    return Department;
}

void Student::setGrade(int Korean, int English, int Math) {
    Grade[0] = Korean;
    Grade[1] = English;
    Grade[2] = Math;
    GradePointAverage = ((Grade[0] + Grade[1] + Grade[2]) / 3);
}

double* Student::getGrade() {
    return Grade;
}

void Student::setCurrentStudentPresence(bool CurrentStudentPresence) {
    this->CurrentStudentPresence = CurrentStudentPresence;
}

bool Student::getCurrentStudentPresence() {
    return CurrentStudentPresence;
}

Student::~Student() {}
#include <string>
#include "CommunityMember.h"
using namespace std;

CommunityMember::CommunityMember(string _name, string _RegistrationNumber, bool _Gender, string _PhoneNumber,
	string _Email)
{
	setName(_name);
	setRegistrationNumber(_RegistrationNumber);
	setGender(_Gender);
	setPhoneNumber(_PhoneNumber);
	setEmail(_Email);
}
CommunityMember::CommunityMember(){}

void CommunityMember::setName(string name) {
	this->name = name;
}

string CommunityMember::getName() {
	return name;
}

void CommunityMember::setRegistrationNumber(string RegistrationNumber) {
	this->RegistrationNumber = RegistrationNumber;
}

string CommunityMember::getRegistrationNumber() {
	return RegistrationNumber;
}

void CommunityMember::setGender(bool Gender) {
	this->Gender = Gender;
}

bool CommunityMember::getGender() {
	return Gender;
}

void CommunityMember::setPhoneNumber(string PhoneNumber) {
	this->PhoneNumber = PhoneNumber;
}

string CommunityMember::getPhoneNumber() {
	return PhoneNumber;
}

void CommunityMember::setEmail(string Email) {
	this->Email = Email;
}

string CommunityMember::getEmail() {
	return Email;
}

CommunityMember::~CommunityMember(){}
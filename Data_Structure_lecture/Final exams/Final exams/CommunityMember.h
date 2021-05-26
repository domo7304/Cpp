#ifndef COMMUNITYMEMBER_H
#define COMMUNITYMEMBER_H

#include <string>
using namespace std;

class CommunityMember {
private:
    string name;
    string RegistrationNumber;
    bool Gender;
    string PhoneNumber;
    string Email;
public:
    CommunityMember(string, string, bool, string, string);
    CommunityMember();
    
    void setName(string);
    string getName();

    void setRegistrationNumber(string);
    string getRegistrationNumber();

    void setGender(bool);
    bool getGender();

    void setPhoneNumber(string);
    string getPhoneNumber();

    void setEmail(string);
    string getEmail();

    ~CommunityMember();
};

#endif
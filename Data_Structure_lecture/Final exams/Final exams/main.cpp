#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include "CommunityMember.h"
#include "Employee.h"
#include "Teacher.h"
#include "Staff.h"
#include "Student.h"
using namespace std;

// 사용자가 선택할 기능
enum class ChoiceFunc {
	PRINT_ALL = 1, PRINT_SELECT, SEARCH, NEW, END
};

// teacher, staff, student 중 선택하여 데이터를 출력할 때 사용자가 선택할 선택지
enum class Choice {
	TEACHER = 1, STAFF, STUDENT
};

// 각 함수들의 프로토타임
ChoiceFunc enterChoice();
void outputLine(Teacher&);
void outputLine(Staff&);
void outputLine(Student&);

void printAll(fstream&);

void printSelected(fstream&);
void sortByStudentId(fstream&);
void sortByAverage(fstream&);

void searchFromFile(fstream&);
void searchByName(fstream&, string);
void searchByDepartment(fstream&, string);
void modify(fstream&, string);

void newData(fstream&);

int main() {
	fstream inOutInfo("CommunityMember.info", ios::in | ios::out | ios::binary);

	if (!inOutInfo) {
		cerr << "File could not be opened." << endl;
		exit(EXIT_FAILURE);
	}

	ChoiceFunc choice;

	// 사용자의 입력에 따라 switch case 문을 통해 기능 수행
	while ((choice = enterChoice()) != ChoiceFunc::END) {
		switch (choice) {
		case ChoiceFunc::PRINT_ALL:
			printAll(inOutInfo);
			break;
		case ChoiceFunc::PRINT_SELECT:
			printSelected(inOutInfo);
			break;
		case ChoiceFunc::SEARCH:
			searchFromFile(inOutInfo);
			break;
		case ChoiceFunc::NEW:
			newData(inOutInfo);
		default:
			cerr << "Incorrect choice" << endl;
			break;
		}
		inOutInfo.clear();
	}
	return 0;
}

// 사용자에게 어떤 기능을 수행할 것인지 출력 및 입력을 받는 함수
ChoiceFunc enterChoice() {
	cout << "\nEnter your choice\n"
		<< "1 - Output all data in a file \n"
		<< "2 - Output data from the selected file \n"
		<< "3 - Search for students by name or department \n"
		<< "4 - add a new deta \n"
		<< "5 - end program\n Enter your choice : ";

	int menuChoice;
	cin >> menuChoice;
	return static_cast<ChoiceFunc> (menuChoice);
}

// teacher, staff, student 각각의 멤버 변수를 출력할 오버로딩 출력 포맷
void outputLine(Teacher& record) {
	cout << left << setw(7) << record.type
		<< setw(7) << record.getName()
		<< setw(7) << record.getRegistrationNumber()
		<< setw(7) << record.getGender()
		<< setw(7) << record.getPhoneNumber()
		<< setw(7) << record.getEmail()
		<< setw(7) << record.getEmployeeNumber()
		<< setw(7) << record.getLocalPhoneNumber()
		<< setw(7) << record.getRank()
		<< setw(7) << record.getAccountNumber()
		<< setw(7) << record.getDepartment()
		<< setw(7) << record.getUniversityIssuanceDate()
		<< setw(7) << record.getHomePageAddress()
		<< setw(7) << record.getFinalEducation() << endl;
}

void outputLine(Staff& record) {
	cout << left << setw(7) << record.type
		<< setw(7) << record.getName()
		<< setw(7) << record.getRegistrationNumber()
		<< setw(7) << record.getGender()
		<< setw(7) << record.getPhoneNumber()
		<< setw(7) << record.getEmail()
		<< setw(7) << record.getEmployeeNumber()
		<< setw(7) << record.getLocalPhoneNumber()
		<< setw(7) << record.getRank()
		<< setw(7) << record.getAccountNumber()
		<< setw(7) << record.getResponsibilities() << endl;
}

void outputLine(Student& record) {
	cout << left << setw(7) << record.type
		<< setw(7) << record.getName()
		<< setw(7) << record.getRegistrationNumber()
		<< setw(7) << record.getGender()
		<< setw(7) << record.getPhoneNumber()
		<< setw(7) << record.getEmail()
		<< setw(7) << record.getStudentID()
		<< setw(7) << record.getDepartment()
		<< setw(7) << record.getGrade()
		<< setw(7) << record.getCurrentStudentPresence() << endl;
}

// 모든 데이터를 출력하는 기능 함수
void printAll(fstream& file) {
	string type;
	file >> type;

	while (!file.eof()) {
		if (type == "teacher") {
			int pos = file.tellg();
			file.seekg(pos - 7);

			Teacher teacher;
			file.read(reinterpret_cast<char*>(&teacher), sizeof(Teacher));

			outputLine(teacher);

			file >> type;
		}

		else if (type == "staff"){
			int pos = file.tellg();
			file.seekg(pos - 5);

			Staff staff;
			file.read(reinterpret_cast<char*>(&staff), sizeof(Staff));

			outputLine(staff);

			file >> type;
		}

		else {
			int pos = file.tellg();
			file.seekg(pos - 7);

			Student student;
			file.read(reinterpret_cast<char*>(&student), sizeof(Student));

			outputLine(student);

			file >> type;
		}
	}
	file.seekg(0);
}

// 사용자의 선택에 따라 출력하는 기능 함수
void printSelected(fstream& file) {
	cout << "\nEnter your choice\n"
		<< "1 - Output data related to 'teacher' \n"
		<< "2 - Output data related to 'staff' \n"
		<< "3 - Output data related to 'student' \nEnter your choice : ";

	int menuChoice;
	cin >> menuChoice;

	Choice choice = static_cast<Choice> (menuChoice);

	// teacher 을 입력받았을 때
	if (choice == Choice::TEACHER) {
		string type;
		file >> type;

		while (!file.eof()) {
			if (type == "teacher") {
				int pos = file.tellg();
				file.seekg(pos - 7);

				Teacher teacher;
				file.read(reinterpret_cast<char*>(&teacher), sizeof(Teacher));

				outputLine(teacher);

				file >> type;
			}

			// 해당 파일포인터 위치가 teacher 에 대한 정보가 아닐시 한 줄 건너뛰기 위한 코드
			else {
				if (type == "student") {
					int pos = file.tellg();
					file.seekg(pos - 7);

					Student student;
					file.read(reinterpret_cast<char*>(&student), sizeof(Student));
					file >> type;
				}
				else if (type == "staff") {
					int pos = file.tellg();
					file.seekg(pos - 5);

					Staff staff;
					file.read(reinterpret_cast<char*>(&staff), sizeof(Staff));
					file >> type;
				}
			}
		}
		file.seekg(0);
	}

	// staff를 입력받았을 때
	else if (choice == Choice::STAFF) {
		string type;
		file >> type;

		while (!file.eof()) {
			if (type == "staff") {
				int pos = file.tellg();
				file.seekg(pos - 7);

				Staff staff;
				file.read(reinterpret_cast<char*>(&staff), sizeof(Staff));

				outputLine(staff);

				file >> type;
			}

			// 해당 파일포인터 위치가 staff 에 대한 정보가 아닐시 한 줄 건너뛰기 위한 코드
			else {
				if (type == "teacher") {
					int pos = file.tellg();
					file.seekg(pos - 7);

					Teacher teacher;
					file.read(reinterpret_cast<char*>(&teacher), sizeof(Teacher));
					file >> type;
				}
				else if (type == "student") {
					int pos = file.tellg();
					file.seekg(pos - 7);

					Student student;
					file.read(reinterpret_cast<char*>(&student), sizeof(Student));
					file >> type;
				}
			}
		}
		file.seekg(0);
	}

	// student를 입력받았을 때
	else {
		cout << "\nEnter your choice\n"
			<< "1 - Output data sorted by StudentID \n"
			<< "2 - Outputs data sorted by GradePointAverage/nEnter your choice : ";

		int num;
		cin >> num;

		// 사용자의 선택에 따라 studentID 혹은 평균점수를 기준으로 데이터 출력
		if (num == 1) {
			sortByStudentId(file);
		}
		else if (num == 2) {
			sortByAverage(file);
		}
		
	}
}

// 사용자의 선택에 따라 studentID를 기준으로 데이터 출력
void sortByStudentId(fstream& file) {
	file.seekg(0);
	string type;
	file >> type;

	fstream outFile("sort.txt", ios::in | ios::out | ios::binary);

	if (!outFile) {
		cerr << "File could not be opened." << '\n';
		exit(EXIT_FAILURE);
	}

	while (!file.eof()) {
		if (type == "student") {
			int pos = file.tellg();
			file.seekg(pos - 7);

			Student student;
			file.read(reinterpret_cast<char*>(&student), sizeof(Student));

			outFile.seekp((stol(student.getStudentID()) - 1) * sizeof(Student));
			outFile.write(reinterpret_cast<char*>(&student), sizeof(Student));

			file >> type;
		}

		// 해당 파일포인터 위치가 student 에 대한 정보가 아닐시 한 줄 건너뛰기 위한 코드
		else {
			if (type == "teacher") {
				int pos = file.tellg();
				file.seekg(pos - 7);

				Teacher teacher;
				file.read(reinterpret_cast<char*>(&teacher), sizeof(Teacher));
				file >> type;
			}
			else if (type == "staff") {
				int pos = file.tellg();
				file.seekg(pos - 5);

				Staff staff;
				file.read(reinterpret_cast<char*>(&staff), sizeof(Staff));
				file >> type;
			}
		}
	}
	file.seekg(0);
	Student student;
	outFile.read(reinterpret_cast<char*>(&student), sizeof(Student));

	while (!outFile.eof()) {
		outputLine(student);

		outFile.read(reinterpret_cast<char*>(&student), sizeof(Student));
	}
}

// 사용자의 선택에 따라 평균을 기준으로 데이터 출력
void sortByAverage(fstream& file) {
	file.seekg(0);
	Student student;
	string type;
	file >> type;

	fstream outFile("sort.txt", ios::in | ios::out | ios::binary);

	if (!outFile) {
		cerr << "File could not be opened." << '\n';
		exit(EXIT_FAILURE);
	}

	while (!file.eof()) {
		if (type == "student") {
			int pos = file.tellg();
			file.seekg(pos - 7);

			file.read(reinterpret_cast<char*>(&student), sizeof(Student));

			outFile.seekp((student.GradePointAverage - 1) * sizeof(Student));
			outFile.write(reinterpret_cast<char*>(&student), sizeof(Student));

			file >> type;
		}

		// 해당 파일포인터 위치가 student 에 대한 정보가 아닐시 한 줄 건너뛰기 위한 코드
		else {
			if (type == "teacher") {
				int pos = file.tellg();
				file.seekg(pos - 7);

				Teacher teacher;
				file.read(reinterpret_cast<char*>(&teacher), sizeof(Teacher));
				file >> type;
			}
			else if (type == "staff") {
				int pos = file.tellg();
				file.seekg(pos - 5);

				Staff staff;
				file.read(reinterpret_cast<char*>(&staff), sizeof(Staff));
				file >> type;
			}
		}
	}
	file.seekg(0);
	outFile.read(reinterpret_cast<char*>(&student), sizeof(Student));

	while (!outFile.eof()) {
		outputLine(student);

		outFile.read(reinterpret_cast<char*>(&student), sizeof(Student));
	}
}

void searchFromFile(fstream& file) {
	cout << "\nEnter your choice\n"
		<< "1 - Searching for data by name \n"
		<< "2 - Searching for data by Registration Number\nEnter your choice : ";
	
	int num;
	cin >> num;

	// 이름에 의한 검색, 등록번호에 의한 검색 두 가지 옵션을 사용자에게 제공
	if (num == 1) {
		string name;
		cin >> name;
		searchByName(file, name);
	}
	else if (num == 2) {
		string department;
		cin >> department;
		searchByDepartment(file, department);
	}
}

// 이름에 의한 검색 기능 함수
void searchByName(fstream& file, string name) {
	file.seekg(0);

	string type;
	file >> type;

	// 각 타입 (teacher, staff, student)마다 크기가 다르므로 file에서 type을 먼저 읽어와 어떤 타입의 데이터인지 확인 후 
	// 이름이 일치하는 데이터 목록을 출력하기
	while (!file.eof()) {
		if (type == "teacher") {
			int pos = file.tellg();
			file.seekg(pos - 7);

			Teacher teacher;
			file.read(reinterpret_cast<char*>(&teacher), sizeof(Teacher));

			if (teacher.getName() == name) {
				outputLine(teacher);
			}
			file >> type;
		}
		else if (type == "staff") {
			int pos = file.tellg();
			file.seekg(pos - 5);

			Staff staff;
			file.read(reinterpret_cast<char*>(&staff), sizeof(Staff));

			if (staff.getName() == name) {
				outputLine(staff);
			}
			file >> type;
		}

		else if (type == "student") {
			int pos = file.tellg();
			file.seekg(pos - 7);

			Student student;
			file.read(reinterpret_cast<char*>(&student), sizeof(Student));

			if (student.getName() == name) {
				outputLine(student);
			}
			file >> type;
		}
	}
	file.seekg(0);

	cout << "\nEnter your choice\n"
		<< "1 - Modify data \n"
		<< "2 - Don't do anything\nEnter your choice : ";

	int num;
	cin >> num;
	if (num == 1) {
		cout << "\nEnter the registration number you want to modify\n" << "number : ";
		string num;
		cin >> num;
		modify(file, num);
	}
}

// 사용자 선택에 따라 부서 검색 기능 함수
void searchByDepartment(fstream& file, string department) {
	file.seekg(0);

	string type;
	file >> type;

	// 각 타입 (teacher, staff, student)마다 크기가 다르므로 file에서 type을 먼저 읽어와 어떤 타입의 데이터인지 확인 후 
	// 이름이 일치하는 데이터 목록을 출력하기
	while (!file.eof()) {
		if (type == "teacher") {
			int pos = file.tellg();
			file.seekg(pos - 7);

			Teacher teacher;
			file.read(reinterpret_cast<char*>(&teacher), sizeof(Teacher));

			if (teacher.getDepartment() == department) {
				outputLine(teacher);
			}
			file >> type;
		}
		else if (type == "student") {
			int pos = file.tellg();
			file.seekg(pos - 7);

			Student student;
			file.read(reinterpret_cast<char*>(&student), sizeof(Student));

			if (student.getDepartment() == department) {
				outputLine(student);
			}
			file >> type;
		}
	}
	file.seekg(0);

	cout << "\nEnter your choice\n"
		<< "1 - Modify data \n"
		<< "2 - Don't do anything\nEnter your choice : ";

	int num;
	cin >> num;
	if (num == 1) {
		cout << "\nEnter the registration number you want to modify\n" << "number : ";
		string num;
		cin >> num;
		modify(file, num);
	}
}

// 사용자가 선택한 등록번호에 대한 데이터 수정 기능 함수
void modify(fstream& file, string registrationNumber) {
	file.seekg(0);

	string type;
	file >> type;

	while (!file.eof()) {
		if (type == "teacher") {
			int pos = file.tellg();
			file.seekg(pos - 7);

			Teacher teacher;
			file.read(reinterpret_cast<char*>(&teacher), sizeof(Teacher));

			if (teacher.getRegistrationNumber() == registrationNumber) {
				outputLine(teacher); // 현재 정보 출력

				cout << "\nEnter your choice\n"
					<< "1 - name \n"
					<< "2 - registration number \n"
					<< "3 - gender \n"
					<< "4 - phone number \n"
					<< "5 - email \n"
					<< "6 - employee number \n"
					<< "7 - local phone number \n"
					<< "8 - rank \n"
					<< "9 - account number \n"
					<< "10 - department \n"
					<< "11 - university lssuance date \n"
					<< "12 - homepage address \n"
					<< "13 - final education \n"
					<< "14 - end \nEnter your choice : " << endl;

				int num;
				cin >> num;

				string str;

				switch (num) {
				case 1:
					cin >> str;
					teacher.setName(str);
					break;
				case 2:
					cin >> str;
					teacher.setRegistrationNumber(str);
					break;
				case 3:
					bool gender;
					cin >> gender;
					teacher.setGender(gender);
					break;
				case 4:
					cin >> str;
					teacher.setPhoneNumber(str);
					break;
				case 5:
					cin >> str;
					teacher.setEmail(str);
					break;
				case 6:
					cin >> str;
					teacher.setEmployeeNumber(str);
					break;
				case 7:
					cin >> str;
					teacher.setLocalPhoneNumber(str);
					break;
				case 8:
					cin >> str;
					teacher.setRank(str);
					break;
				case 9:
					cin >> str;
					teacher.setAccountNumber(str);
					break;
				case 10:
					cin >> str;
					teacher.setDepartment(str);
					break;
				case 11:
					cin >> str;
					teacher.setUniversityIssuanceDate(str);
					break;
				case 12:
					cin >> str;
					teacher.setHomePageAddress(str);
					break;
				case 13:
					cin >> str;
					teacher.setFinalEducation(str);
					break;
				case 14:
					break;
				}
			}
		
			file.write(reinterpret_cast<char*>(&teacher), sizeof(Teacher));	
			outputLine(teacher); // 수정 후 정보 출력

			file >> type;
		}

		else if (type == "staff") {
			int pos = file.tellg();
			file.seekg(pos - 5);

			Staff staff;
			file.read(reinterpret_cast<char*>(&staff), sizeof(Staff));

			if (staff.getRegistrationNumber() == registrationNumber) {
				outputLine(staff); // 현재 정보 출력

				cout << "\nEnter your choice\n"
					<< "1 - name \n"
					<< "2 - registration number \n"
					<< "3 - gender \n"
					<< "4 - phone number \n"
					<< "5 - email \n"
					<< "6 - employee number \n"
					<< "7 - local phone number \n"
					<< "8 - rank \n"
					<< "9 - account number \n"
					<< "10 - responsibilities \n"
					<< "11 - end \nEnter your choice : " << endl;

				int num;
				cin >> num;

				string str;

				switch (num) {
				case 1:
					cin >> str;
					staff.setName(str);
					break;
				case 2:
					cin >> str;
					staff.setRegistrationNumber(str);
					break;
				case 3:
					bool gender;
					cin >> gender;
					staff.setGender(gender);
					break;
				case 4:
					cin >> str;
					staff.setPhoneNumber(str);
					break;
				case 5:
					cin >> str;
					staff.setEmail(str);
					break;
				case 6:
					cin >> str;
					staff.setEmployeeNumber(str);
					break;
				case 7:
					cin >> str;
					staff.setLocalPhoneNumber(str);
					break;
				case 8:
					cin >> str;
					staff.setRank(str);
					break;
				case 9:
					cin >> str;
					staff.setAccountNumber(str);
					break;
				case 10:
					cin >> str;
					staff.setResponsibilities(str);
					break;
				case 11:
					break;
				}
			}

			file.write(reinterpret_cast<char*>(&staff), sizeof(Staff));
			outputLine(staff); // 수정 후 정보 출력

			file >> type;
		}

		else if (type == "student") {
			int pos = file.tellg();
			file.seekg(pos - 7);

			Student student;
			file.read(reinterpret_cast<char*>(&student), sizeof(Student));

			if (student.getRegistrationNumber() == registrationNumber) {
				outputLine(student); // 현재 정보 출력

				cout << "\nEnter your choice\n"
					<< "1 - name \n"
					<< "2 - registration number \n"
					<< "3 - gender \n"
					<< "4 - phone number \n"
					<< "5 - email \n"
					<< "6 - SudentID \n"
					<< "7 - Department \n"
					<< "8 - Grade \n"
					<< "9 -  CurrentStudentPresence; \n"
					<< "10 - end \nEnter your choice : " << endl;

				int num;
				cin >> num;

				string str;

				switch (num) {
				case 1:
					cin >> str;
					student.setName(str);
					break;
				case 2:
					cin >> str;
					student.setRegistrationNumber(str);
					break;
				case 3:
					bool gender;
					cin >> gender;
					student.setGender(gender);
					break;
				case 4:
					cin >> str;
					student.setPhoneNumber(str);
					break;
				case 5:
					cin >> str;
					student.setEmail(str);
					break;
				case 6:
					cin >> str;
					student.setStudentID(str);
					break;
				case 7:
					cin >> str;
					student.setDepartment(str);
					break;
				case 8:
					cout << "enter scores for all three subjects : ";
					int a, b, c;
					cin >> a >> b >> c;
					student.setGrade(a, b, c);
					break;
				case 9:
					bool flag;
					cin >> flag;
					student.setCurrentStudentPresence(flag);
					break;
				case 10:
					break;
				}
			}
			file.write(reinterpret_cast<char*>(&student), sizeof(Student));
			outputLine(student); // 수정 후 정보 출력

			file >> type;
		}
	}
}

// 새로운 데이터를 입력하는 기능 함수
void newData(fstream& file) {
	cout << "\nEnter your choice\n"
		<< "1 - teacher \n"
		<< "2 - staff \n"
		<< "3 - gender \nEntr your choice : ";

	int num;
	cin >> num;

	if (num == 1) {
		Teacher teacher;

		string str;

		cin >> str;
		teacher.setName(str);

		cin >> str;
		teacher.setRegistrationNumber(str);
		
		bool gender;
		cin >> gender;
		teacher.setGender(gender);
		
		cin >> str;
		teacher.setPhoneNumber(str);
		
		cin >> str;
		teacher.setEmail(str);
		
		cin >> str;
		teacher.setEmployeeNumber(str);
		
		cin >> str;
		teacher.setLocalPhoneNumber(str);
		
		cin >> str;
		teacher.setRank(str);
		
		cin >> str;
		teacher.setAccountNumber(str);
		
		cin >> str;
		teacher.setDepartment(str);
		
		cin >> str;
		teacher.setUniversityIssuanceDate(str);
		
		cin >> str;
		teacher.setHomePageAddress(str);
		
		cin >> str;
		teacher.setFinalEducation(str);

		file.write(reinterpret_cast<const char*> (&teacher), sizeof(Teacher));
	}

	else if (num == 2) {
		Staff staff;

		string str;

		cin >> str;
		staff.setName(str);

		cin >> str;
		staff.setRegistrationNumber(str);

		bool gender;
		cin >> gender;
		staff.setGender(gender);

		cin >> str;
		staff.setPhoneNumber(str);

		cin >> str;
		staff.setEmail(str);

		cin >> str;
		staff.setEmployeeNumber(str);

		cin >> str;
		staff.setLocalPhoneNumber(str);

		cin >> str;
		staff.setRank(str);

		cin >> str;
		staff.setAccountNumber(str);

		cin >> str;
		staff.setResponsibilities(str);

		file.write(reinterpret_cast<const char*> (&staff), sizeof(Staff));
	}

	else if (num == 3) {
		Student student;

		string str;

		cin >> str;
		student.setName(str);

		cin >> str;
		student.setRegistrationNumber(str);

		bool gender;
		cin >> gender;
		student.setGender(gender);

		cin >> str;
		student.setPhoneNumber(str);

		cin >> str;
		student.setEmail(str);

		cin >> str;
		student.setStudentID(str);

		cin >> str;
		student.setDepartment(str);

		cout << "enter scores for all three subjects : ";
		int a, b, c;
		cin >> a >> b >> c;
		student.setGrade(a, b, c);

		bool flag;
		cin >> flag;
		student.setCurrentStudentPresence(flag);

		file.write(reinterpret_cast<const char*> (&student), sizeof(Student));
	}
}
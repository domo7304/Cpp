//--------------------------2020.7.29. 목요일 '상속'--------------------------------
//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <cstring>
//using namespace std;
//
//class Person {
//private:
//	int age;
//	char name[50];
//public:
//	Person (int _age, const char* _name)
//		: age(_age) {
//		strcpy(name, _name);
//	}
//	void WhatYourName() const {
//		cout << "My name is " << name << '\n';
//	}
//	void HowOladAreYou() const {
//		cout << "I'm " << age << " years old" << '\n';
//	}
//};
//
//class UnivStudent : public Person {
//private:
//	char major[50];
//public:
//	UnivStudent(const char* _name, int _age, const char* _major)
//		: Person(_age, _name) {
//		strcpy(major, _major);
//	}
//	void WhoAreYou() {
//		WhatYourName();
//		HowOladAreYou();
//		cout << "My major is: " << major << '\n' << '\n';
//	}
//};
//
//int main() {
//	UnivStudent ustd1("LEE", 22, "Computer eng.");
//	ustd1.WhoAreYou();
//
//	UnivStudent ustd2("Yoon", 21, "Electronic eng.");
//	ustd2.WhoAreYou();
//
//	return 0;
//}

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Person {
private:
	char* name;
public:
	Person(const char* name) {
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}
	~Person() {
		delete[]name;
	}
	void WhatYourName() {
		cout << "My name is " << name << '\n';
	}
};

class UnivStudent : public Person {
private:
	char* major;
public:
	UnivStudent(const char* name, const char* major)
		: Person(name) {
		this->major = new char[strlen(major) + 1];
		strcpy(this->major, major);
	}
	~UnivStudent() {
		delete[]major;
	}
	void WhoAreYou() {
		WhatYourName();
		cout << "My major is " << major << '\n' << '\n';
	}
};

int main() {
	UnivStudent st1("Kim", "Mathematics");
	st1.WhoAreYou();
	UnivStudent st2("Hong", "Physics");
	st2.WhoAreYou();

	return 0;
}

//#include <iostream>
//using namespace std;
//
//class Car {
//private:
//	int gasolineGauge;
//public:
//	Car(int gas) : gasolineGauge(gas) {};
//	int GetGasGauge() { return gasolineGauge;  }
//};
//
//class HybridCar : public Car {
//private:
//	int ElectricGauge;
//public:
//	HybridCar(int gas, int elec) : Car(gas), ElectricGauge(elec) {};
//	int GetElecGuage() { return ElectricGauge;  }
//};
//
//class HybridWaterCar : public HybridCar {
//private:
//	int waterGauge;
//public:
//	HybridWaterCar(int gas, int elec, int water) : HybridCar(gas, elec), waterGauge(water) {};
//	void ShowCurrentGauge() {
//		cout << "remain gasoline: " << GetGasGauge() << '\n';
//		cout << "remain electric: " << GetElecGuage() << '\n';
//		cout << "remain water: " << waterGauge << '\n';
//	}
//};
//
//int main() {
//	HybridWaterCar wCar(79, 65, 35);
//	wCar.ShowCurrentGauge();
//
//	return 0;
//}

//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <cstring>
//using namespace std;
//
//class MyFriendInfo {
//private:
//	char* name;
//	int age;
//public:
//	MyFriendInfo(const char* name, int _age)
//		: age(_age) {
//		this->name = new char[strlen(name) + 1];
//		strcpy(this->name, name);
//	}
//	void ShowMyFriendInfo() {
//		cout << "name: " << name << '\n';
//		cout << "age: " << age << '\n';
//	}
//	~MyFriendInfo() {
//		delete[]name;
//	}
//};
//
//class MyFriendDetailInfo : public MyFriendInfo {
//private:
//	char* address;
//	char* phone;
//public:
//	MyFriendDetailInfo(const char* name, int age, const char* address, const char* phone)
//		: MyFriendInfo(name, age) {
//		this->address = new char[strlen(address) + 1];
//		this->phone = new char[strlen(phone) + 1];
//
//		strcpy(this->address, address);
//		strcpy(this->phone, phone);
//	}
//	void ShowMyFriendDetailInfo() {
//		ShowMyFriendInfo();
//		cout << "address: " << address << '\n';
//		cout << "phone: " << phone << '\n';
//	}
//	~MyFriendDetailInfo() {
//		delete[]address;
//		delete[]phone;
//	}
//};
//
//int main() {
//	MyFriendDetailInfo fren1("김진성", 22, "충남 아산", "010-1234-00XX");
//	MyFriendDetailInfo fren2("이주성", 19, "인천광역시", "010-3333-00XX");
//	fren1.ShowMyFriendDetailInfo();
//	fren2.ShowMyFriendDetailInfo();
//
//	return 0;
//}


//#include <iostream>
//using namespace std;
//
//class Rectangle {
//private:
//	int w, d;
//public:
//	Rectangle(int _w, int _d) : w(_w), d(_d) {};
//
//	void ShowAreaInfo() {
//		cout << "면적: " << w * d << '\n';
//	}
//};
//
//class Square : public Rectangle {
//private:
//	int len;
//public:
//	Square(int len) : Rectangle(len, len) {};
//};
//
//int main() {
//	Rectangle rec(4, 3);
//	rec.ShowAreaInfo();
//
//	Square sqr(7);
//	sqr.ShowAreaInfo();
//
//	return 0;
//}


//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <cstring>
//using namespace std;
//
//class Book {
//private:
//	char* title;
//	char* isbn;
//	int price;
//public:
//	Book(const char* title, const char* isbn, int _price)
//		: price(_price) {
//		this->title = new char[strlen(title) + 1];
//		this->isbn = new char[strlen(isbn) + 1];
//		strcpy(this->title, title);
//		strcpy(this->isbn, isbn);
//	}
//	void ShowBookInfo() {
//		cout << "title: " << title << '\n';
//		cout << "ISBN: " << isbn << '\n';
//		cout << "price: " << price << '\n';
//	}
//	~Book() {
//		delete[]title;
//		delete[]isbn;
//	}
//};
//
//class EBook : public Book {
//private:
//	char* DRMKey;
//public:
//	EBook(const char* title, const char* isbn, int price, const char* DRM)
//		: Book(title, isbn, price) {
//		this->DRMKey = new char[strlen(DRM) + 1];
//		strcpy(DRMKey, DRM);
//	}
//	void ShowEBookInfo() {
//		ShowBookInfo();
//		cout << "DRMKey: " << DRMKey << '\n';
//	}
//	~EBook() {
//		delete[]DRMKey;
//	}
//};
//
//int main() {
//	Book book("좋은 C++", "555-12345-890-0", 20000);
//	book.ShowBookInfo();
//	cout << '\n';
//	EBook ebook("좋은 C++ ebook", "55555-12345-890-1", 10000, "fdx9w0i8kiw");
//	ebook.ShowEBookInfo();
//
//	return 0;
//}

//-----------------------2020.7.30. 목요일---------------------------//
//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <cstring>
//using namespace std;
//
//class Employee {
//private:
//	char name[100];
//public:
//	Employee(const char* name) {
//		strcpy(this->name, name);
//	}
//	void ShowYourName() const {
//		cout << "name: " << name << '\n';
//	}
//	virtual int GetPay() const {
//		return 0;
//	}
//	virtual void ShowSalaryInfo() const{}
//};
//
//class PermanentWorker : public Employee {
//private:
//	int salary;
//public:
//	PermanentWorker(const char* name, int money)
//		: Employee (name), salary(money) {}
//	virtual int GetPay() const{
//		return salary; 
//	};
//	virtual void ShowSalaryInfo() const {
//		ShowYourName();
//		cout << "salary: " << GetPay() << '\n' << '\n';
//	}
//};
//
//class TemporaryWorker : public Employee {
//private:
//	int workTime;
//	int payPerHour;
//public:
//	TemporaryWorker(const char* name, int pay)
//		:Employee(name), workTime(0), payPerHour(pay) {}
//	void AddWorkTime(int time) {
//		workTime += time;
//	}
//	virtual int GetPay() const{
//		return workTime * payPerHour;
//	}
//	virtual void ShowSalaryInfo() const {
//		ShowYourName();
//		cout << "salary: " << GetPay() << '\n' << '\n';
//	}
//};
//
//class SalesWorker : public PermanentWorker {
//private:
//	int salesResult;
//	double bonusRatio;
//public:
//	SalesWorker(const char* name, int money, double ratio)
//		: PermanentWorker(name, money), salesResult(0), bonusRatio(ratio) {};
//	void AddSalaryResult(int value) {
//		salesResult += value;
//	}
//	virtual int GetPay() const {
//		return PermanentWorker::GetPay() + (int)(salesResult * bonusRatio);
//	}
//	virtual void ShowSalaryInfo() {
//		ShowYourName();
//		cout << "salary: " << GetPay() << '\n' << '\n';
//	}
//};
//
//class EmployeeHandler {
//private:
//	Employee* empList[50];
//	int empNum;
//public:
//	EmployeeHandler() : empNum(0) { };
//	void addEmployee(Employee* emp) {
//		empList[empNum++] = emp;
//	}
//	void ShowAllSalaryInfo() const {
//		for (int i = 0; i < empNum; i++) {
//			empList[i]->ShowSalaryInfo();
//		}
//	}
//	void ShowTotalSalary() const {
//		int sum = 0;
//		for (int i = 0; i < empNum; i++)
//			sum += empList[i]->GetPay();
//		cout << "salary sum: " << sum << '\n';
//	}
//	~EmployeeHandler() {
//		for (int i = 0; i < empNum; i++) {
//			delete empList[i];
//		}
//	}
//};
//
//int main() {
//	EmployeeHandler handler;
//
//	handler.addEmployee(new PermanentWorker("KIM", 1000));
//	handler.addEmployee(new PermanentWorker("LEE", 1500));
//
//	TemporaryWorker* alba = new TemporaryWorker("Jung", 700);
//	alba->AddWorkTime(5);
//	handler.addEmployee(alba);
//
//	SalesWorker* seller = new SalesWorker("Hong", 1000, 0.1);
//	seller->AddSalaryResult(7000);
//	handler.addEmployee(seller);
//
//	handler.ShowAllSalaryInfo();
//
//	handler.ShowTotalSalary();
//	return 0;
//}



//---------------------------------------2020.8.4. 화요일-----------------------------------------------//
//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <cstring>
//using namespace std;
//
//class Employee {
//private:
//	char name[100];
//public:
//	Employee(const char* name) {
//		strcpy(this->name, name);
//	}
//	void ShowYourName() const {
//		cout << "name: " << name << '\n';
//	}
//	virtual int GetPay() const = 0;
//	virtual void ShowSalaryInfo() const = 0;
//};
//
//class PermanentWorker : public Employee {
//private:
//	int salary;
//public:
//	PermanentWorker(const char* name, int money)
//		: Employee(name), salary(money) {}
//	int GetPay() const {
//		return salary;
//	};
//	void ShowSalaryInfo() const {
//		ShowYourName();
//		cout << "salary: " << GetPay() << '\n' << '\n';
//	}
//};
//
//class TemporaryWorker : public Employee {
//private:
//	int workTime;
//	int payPerHour;
//public:
//	TemporaryWorker(const char* name, int pay)
//		:Employee(name), workTime(0), payPerHour(pay) {}
//	void AddWorkTime(int time) {
//		workTime += time;
//	}
//	int GetPay() const {
//		return workTime * payPerHour;
//	}
//	void ShowSalaryInfo() const {
//		ShowYourName();
//		cout << "salary: " << GetPay() << '\n' << '\n';
//	}
//};
//
//class SalesWorker : public PermanentWorker {
//private:
//	int salesResult;
//	double bonusRatio;
//public:
//	SalesWorker(const char* name, int money, double ratio)
//		: PermanentWorker(name, money), salesResult(0), bonusRatio(ratio) {};
//	void AddSalaryResult(int value) {
//		salesResult += value;
//	}
//	int GetPay() const {
//		return PermanentWorker::GetPay() + (int)(salesResult * bonusRatio);
//	}
//	void ShowSalaryInfo() const {
//		ShowYourName();
//		cout << "salary: " << GetPay() << '\n' << '\n';
//	}
//};
//
//namespace RISK_LEVEL {
//	enum {
//		RISK_A, RISK_B, RISK_C
//	};
//	double Risk_level(int risk) {
//		switch (risk) {
//		case RISK_A:
//			return 0.3;
//			break;
//		case RISK_B:
//			return 0.2;
//			break;
//		case RISK_C:
//			return 0.1;
//			break;
//		}
//	}
//}
//
//class ForeignSalesWorker : public SalesWorker {
//private:
//	int risk;
//public:
//	ForeignSalesWorker(const char* name, int money, double ratio, int _risk)
//		: SalesWorker(name, money, ratio), risk(_risk) {}
//	int GetPay() const {
//		return SalesWorker::GetPay() * RISK_LEVEL::Risk_level(risk);
//	}
//	void ShowSalaryInfo() const {
//		ShowYourName();
//		cout << "salary: " << SalesWorker::GetPay() << '\n';
//		cout << "risk pay: " << GetPay() << '\n';
//		cout << "sum: " << SalesWorker::GetPay() + GetPay() << '\n' << '\n';
//	}
//};
//
//class EmployeeHandler {
//private:
//	Employee* empList[50];
//	int empNum;
//public:
//	EmployeeHandler() : empNum(0) { };
//	void addEmployee(Employee* emp) {
//		empList[empNum++] = emp;
//	}
//	void ShowAllSalaryInfo() const {
//		for (int i = 0; i < empNum; i++) {
//			empList[i]->ShowSalaryInfo();
//		}
//	}
//	void ShowTotalSalary() const {
//		int sum = 0;
//		for (int i = 0; i < empNum; i++)
//			sum += empList[i]->GetPay();
//		cout << "salary sum: " << sum << '\n';
//	}
//	~EmployeeHandler() {
//		for (int i = 0; i < empNum; i++) {
//			delete empList[i];
//		}
//	}
//};
//
//int main() {
//	EmployeeHandler handler;
//
//	ForeignSalesWorker* fseller1 = new ForeignSalesWorker("Hong", 1000, 0.1, RISK_LEVEL::RISK_A);
//	fseller1->AddSalaryResult(7000);
//	handler.addEmployee(fseller1);
//
//	ForeignSalesWorker* fseller2 = new ForeignSalesWorker("Yoon", 1000, 0.1, RISK_LEVEL::RISK_B);
//	fseller2->AddSalaryResult(7000);
//	handler.addEmployee(fseller2);
//
//	ForeignSalesWorker* fseller3 = new ForeignSalesWorker("Lee", 1000, 0.1, RISK_LEVEL::RISK_C);
//	fseller3->AddSalaryResult(7000);
//	handler.addEmployee(fseller3);
//
//	handler.ShowAllSalaryInfo();
//
//	return 0;
//}
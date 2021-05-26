//---------------------------chap4에서 계속 2020.7.27. 월 복사생성자--------------------------//
//얕은 복사
//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <cstring>
//using namespace std;
//
//class Person {
//private:
//	char* name;
//	int age;
//public:
//	Person(const char* myname, int myage) {
//		int len = strlen(myname) + 1;
//		name = new char[len];
//		strcpy(name, myname);
//		age = myage;
//	}
//	void ShowPersonInfo() const {
//		cout << "이름: " << name << '\n';
//		cout << "나이: " << age << '\n';
//	}
//	~Person() {
//		delete[]name;
//		cout << "called destructor!" << '\n';
//	}
//};
//
//int main() {
//	Person man1("Lee dong woo", 29);
//	Person man2 = man1;
//	man1.ShowPersonInfo();
//	man2.ShowPersonInfo();
//
//	return 0;
//}

//깊은 복사
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Person {
private:
	char* name;
	int age;
public:
	Person(const char* myname, int myage) {
		name = new char[strlen(myname) + 1];
		strcpy(name, myname);
		age = myage;
	}
	Person(const Person& copy)
		:age(copy.age) {
		name = new char[strlen(copy.name) + 1];
		strcpy(name, copy.name);
	}
	void ShowPersonInfo() const {
		cout << "이름: " << name << '\n';
		cout << "나이: " << age << '\n';
	}
	~Person() {
		delete[]name;
		cout << "called destructor!" << '\n';
	}
};

int main() {
	Person man1("Lee dong woo", 29);
	Person man2 = man1;
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();

	return 0;
}


//this 포인터 활용, 복사생성자 정의
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

namespace COMP_POS {
	enum {
		CLERK, SENIOR, ASSIST, MANAGER
	};
	void ShowPosition(int pos) {
		switch (pos) {
		case CLERK:
			cout << "CLERK" << '\n';
			break;
		case SENIOR:
			cout << "SENIOR" << '\n';
			break;
		case ASSIST:
			cout << "ASSIST" << '\n';
			break;
		case MANAGER:
			cout << "MANAGER" << '\n';
			break;
		}
	}
}

class NameCard {
private:
	char* name;
	char* company;
	char* phone;
	int position;
public:
	NameCard(const char* name, const char* company, const char* phone, int _position)
		:position(_position) {
		this->name = new char[strlen(name) + 1];
		this->company = new char[strlen(company) + 1];
		this->phone = new char[strlen(phone) + 1];

		strcpy(this->name, name);
		strcpy(this->company, company);
		strcpy(this->phone, phone);
	}
	NameCard(const NameCard& copy)
		:position(copy.position) {
		name = new char[strlen(copy.name) + 1];
		company = new char[strlen(copy.company) + 1];
		phone = new char[strlen(copy.phone) + 1];

		strcpy(name, copy.name);
		strcpy(company, copy.company);
		strcpy(phone, copy.phone);
	}

		void ShowNameCardInfo() {
		cout << "이름: " << name << '\n';
		cout << "회사: " << company << '\n';
		cout << "전화번호: " << phone << '\n';
		cout << "직급: ";
		COMP_POS::ShowPosition(position);
		cout << '\n';
	}

	~NameCard() {
		delete[]name;
		delete[]company;
		delete[]phone;
		cout << "called destructor!" << '\n';
	}
};

int main() {
	NameCard manClerk("LEE", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
	NameCard copy1 = manClerk;
	NameCard manSenior("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
	NameCard copy2 = manSenior;
	copy1.ShowNameCardInfo();
	copy2.ShowNameCardInfo();

	return 0;
}

//#include <iostream>
//using namespace std;
//
//class SoSimple {
//private:
//	int num;
//public:
//	SoSimple(int n)
//		:num(n) {}
//	SoSimple(const SoSimple& copy)
//		:num(copy.num) {
//		cout << "Calles SoSimple(const SoSimple& copy)" << '\n';
//	}
//	SoSimple& AddNum(int n) {
//		num += n;
//		return *this;
//	}
//	void ShowData() {
//		cout << "num: " << num << '\n';
//	}
//};
//
//SoSimple SimpleFunObj(SoSimple ob) {
//	cout << "return 이전" << '\n';
//	return ob;
//}
//
//int main() {
//	SoSimple obj(7);
//	SimpleFunObj(obj).AddNum(30).ShowData();
//	obj.ShowData();
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//class SoSimple {
//private:
//	int num;
//public:
//	SoSimple(int n)
//		: num(n) {
//		cout << "New Object: " << this << '\n';
//	}
//	SoSimple(const SoSimple& copy)
//		: num(copy.num) {
//		cout << "New Copy Object: " << this << '\n';
//	}
//	~SoSimple() {
//		cout << "Destroy obj: " << this << '\n';
//	}
//};
//
//SoSimple SimpleFuncObj(SoSimple ob) {
//	cout << "Parm ADR: " << &ob << '\n';
//	return ob;
//}
//
//int main() {
//	SoSimple obj(7);
//	SimpleFuncObj(obj);
//
//	cout << '\n';
//	SoSimple tempRef = SimpleFuncObj(obj); //ob가 복사생성자를 호출하여 obj를 복사, ob가 반환되며 임시객체 생성, 이 구문은 새로운 객체를 생성하는 게 아니라 이름 없는 임시객체에 tempRef라는 이름을 붙여준 것이므로 new copy가 따로 출력되지 않는다!
//	cout << "Return Obj" << &tempRef << '\n';
//	return 0;
//}
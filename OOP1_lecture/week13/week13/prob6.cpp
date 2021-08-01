//#include <iostream>
//#include <string>
//using namespace std;
//
//class Employee {
//private:
//	string name;
//	int age;
//	int salary;
//	int years;
//public:
//	Employee(string name, int age, int salary, int years) {
//		this->name = name;
//		this->age = age;
//		this->salary = salary;
//		this->years = years;
//	}
//	string getName() { return name; }
//	int getAge() { return age; }
//	int getSalary() { return salary; }
//	int getYears() { return years; }
//};
//
//int main() {
//	Employee* eArr[2];
//
//	for (int i = 0; i < 2; i++) {
//		string name;
//		int age;
//		int salary;
//		int years;
//
//		cout << "Please input name age salary years : ";
//		cin >> name >> age >> salary >> years;
//
//		eArr[i] = new Employee(name, age, salary, years);
//	}
//
//	for (int i = 0; i < 2; i++) {
//		cout << eArr[i]->getName() << ", "
//			<< eArr[i]->getAge() << ", "
//			<< eArr[i]->getSalary() << ", "
//			<< eArr[i]->getYears() << '\n';
//	}
//}
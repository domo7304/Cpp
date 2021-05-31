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
//	void setName(string name) { this->name = name; }
//	void setAge(int age) { this->age = age; }
//	void setSalary(int salary) { this->salary = salary; }
//	void setYears(int years) { this->years = years; }
//	string getName() { return name; }
//	int getAge() { return age; }
//	int getSalary() { return salary; }
//	int getYears() { return years; }
//};
//
//void print(Employee*, int);
//
//int main() {
//	Employee e1("name1", 30, 200, 10);
//	Employee e2("name2", 35, 300, 15);
//
//	Employee employee[2] = { e1, e2 };
//	print(employee, 2);
//}
//
//void print(Employee* e, int num) {
//	for (int i = 0; i < num; i++) {
//		cout << "Element " << i << " : "
//			<< e[i].getName() << ", "
//			<< e[i].getAge() << ", "
//			<< e[i].getSalary() << ", "
//			<< e[i].getYears() << '\n';
//	}
//}
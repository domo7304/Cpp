#include <iostream>
using namespace std;

void swap(int&, int&);
void swap(float&, float&);
void swap(char&, char&);

int main() {
	int n1, n2;
	float n3, n4;
	char c1, c2;

	cout << "Please input 2 data(integer) : ";
	cin >> n1 >> n2;
	cout << "before running swap funcion, the date :" << n1 << ", " << n2 << '\n';
	swap(n1, n2);
	cout << "after running swap funcion, the date :" << n1 << ", " << n2 << "\n\n";

	cout << "Please input 2 data(float) : ";
	cin >> n3 >> n4;
	cout << "before running swap funcion, the date :" << n3 << ", " << n4 << '\n';
	swap(n3, n4);
	cout << "after running swap funcion, the date :" << n3 << ", " << n4 << "\n\n";

	cout << "Please input 2 data(char) : ";
	cin >> c1;
	cin.ignore();
	cin >> c2;
	cout << "before running swap funcion, the date :" << c1 << ", " << c2 << '\n';
	swap(c1, c2);
	cout << "after running swap funcion, the date :" << c1 << ", " << c2 << "\n\n";
}

void swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void swap(float& a, float& b) {
	float tmp = a;
	a = b;
	b = tmp;
}

void swap(char& a, char& b) {
	char tmp = a;
	a = b;
	b = tmp;
}
#include <iostream>
using namespace std;

inline void calculator(double, double);

int main() {
	double num1, num2;
	cout << "input 2 floats : ";
	cin >> num1 >> num2;

	calculator(num1, num2);
}

inline void calculator(double num1, double num2) {
	int select;
	cout << "Select sum -1, substract - 2, multiply - 3, division - 4 : ";
	cin >> select;

	switch (select) {
		case 1:
			cout << num1 << " + " << num2 << " = " << num1 + num2 << '\n';
			break;
		case 2:
			cout << num1 << " - " << num2 << " = " << num1 - num2 << '\n';
			break;
		case 3:
			cout << num1 << " * " << num2 << " = " << num1 * num2 << '\n';
			break;
		case 4:
			cout << num1 << " / " << num2 << " = " << num1 / num2 << '\n';
			break;
	}
}
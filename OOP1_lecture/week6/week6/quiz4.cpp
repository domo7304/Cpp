#include <iostream>
using namespace std;

int decimalToBinary(int);

int main() {
	int num;
	cout << "Input decimal num (0 to 1023) : ";
	cin >> num;

	cout << "to binary..:" << decimalToBinary(num) << '\n';
}

int decimalToBinary(int num) {
	int binaryNum = 0;

	for (int i = 1; num > 0; i *= 10) {
		binaryNum += (num % 2) * i;
		num /= 2;
	}

	return binaryNum;
}
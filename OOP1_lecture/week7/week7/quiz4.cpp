#include <iostream>
using namespace std;

void binary(int);

int main() {
	int num;
	cout << "Input decmal num : ";
	cin >> num;

	binary(num);
	cout << '\n';
}

void binary(int num) {
	if (num == 0 || num == 1) cout << num;
	else {
		binary(num / 2);
		cout << num % 2;
	}
}
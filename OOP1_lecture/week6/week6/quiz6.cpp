#include <iostream>
using namespace std;

void function(int);

int main() {
	int num;
	cout << "Input your number : ";
	cin >> num;

	function(num);
}

void function(int num) {
	for (int i = 0; i < num; i++) {
		for (int j = 1; j < (num - i); j++) {
			cout << "  ";
		}
		for (int j = i; j >= 0; j--) {
			cout << (j + 1) << " ";
		}
		for (int j = 2; j <= (i + 1); j++) {
			cout << j << " ";
		}
		cout << '\n';
	}
}
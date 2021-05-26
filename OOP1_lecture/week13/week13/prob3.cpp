#include <iostream>
using namespace std;

int* compareInt(int*, int*, int*);

int main() {
	int a, b, c;
	cin >> a >> b >> c;

	int* max_main = compareInt(&a, &b, &c);

	cout << "Address of max_main : " << max_main << '\n'
		<< "Value of max_main : " << *max_main << '\n';
}

int* compareInt(int* a, int* b, int* c) {
	int* max = 0;

	cout << "Address of parameters" << '\n'
		<< "a : " << a << '\n'
		<< "b : " << b << '\n'
		<< "c : " << c << "\n\n";

	*a > * b ? max = a : max = b;
	cout << "Address of max : " << max << '\n'
		<< "Value of max : " << *max << "\n\n";

	*c > * max ? max = c : max;

	cout << "Address of max : " << max << '\n'
		<< "Value of max : " << *max << "\n\n";

	return max;
}
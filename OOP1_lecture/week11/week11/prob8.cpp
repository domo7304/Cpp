#include <iostream>
using namespace std;

void swap3elem(int*, int*, int*);

int main() {
	int a = 10, b = 20, c = 30;
	cout << "Before swap : " << a << ", " << b << ", " << c << '\n';

	swap3elem(&a, &b, &c);

	cout << "After swap : " << a << ", " << b << ", " << c << '\n';
}

void swap3elem(int* a, int* b, int* c) {
	int tmp = *c;
	*c = *b;
	*b = *a;
	*a = tmp;
}
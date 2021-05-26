#include <iostream>
using namespace std;

int* getPointer(int*);
int* getPointer(int);

int main() {
	int x = 10;
	int* xptr = &x;
	int* xptr2 = getPointer(&x);

	cout << "x : " << x << '\n';
	cout << "xptr : " << xptr << '\t';
	cout << "*ptr : " << *xptr << '\n';
	cout << "xptr2 : " << xptr2 << '\t';
	cout << "*xptr2 : " << *xptr2 << '\n';

	int* xptr3 = getPointer(x);
	cout << "xptr3 : " << xptr3 << '\n';
	cout << "*xptr3 : " << *xptr3 << '\n';
	cout << "\n\n";
}

int* getPointer(int* x) {
	return x;
}

int* getPointer(int x) {
	return &x;
}
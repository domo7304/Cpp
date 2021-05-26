#include <iostream>
using namespace std;

#define PI (3.14)
double getArea(double);
double getArea(double*);

int main() {
	double r = 5;

	cout << "Area (calculated by call by value) : " << getArea(r) << '\n';
	cout << "Area (calculated by call by reference) : " << getArea(&r) << '\n';
}

double getArea(double r) {
	return (r * r * PI);
}

double getArea(double* r) {
	return ((*r) * (*r) * PI);
}
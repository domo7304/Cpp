#include <iostream>
using namespace std;

int rectangle(int, int);
double circle(int);
double triangle(float, float);

int main() {
	int num;
	cout << "please select hape 1 - rectangle, 2 - circle, 3 - triangle : ";
	cin >> num;

	switch (num) {
	case 1:
		int n1, n2;
		cout << "You are select retangle, please input two integer for length and height : ";
		cin >> n1 >> n2;
		cout << "the area is : " << rectangle(n1, n2) << '\n';
		break;
	case 2:
		int r;
		cout << "You are select circle, please input one integer for radius : ";
		cin >> r;
		cout << "the area is : " << circle(r) << '\n';
		break;
	case 3:
		float edge, height;
		cout << "You are select triangle, please input two integer for edge and height : ";
		cin >> n1 >> n2;
		cout << "the area is : " << triangle(n1, n2) << '\n';
		break;
	}
}

int rectangle(int n1, int n2) {
	return n1 * n2;
}

double circle(int r) {
	return r * r * 3.14;
}

double triangle(float edge, float height) {
	return edge * height * 0.5;
}
#include <iostream>
using namespace std;

int gcd(int, int);

int main() {
	int n1, n2;
	cout << "Enter any two numbers to find GCD : ";
	cin >> n1 >> n2;

	if (n1 < n2) {
		int tmp = n1;
		n1 = n2;
		n2 = tmp;
	}

	cout << "GCD of " << n1 << " and " << n2 << " = " << gcd(n1, n2) << '\n';
}

int gcd(int a, int b) {
	return a % b == 0 ? b : gcd(b, a % b);
}
#include <iostream>
using namespace std;

bool isPrimeNumber(int);
int getNextPrime();
int prime = 1;

int main() {
	for (int i = 0; i < 10; i++) {
		cout << getNextPrime() << '\n';
	}
}

bool isPrimeNumber(int n) {
	for (int i = 2; i < n; i++)
		if (n % i == 0) return false;
	return true;
}

int getNextPrime() {
	while (isPrimeNumber(++prime) == false);
	return prime;
}
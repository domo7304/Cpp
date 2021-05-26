#include <iostream>
using namespace std;

void sumOfSquares(int, int);

int main() {
	int mean = 2;
	
	for (int x = 2; x < 10; x++) {
		sumOfSquares(x, mean);
	}
}

void sumOfSquares(int x, int mean) {
	static int nStatic = 0;

	nStatic += (x - mean) * (x - mean);

	cout << "Sum of squeare in x = " << x << " : " << nStatic << '\n';
}
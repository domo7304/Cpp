#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

void sumOfSquares(int, int);

int main() {
	srand((unsigned)time(NULL));
	int mean;
	cout << "Input your mean : ";
	cin >> mean;
	
	for (int i = 0; i < 10; i++) {
		int num = (rand() % 101);
		sumOfSquares(num, mean);
	}
}

void sumOfSquares(int num, int mean) {
	static int nStatic = 0;

	nStatic += (num - mean) * (num - mean);

	cout << "Sum of squares in x = " << num << " : " << nStatic << '\n';
}
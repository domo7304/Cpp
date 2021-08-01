#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	srand((unsigned)time(NULL));
	int arr[20] = {};

	for (int i = 0; i < 20; i++) arr[i] = (rand() % 21);

	cout << setw(7) << "Element" << setw(7) << "Value" << setw(15) << "Histogram" << '\n';

	for (int i = 0; i < 20; i++) {
		cout << setw(7) << i << setw(7) << arr[i] << setw(7);
		for (int j = 0; j < arr[i]; j++) cout << "*";
		cout << '\n';
	}
}
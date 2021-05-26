#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	srand((unsigned)time(NULL));

	int arr[20];
	for (int i = 0; i < 20; i++) {
		arr[i] = rand() % 21;
	}

	cout << "Element" << setw(13) << "Values" << setw(17)
		<< "Histogram" << '\n';

	for (int i = 0; i < 20; i++) {
		cout << setw(7) << i << setw(13) << arr[i] << setw(9);

		for (int j = 0; j < arr[i]; j++) cout << '*';
		cout << '\n';
	}
}
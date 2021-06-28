#include <iostream>
using namespace std;

int main() {
	srand((unsigned)time(null));
	int arr1[10] = { 5, 10, 36, 42, 49, 53, 62, 71, 79, 82 };
	int arr2[11] = { 0 };
	int idx = 10;
	int num = rand() % 101;

	cout << "arr1 is ";
	for (int i = 0; i < 10; i++) cout << arr1[i] << " ";
	cout << "\nrandom number is " << num << '\n';

	for (int i = 0; i < 10; i++) {
		if (arr1[i] <= num) arr2[i] = arr1[i];
		else if (arr1[i] > num) {
			idx = i;
			break;
		}
	}
	arr2[idx] = num;
	for (int i = idx; i < 10; i++) arr2[i + 1] = arr1[i];

	cout << "arr2 is ";
	for (int i = 0; i < 11; i++) cout << arr2[i] << " ";
	cout << "\n";
}
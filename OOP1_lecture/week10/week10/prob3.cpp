#include <iostream>
using namespace std;

int main() {
	srand((unsigned)time(NULL));
	int arr[10] = {};

	for (int i = 0; i < 10; i++) arr[i] = (rand() % 97) + 3;

	for (int i = 0; i < 10; i++) {
		int minIndex = i;
		for (int j = i; j < 10; j++) {
			if (arr[j] < arr[minIndex]) minIndex = j;
		}

		int tmp = arr[minIndex];
		arr[minIndex] = arr[i];
		arr[i] = tmp;
	}
	for (int j = 0; j < 10; j++) cout << arr[j] << " ";
	cout << "\n\n";

	cout << "가장 큰 수는 : " << arr[9] << " " << arr[8] << " " << arr[7] << " 입니다. \n";
}
#include <iostream>
using namespace std;

int main() {
	srand((unsigned)time(NULL));
	int arr[10];
	int max[3] = { 0 };

	for (int i = 0; i < 10; i++) arr[i] = (rand() % 98 + 3);
	cout << "������ int �迭�� : ";
	for (int i = 0; i < 10; i++) cout << arr[i] << " ";

	int maxIdx = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 10; j++) {
			if (arr[j] > arr[maxIdx]) maxIdx = j;
		}
		max[i] = arr[maxIdx];
		arr[maxIdx] = 0;
	}

	cout << "\n�� �� ���� ū 3���� ���� ";
	for (int i = 0; i < 3; i++) cout << max[i] << " ";
	cout << "�Դϴ�.\n";
}
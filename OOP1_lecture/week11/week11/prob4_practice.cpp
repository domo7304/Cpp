#include <iostream>
using namespace std;

void print(int[]);

int main() {
	int arr[5] = { 0 };
	cout << "5���� ���� �ٸ� ���ڸ� �Է��ϼ��� : ";
	for (int i = 0; i < 5; i++) cin >> arr[i];

	print(arr);
}

void print(int arr[]) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) cout << arr[i] << arr[j] << arr[k] << " ";
		}
	}
}
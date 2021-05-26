#include <iostream>
#include <iomanip>
using namespace std;

const int arraysize = 10;
void bubblesort(int[]);

int main() {
	int a[arraysize] = { 2, 6, 4, 8, 10, 12, 89, 68, 45, 37 };

	cout << "data items in original order\n";
	for (int i = 0; i < arraysize; i++) cout << setw(4) << a[i];

	bubblesort(a);

	cout << "\n\nresult :";
	for (int k = 0; k < arraysize; k++) cout << setw(4) << a[k];
	cout << "\n";
}

void bubblesort(int arr[]) {
	for (int i = 0; (i < arraysize - 1); i++) {
		int cnt = 0;
		for (int j = 0; j < arraysize - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int hold = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = hold;
				cnt++;
			}
		}
		if (cnt == 0) return;
		cout << "\ndata items in ascending order\n";
		for (int j = 0; j < arraysize; j++) cout << setw(4) << arr[j];
	}
}
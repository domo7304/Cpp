//#include <iostream>
//#include <iomanip>
//using namespace std;
//
//int const arr_size = 10;
//void bubblesort(int[]);
//
//int main() {
//	srand((unsigned)time(NULL));
//	int arr[arr_size] = { 0 };
//	for (int i = 0; i < arr_size; i++) arr[i] = (rand() % 100 + 1);
//	cout << "Original : ";
//	for (int i = 0; i < arr_size; i++) cout << setw(3) << arr[i] << " ";
//	cout << "\n\n";
//
//	bubblesort(arr);
//}
//
//void bubblesort(int arr[]) {
//	for (int i = 0; i < arr_size - 1; i++) {
//		int cnt = 0;
//		for (int j = 0; j < arr_size - 1; j++) {
//			if (arr[j] > arr[j + 1]) {
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//				cnt++;
//				cout << arr[j + 1] << " and " << arr[j] << " is changed!\n";
//			}
//		}
//		if (cnt == 0) return;
//		cout << setw(7) << "\nPass " << i << " : ";
//		for (int j = 0; j < arr_size; j++) cout << setw(3) << arr[j] << " ";
//		cout << "\n\n";
//	}
//}
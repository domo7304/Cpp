//#include <iostream>
//using namespace std;
//
//int main() {
//	char arr[100] = {};
//	int arrSize = 100;
//	cin >> arr;
//
//	for (int i = 0; i < arrSize; i++) {
//		int minIndex = i;
//		for (int j = i; j < arrSize; j++) {
//			if (arr[j] < arr[minIndex]) minIndex = j;
//		}
//		int tmp = arr[i];
//		arr[i] = arr[minIndex];
//		arr[minIndex] = tmp;
//	}
//	for (int i = 0; i < arrSize; i++) cout << arr[i];
//	cout << "\n";
//}
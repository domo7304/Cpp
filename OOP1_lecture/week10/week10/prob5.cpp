//#include <iostream>
//using namespace std;
//
//int main() {
//	srand((unsigned)time(NULL));
//	int arr1[10] = { 5,10,36,42,49,53,62,71,79,82 };
//	int randNum = rand() % 101, index = 10;
//
//	for (int i = 0; i < 9; i++) {
//		if (arr1[i] <= randNum && randNum <= arr1[i + 1]) {
//			index = i + 1;
//		}
//	}
//	int arr2[11] = {};
//	for (int i = 0; i < index; i++) {
//		arr2[i] = arr1[i];
//	}
//	arr2[index] = randNum;
//	for (int i = index; i < 10; i++) {
//		arr2[i + 1] = arr1[i];
//	}
//
//	for (int i = 0; i < 10; i++) cout << arr1[i] << " ";
//	cout << "\n\nrandum number : " << randNum << "\n\n";
//	for (int i = 0; i < 11; i++) cout << arr2[i] << " ";
//	cout << '\n';
//}
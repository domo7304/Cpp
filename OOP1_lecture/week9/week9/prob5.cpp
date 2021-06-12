//#include <iostream>
//using namespace std;
//
//const int arraySize = 100;
//int linearSearch(const int[], int, int);
//void outArr(int[], int);
//int findMax(int[], int);
//
//int main() {
//	srand((unsigned int)time(NULL));
//	int a[arraySize];
//	int searchKey;
//
//	for (int i = 0; i < arraySize; i++) a[i] = (rand() % 100) + 1;
//	outArr(a, arraySize);
//	cout << "max value is " << findMax(a, arraySize) << "\n\n\n";
//
//	cout << "Enter integer search key : ";
//	cin >> searchKey;
//
//	int element = linearSearch(a, searchKey, arraySize);
//
//	if (element != -1) cout << "Found value in element " << element << '\n';
//	else cout << "Value not found" << '\n';
//}
//
//int linearSearch(const int array[], int key, int sizeOfArray) {
//	for (int j = 0; j < sizeOfArray; j++) {
//		if (array[j] == key) return j;
//	}
//	return -1;
//}
//
//void outArr(int array[], int size) {
//	for (int i = 0; i < size; i++) cout << i << "th : " << array[i] << '\n';
//}
//
//int findMax(int array[], int size) {
//	int max = -1;
//	for (int i = 0; i < size; i++) {
//		if (array[i] > max) max = array[i];
//	}
//	return max;
//}
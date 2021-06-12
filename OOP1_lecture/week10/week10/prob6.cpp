//#include <iostream>
//using namespace std;
//
//int main() {
//	srand((unsigned)time(NULL));
//	int row, col;
//	cout << "Input row and column : ";
//	cin >> row >> col;
//
//	int** arr = new int* [row];
//	for (int i = 0; i < row; i++) arr[i] = new int[col];
//
//	for (int i = 0; i < row; i++) {
//		for (int j = 0; j < col; j++) arr[i][j] = rand() % 100;
//	}
//
//	cout << "< Before swap >" << '\n';
//	for (int i = 0; i < row; i++) {
//		for (int j = 0; j < col; j++) cout << arr[i][j] << " ";
//		cout << '\n';
//	}
//
//	for (int i = 0; i < (row / 2); i++) {
//		for (int j = 0; j < col; j++) {
//			int tmp = arr[i][j];
//			arr[i][j] = arr[row - 1 - i][j];
//			arr[row - 1 - i][j] = tmp;
//		}
//	}
//
//	cout << "< After swap >" << '\n';
//	for (int i = 0; i < row; i++) {
//		for (int j = 0; j < col; j++) cout << arr[i][j] << " ";
//		cout << '\n';
//	}
//
//	for (int i = 0; i < row; i++) delete[] arr[i];
//	delete[] arr;
//}
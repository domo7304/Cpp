#include <iostream>
#include <iomanip>
using namespace std;

int** change(int**, int, int);

int main() {
	srand((unsigned)time(NULL));
	int row, col;
	cout << "row�� col�� �Է��ϼ��� : ";
	cin >> row >> col;

	int** arr = new int* [row];
	for (int i = 0; i < row; i++) arr[i] = new int[col];

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) arr[i][j] = rand() % 101;
	}

	cout << "\n< ������ �迭 > \n";
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) cout << setw(2) << arr[i][j] << " ";
		cout << '\n';
	}

	int** arr2 = new int* [col];
	for (int i = 0; i < col; i++) arr2[i] = new int[row];

	arr2 = change(arr, row, col);

	cout << "\n< ��ġ �� �迭 > \n";
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) cout << setw(2) << arr2[i][j] << " ";
		cout << '\n';
	}
}

int** change(int** arr, int row, int col) {
	int** arr2 = new int* [col];
	for (int i = 0; i < col; i++) arr2[i] = new int[row];

	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) arr2[i][j] = arr[j][i];
	}

	return arr2;
}

#include <iostream>
#include <iomanip>
using namespace std;

int** change(int**, int, int);

const int row = 3;
const int col = 4;

int main() {
	srand((unsigned)time(NULL));

	int** arr = new int* [row];
	for (int i = 0; i < row; i++) arr[i] = new int[col];

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) arr[i][j] = rand() % 101;
	}

	cout << "\n< ������ �迭 > \n";
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) cout << setw(2) << arr[i][j] << " ";
		cout << '\n';
	}

	int** arr2 = new int* [col];
	for (int i = 0; i < col; i++) arr2[i] = new int[row];

	arr2 = change(arr, row, col);

	cout << "\n< ��ġ �� �迭 > \n";
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) cout << setw(2) << arr2[i][j] << " ";
		cout << '\n';
	}
}

int** change(int** arr, int row, int col) {
	int** arr2 = new int* [col];
	for (int i = 0; i < col; i++) arr2[i] = new int[row];

	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) arr2[i][j] = arr[j][i];
	}

	return arr2;
}
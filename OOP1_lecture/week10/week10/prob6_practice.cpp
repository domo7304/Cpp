#include <iostream>
#include <iomanip>
using namespace std;

void row_change(int**, int, int);
void col_change(int**, int, int);

int main() {
	srand((unsigned)time(NULL));
	int row, col;
	cout << "Input row and column : ";
	cin >> row >> col;
	
	int** arr = new int*[row];
	for (int i = 0; i < row; i++) arr[i] = new int[col];

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) arr[i][j] = rand() % 101;
	}

	cout << "< 원래의 배열 >" << '\n';
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << setw(3) << arr[i][j] << " ";
		}
		cout << "\n";
	}

	cout << "\n< 행으로 배열을 접었을 경우 >" << '\n';
	row_change(arr, row, col);

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << setw(3) << arr[i][j] << " ";
		}
		cout << "\n";
	}

	cout << "\n< 열로 배열을 접었을 경우 >" << '\n';
	col_change(arr, row, col);

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << setw(3) << arr[i][j] << " ";
		}
		cout << "\n";
	}

	for (int i = 0; i < row; i++) delete[] arr[i];
	delete[] arr;
}

void row_change(int** arr, int row, int col) {
	for (int i = 0; i < row / 2; i++) {
		for (int j = 0; j < col; j++) {
			int tmp = arr[i][j];
			arr[i][j] = arr[row - i - 1][j];
			arr[row - i - 1][j] = tmp;
		}
	}
}

void col_change(int** arr, int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col / 2; j++) {
			int tmp = arr[i][j];
			arr[i][j] = arr[i][col - j - 1];
			arr[i][col - j - 1] = tmp;
		}
	}
}

/*
	업그레이드 해서, 배열의 사이즈를 사용자로부터 입력받고, 입력받은 배열을 rand로 채우고
	한 번은 행으로 접기
	한 번은 열로 접기 
	이렇게 두 번 보여주는 프로그램으로 해보자
*/

/*
	2차원 배열 동적 할당 
	1. int** arr = new int* [row];
	2. for (int i = 0; i < row; i++) arr[i] = new int[col];

	첫 번째로 int** 2차원 공간 만들어주고, 각 row를 동적할당 해주기 위해 int* 로 만들어주기
	두 번째로 for문을 이용하여 각 row에 대한 col를 동적할당 마무리

	삭제할 때에는 

	for (int i = 0; i < row; i++) delete[] arr[i];
	delete[] arr;

	첫 번쨰로 각 row의 col을 지워주고
	배열 전체를 지워주면 됨
*/
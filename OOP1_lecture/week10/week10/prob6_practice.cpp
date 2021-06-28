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

	cout << "< ������ �迭 >" << '\n';
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << setw(3) << arr[i][j] << " ";
		}
		cout << "\n";
	}

	cout << "\n< ������ �迭�� ������ ��� >" << '\n';
	row_change(arr, row, col);

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << setw(3) << arr[i][j] << " ";
		}
		cout << "\n";
	}

	cout << "\n< ���� �迭�� ������ ��� >" << '\n';
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
	���׷��̵� �ؼ�, �迭�� ����� ����ڷκ��� �Է¹ް�, �Է¹��� �迭�� rand�� ä���
	�� ���� ������ ����
	�� ���� ���� ���� 
	�̷��� �� �� �����ִ� ���α׷����� �غ���
*/

/*
	2���� �迭 ���� �Ҵ� 
	1. int** arr = new int* [row];
	2. for (int i = 0; i < row; i++) arr[i] = new int[col];

	ù ��°�� int** 2���� ���� ������ְ�, �� row�� �����Ҵ� ���ֱ� ���� int* �� ������ֱ�
	�� ��°�� for���� �̿��Ͽ� �� row�� ���� col�� �����Ҵ� ������

	������ ������ 

	for (int i = 0; i < row; i++) delete[] arr[i];
	delete[] arr;

	ù ������ �� row�� col�� �����ְ�
	�迭 ��ü�� �����ָ� ��
*/
/*
	��� �غ���

	�迭�� ���� �ϳ� �� ����
	���� �迭�� �� ������ ���� ���� �迭�� �ش� ���Ұ� ������ ����ִ� ������ 
*/

#include <iostream>
using namespace std;

int main() {
	char str[100];
	char new_str[100];
	cout << "Char �迭 ���� �Է��ϼ��� : ";
	cin >> str;

	int str_size = strlen(str);
	int new_str_size = 0;

	for (int i = 0; i < str_size; i++) {
		bool flag = true;
		for (int j = 0; j < new_str_size; j++) {
			if (str[i] == new_str[j]) flag = false;
		}
		if (flag) {
			new_str[new_str_size] = str[i];
			new_str_size++;
		}
	}

	cout << "�ߺ� ���� �� char : ";
	for (int i = 0; i < new_str_size; i++) cout << new_str[i] << " ";
	cout << '\n';
}
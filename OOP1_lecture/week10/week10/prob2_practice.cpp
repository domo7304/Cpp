#include <iostream>
using namespace std;

int main() {
	srand((unsigned)time(NULL));
	char str1[5], str2[5];

	for (int i = 0; i < 5; i++) str1[i] = (rand() % 9 + 1) + '0';
	for (int i = 0; i < 5; i++) str2[i] = (rand() % 9 + 1) + '0';

	cout << "char1 = ";
	for (int i = 0; i < 5; i++) cout << str1[i];
	cout << "\nchar2 = ";
	for (int i = 0; i < 5; i++) cout << str2[i];
	cout << '\n' << "�̸� ";

	int flag = 0;
	for (int i = 0; i < 5; i++) {
		if (str1[i] > str2[i]) {
			flag = 1;
			break;
		}
		else if (str1[i] < str2[i]) {
			flag = 2;
			break;
		}
	}

	if (flag == 0) cout << "�� ���� �迭�� �����ϴ�." << '\n';
	else if (flag == 1) cout << "char1�� char2���� Ů�ϴ�." << '\n';
	else cout << "char2�� char1���� Ů�ϴ�." << '\n';
}
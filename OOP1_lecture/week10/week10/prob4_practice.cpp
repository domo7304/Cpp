#include <iostream>
using namespace std;

int main() {
	char str[100];
	cout << "�迭�� �Է��ϼ���(�ִ� 100����) : ";
	cin >> str;
	cout << "�Էµ� �迭�� ������ �����ϴ� : " << str << '\n';

	int str_len = strlen(str);

	for (int i = 0; i < str_len / 2; i++) {
		char tmp = str[i];
		str[i] = str[str_len - i - 1];
		str[str_len - i - 1] = tmp;
	}
	cout << "�Ųٷ� ������ �迭�� ������ �����ϴ� : " << str << '\n';
}
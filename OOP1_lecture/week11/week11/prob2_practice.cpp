#include <iostream>
using namespace std;

void bubblesort(char*);

int main() {
	char str[100];
	cout << "Char 배열을 입력하세요 : ";
	cin >> str;

	bubblesort(str);

	cout << "정렬 후 char : ";
	for (int i = 0; i < strlen(str); i++) cout << str[i] << " ";
	cout << '\n';
}

void bubblesort(char* str) {
	for (int i = 0; i < strlen(str) - 1; i++) {
		bool flag = true;
		for (int j = 0; j < strlen(str) - 1; j++) {
			if (str[j] > str[j + 1]) {
				char tmp = str[j];
				str[j] = str[j + 1];
				str[j + 1] = tmp;
				flag = false;
			}
		}
		if (flag) return;
		cout << "\nPass" << i << " : ";
		for (int j = 0; j < strlen(str); j++) cout << str[j] << " ";
	}
}
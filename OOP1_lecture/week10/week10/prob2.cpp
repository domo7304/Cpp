#include <iostream>
using namespace std;

int main() {
	srand((unsigned)time(NULL));
	char char1[5] = {}, char2[5] = {};

	for (int i = 0; i < 5; i++) char1[i] = (rand() % 9) + '0';
	for (int i = 0; i < 5; i++) char2[i] = (rand() % 9) + '0';

	for (int i = 0; i < 5; i++) {
		cout << char1[i] << " ";
	}
	cout << '\n';
	for (int i = 0; i < 5; i++) {
		cout << char2[i] << " ";
	}
	cout << '\n';

	int flag = 1;
	for (int i = 0; i < 5; i++) {
		if (char1[i] > char2[i]) break;
		else if (char1[i] < char2[i]) {
			flag = 2;
			break;
		}
		else if (i == 4) flag = 3;
	}

	if (flag == 1) cout << "char1은 char2보다 더 큽니다." << '\n';
	else if (flag == 2) cout << "char2가 char1보다 더 큽니다." << '\n';
	else cout << "char1과 char2는 같습니다." << '\n';
}
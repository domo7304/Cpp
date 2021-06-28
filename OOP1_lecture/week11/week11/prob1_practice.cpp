/*
	어떻게 해볼까

	배열을 새로 하나 더 만들어서
	원래 배열을 돌 때마다 새로 만든 배열에 해당 원소가 없으면 집어넣는 식으로 
*/

#include <iostream>
using namespace std;

int main() {
	char str[100];
	char new_str[100];
	cout << "Char 배열 값을 입력하세요 : ";
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

	cout << "중복 제거 후 char : ";
	for (int i = 0; i < new_str_size; i++) cout << new_str[i] << " ";
	cout << '\n';
}
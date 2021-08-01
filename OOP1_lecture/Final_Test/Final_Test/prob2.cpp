#include <iostream>
#include <string>
using namespace std;

const int length = 20;

void change_int(int arr[], int len) {
	int arr_result[length] = { 0 };
	int index = 0;

	for (int i = 0; i < len; i++) {
		bool flag = true;
		for (int j = 0; j < len; j++) {
			if (arr_result[j] == arr[i]) {
				flag = false;
			}
		}
		if (flag) {
			arr_result[index] = arr[i];
			index++;
		}
	}

	for (int i = 0; i < len; i++) {	
		for (int j = 0; j < len - 1; j++) {
			if (arr_result[j] > arr_result[j + 1]) {
				int tmp = arr_result[j];
				arr_result[j] = arr_result[j + 1];
				arr_result[j + 1] = tmp;
			}
		}
	}

	cout << "output : ";
	for (int i = 0; i < len; i++) {
		cout << arr_result[i] << " ";
	}
	cout << '\n';
}

void change_str(char str[], int len) {
	char str_result[10] = {};
	int index = 0;

	for (int i = 0; i < len; i++) {
		bool flag = true;
		for (int j = 0; j < index; j++) {
			if (str_result[j] == str[i]) {
				flag = false;
			}
		}
		if (flag) {
			str_result[index] = str[i];
			index++;
		}
	}

	for (int i = 0; i < index; i++) {
		for (int j = 0; j < index - 1; j++) {
			if (str_result[j] > str_result[j + 1]) {
				int tmp = str_result[j];
				str_result[j] = str_result[j + 1];
				str_result[j + 1] = tmp;
			}
		}
	}

	cout << "output : ";
	for (int i = 0; i < index; i++) {
		cout << str_result[i] << " ";
	}
	cout << '\n';
}

int main() {
	
	int arr[20];
	cout << "Input integer (input 20 integers) : ";
	
	for (int i = 0; i < 20; i++) {
		cin >> arr[i];
	}

	change_int(arr, 20);
	

	char str[20];
	cout << "문자를 입력해주세요 (20자) : ";
	for (int i = 0; i < 20; i++) {
		cin >> str[i];
	}

	change_str(str, 20);
}
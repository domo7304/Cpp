#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	cout << "���ڿ��� �Է��ϼ��� : ";
	getline(cin, str);

	for (int i = 0; i < str.length(); i++) {
		char tmp = str[0];
		for (int j = 0; j < str.length() - 1; j++) {
			str[j] = str[j + 1];
		}
		str[str.length() - 1] = tmp;
		cout << str << '\n';
	}
}
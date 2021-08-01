#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	cout << "문자열을 입력하세요 : ";
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
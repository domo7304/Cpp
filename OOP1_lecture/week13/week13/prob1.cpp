#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	getline(cin, str);

	for (int i = 0; i < str.length(); i++) {
		char tmp = str[0];
		for (int j = 0; j < str.length(); j++) str[j] = str[j + 1];
		str[str.length() - 1] = tmp;

		cout << i << "번째 순환 결과 : " << str << '\n';
	}
}
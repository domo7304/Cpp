#include <iostream>
using namespace std;

int main() {
	char str[100];
	cout << "배열을 입력하세요(최대 100글자) : ";
	cin >> str;
	cout << "입력된 배열은 다음과 같습니다 : " << str << '\n';

	int str_len = strlen(str);

	for (int i = 0; i < str_len / 2; i++) {
		char tmp = str[i];
		str[i] = str[str_len - i - 1];
		str[str_len - i - 1] = tmp;
	}
	cout << "거꾸로 생성된 배열은 다음과 같습니다 : " << str << '\n';
}
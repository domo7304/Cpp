//#include <iostream>
//using namespace std;
//
//int main() {
//	char str[100] = {};
//	cout << "Input your string : ";
//	cin >> str;
//
//	for (int i = 0; i < strlen(str) / 2; i++) {
//		char tmp = str[strlen(str) - 1 - i];
//		str[strlen(str) - 1 - i] = str[i];
//		str[i] = tmp;
//	}
//	cout << "문자열을 거꾸로 생성하였습니다. \n\n";
//
//	for (int i = 0; i < strlen(str); i++) cout << str[i] << " ";
//	cout << '\n';
//}
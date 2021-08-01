//#include <iostream>
//#include <string>
//using namespace std;
//
//void change(string& str);
//
//int main() {
//	string str;
//	cout << "Input text : ";
//	getline(cin, str);
//	
//	change(str);
//
//	cout << "Output text : " << str << '\n';
//}
//
//void change(string& str) {
//	for (int i = 0; i < str.length(); i++) {
//		if (str[i] == 97 || str[i] == 101 || str[i] == 105 || str[i] == 111 || str[i] == 117) {
//			cout << "char " << str[i] << " is changed to ";
//			str[i] -= 32;
//			cout << str[i] << '\n';
//		}
//	}
//}
//#include <iostream>
//using namespace std;
//
//string compareStr(string, string);
//
//int main() {
//	string str1, str2;
//	cin >> str1 >> str2;
//
//	string str = compareStr(str1, str2);
//
//	cout << str << '\n';
//}
//
//string compareStr(string str1, string str2) {
//	string str;
//
//	for (int i = 0; i < str1.length(); i++) {
//		for (int j = 0; j < str2.length(); j++) {
//			if (str1[i] == str2[j]) {
//				bool flag = true;
//				char c = str1[i];
//				for (int k = 0; k < str.length(); k++) {
//					if (str[k] == c) flag = false;
//				}
//				if (flag) str.push_back(c);
//			}
//		}
//	}
//	return str;
//}
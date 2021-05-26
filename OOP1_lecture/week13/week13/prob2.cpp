//#include<iostream>
//#include<string>
//using namespace std;
//
//int main() {
//	string str;
//	getline(cin, str, '\n');
//	int sum = 0;
//	int startIndex = 0;
//
//	while (1) {
//		int fIndex = str.find('+', startIndex);
//
//		if (fIndex == -1) {
//			string part = str.substr(startIndex);
//
//			if (part == "")	break;
//			else if (str.find('-', startIndex) != -1) {
//				int f = str.find('-', startIndex);
//				int c = f - startIndex;
//				string p = str.substr(startIndex, c);
//				cout << p << '\n';
//;				sum += stoi(p);
//				p = str.substr(f + 1, str.length() - 1);
//				cout << '-' << p << '\n';
//				sum -= stoi(p);
//				break;
//			}
//
//			cout << part << '\n';
//			sum += stoi(part);
//			break;
//		}
//
//		int count = fIndex - startIndex;
//		string part = str.substr(startIndex, count);
//
//		if (part.find("-") == -1) {
//			cout << part << '\n';
//			sum += stoi(part);
//		}
//		else {
//			string a;
//			char oper = ' ';
//
//			if (part.at(0) == '-') oper = '-';
//			else a += (part[0]);
//
//			for (int i = 1; i < count; i++) {
//				if (part[i] == '-') {
//					if (oper == '-') {
//						cout << '-' << a << '\n';
//						sum -= stoi(a);
//						a.clear();
//					}
//					else {
//						cout << a << '\n';
//						sum += stoi(a);
//						a.clear();
//					}
//					oper = '-';
//				}
//				else a += (part[i]);
//			}
//
//			if (oper == '-' && a.length() != 0) {
//				cout << '-' << a << '\n';
//
//				sum -= stoi(a);
//				oper = ' ';
//				a.clear();
//			}
//		}
//		startIndex = fIndex + 1;
//	}
//	
//	cout << "숫자들의 합은 " << sum << '\n';
//}
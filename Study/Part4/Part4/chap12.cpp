//#define _CRT_SECURE_NO_WARNINGS

//#include <iostream>
//using namespace std;
//
//class String {
//private:
//	char* str;
//public:
//	String(const char* str) {
//		this->str = new char[strlen(str) + 1];
//		strcpy(this->str, str);
//	}
//	String(const String& ref) {
//		str = new char[strlen(ref.str) + 1];
//		strcpy(str, ref.str);
//	}
//	String& operator=(const String& ref) {
//		delete[]str;
//		str = new char[strlen(ref.str) + 1];
//		strcpy(str, ref.str);
//		return *this;
//	}
//	String& operator+(const String& ref){
//		int len = strlen(str) + strlen(ref.str);
//		str = new char[len + 1]; // 이미 메모리가 할당되어있고 초기화 되어있는 str을 new char 로 메모리를 재할당한다면 내부에서는 무슨 일이 일어날까..? 나중에 더 공부하고 알게 된다면 이 코드가 맞는 코드인지 생각해보자.
//		for (int i = 0; i < strlen(ref.str); i++) {
//			str[strlen(str) + 1 + i] = ref.str[i];
//		}
//		//위는 내가 짠 코드. 이를 strcat을 이용하여 다시 구성해보자
//		//strcat(str, ref.str);
//		//이거 한 문장이면 기존의 str의 '종결 NULL문자를 시작점으로' 하여 문자열이 덧붙여지기 시작.
//		return *this;
//	}
//	void operator+=(const String& ref) {
//		int len = strlen(str) + strlen(ref.str);	
//		str = new char[len + 1]; // 이미 메모리가 할당되어있고 초기화 되어있는 str을 new char 로 메모리를 재할당한다면 내부에서는 무슨 일이 일어날까..? 나중에 더 공부하고 알게 된다면 이 코드가 맞는 코드인지 생각해보자.
//		for (int i = 0; i < strlen(ref.str); i++) {
//			str[strlen(str) + 1 + i] = ref.str[i];
//		}
//		//위는 내가 짠 코드. 이를 strcat을 이용하여 다시 구성해보자
//		//strcat(str, ref.str);
//		//이거 한 문장이면 기존의 str의 '종결 NULL문자를 시작점으로' 하여 문자열이 덧붙여지기 시작.
//	}
//	bool operator==(const String& ref) {
//		for (int i = 0; i < strlen(str); i++) {
//			if (str[i] != ref.str[i]) return false;
//		}
//		return true;
//		//위는 내가 짠 코드. 이를 strcmp를 이용하여 다시 구성해보자
//		//return strcmp(str, ref.str) ? false : true;
//		//이 한 문장이면 비교가 완료된다.
//	}
//	/*friend ostream& operator<<(ostream& cout, const String& ref);
//	friend istream& operator>>(istream& cin, const String& ref);*/
//	~String() {
//		delete[]str;
//	}
//};
//
////ostream& operator<<(ostream& cout, const String& ref) {
////	for (int i = 0; i < strlen(ref.str); i++) {
////		cout << ref.str[i];
////	}
////	return cout;
////}
////
////istream& operator>>(istream& cin, const String& ref) {
////	for (int i = 0; i < strlen(ref.str); i++) {
////		cin >> ref.str[i];
////	}
////	return cin;
////}
//// c++ 내에서 이미 cout cin 에 대해 오버로딩이 되어있기 때문에 내가 쓴 이 코드가 올바른지 검사해볼 길이 없다...나중에 더 공부하고 알게 된다면 마찬가지로 다시 검토해보자.
//
////교재에 나와있는 코드
///*
//ostream& operator<< (ostream& cout, String& ref){
//	cout << ref.str;
//	return cout;
//}
//
//istream& operator>> (istream& cin, String& ref){
//	char str[100];
//	cin >> str;
//	ref = String(str);
//	return cin;
//*/
//
//int main() {
//	string str1 = "I like ";
//	string str2 = "string class";
//	string str3 = str1 + str2;
//
//	cout << str1 << '\n';
//	cout << str2 << '\n';
//	cout << str3 << '\n';
//
//	str1 += str2;
//	if (str1 == str3) cout << "동일한 문자열" << '\n';
//	else cout << "동일하지 않은 문자열" << '\n';
//
//	string str4;
//	cout << "문자열 입력: ";
//	cin >> str4;
//	cout << "입력한 문자열: " << str4 << '\n';
//
//	return 0;
//}
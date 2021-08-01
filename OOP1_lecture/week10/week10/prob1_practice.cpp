#include <iostream>
using namespace std;

int main() {
	char str1[5] = "1234",
		str2[5] = "5678",
		str3[10] = "";
	int lenStr1 = strlen(str1),
		lenStr2 = strlen(str2);

	for (int i = 0; i < lenStr1; i++) str3[i] = str1[i];
	for (int i = 0; i < lenStr2; i++) str3[lenStr1 + i] = str2[i];

	cout << "\nstr1 = ";
	for (int i = 0; i < strlen(str1); i++) cout << str1[i];
	cout << "\nstr2 = ";
	for (int i = 0; i < strlen(str2); i++) cout << str2[i];
	cout << "\nstr3 = ";
	for (int i = 0; i < strlen(str1) + strlen(str2); i++) cout << str3[i];
}
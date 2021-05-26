#include <iostream>
using namespace std;

int main() {
	char string1[20];
	char string2[] = "string literal";

	cout << "Enter the string \"hello there\" : ";
	cin >> string1;

	cout << "string1 is : " << string1 << "\nstring2 is : " << string2;

	cout << "\nstring1 with spaces between characters is : \n";

	for (int i = 0; string1[i] != '\0'; i++) cout << string1[i] << " ";

	cin >> string1;
	cout << "\nstring1 is : " << string1 << '\n';
}
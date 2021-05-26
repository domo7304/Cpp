#include <iostream>
#include <cstring>
using namespace std;

int main() {
	string str = "This is a long string.";
	cout << "str before chage : " << str << '\n';

	str[str.find("s")] = 'S';
	cout << "str after first change : " << str << '\n';

	str[str.find("s")] = 'S';
	cout << "str agfter second change : " << str << '\n';
}
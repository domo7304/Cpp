#include <iostream>
using namespace std;

int main() {
	int integerValue = 1000;
	double doubleValue = 0.0947628;

	cout << "The value of the flags variable is " << cout.flags()
		<< "\nPrint int and double in original format:\n"
		<< integerValue << '\t' << doubleValue;

	ios_base::fmtflags originalFormat = cout.flags();
	cout << showbase << oct << scientific;

	cout << "\n\nThe value of the flags variable is: " << cout.flags()
		<< "\nPrint int and double in a new format:\n"
		<< integerValue << '\t' << doubleValue;

	cout.flags(originalFormat);

	cout << "\n\nThe restored value of the flags variable is: "
		<< cout.flags() << "\nPrint values in original format again:\n"
		<< integerValue << '\t' << doubleValue << endl;
}
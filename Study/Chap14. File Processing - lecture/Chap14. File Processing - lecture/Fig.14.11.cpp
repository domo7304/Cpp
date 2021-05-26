//#include <iostream>
//#include <fstream>
//#include <cstdlib>
//#include "ClientData.h"
//using namespace std;
//
//int main() {
//	fstream outCredit("credit.dat", ios::in | ios::out | ios::binary);
//
//	if (!outCredit) {
//		cerr << "File could not be opened." << endl;
//		exit(EXIT_FAILURE);
//	}
//
//	cout << "Enter account number (1 to 100, 0 to end input)\n? ";
//
//	int accountNumber;
//	string lastName;
//	string firstName;
//	double balance;
//
//	cin >> accountNumber;
//
//	while (accountNumber > 0 && accountNumber <= 100) {
//		cout << "Enter lastname, firstname and balance\n? ";
//		cin >> lastName;
//		cin >> firstName;
//		cin >> balance;
//
//		ClientData client{ accountNumber, lastName, firstName, balance };
//
//		outCredit.seekp(
//			(client.getAccountNumber() - 1) * sizeof(ClientData));
//
//		outCredit.write(
//			reinterpret_cast<const char*>(&client), sizeof(ClientData));
//
//		cout << "Enter acocunt number\n? ";
//		cin >> accountNumber;
//	}
//}
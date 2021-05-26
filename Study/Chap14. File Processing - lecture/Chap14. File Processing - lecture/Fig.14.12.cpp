//#include <iostream>
//#include <iomanip>
//#include <fstream>
//#include <cstdlib>
//#include "ClientData.h"
//using namespace std;
//
//void outputLine(ostream&, const ClientData&);
//
//int main() {
//	ifstream inCredit("credit.dat", ios::in | ios::binary);
//
//	if (!inCredit) {
//		cerr << "File could not be opened." << endl;
//		exit(EXIT_FAILURE);
//	}
//
//	cout << left << setw(10) << "Account" << setw(16) << "Last Name"
//		<< setw(11) << "First Name" << setw(10) << right << "Balance\n";
//
//	ClientData client;
//
//	inCredit.read(reinterpret_cast <char*> (&client), sizeof(ClientData));
//
//	while (inCredit) {
//		if (client.getAccountNumber() != 0) {
//			outputLine(cout, client);
//		}
//
//		inCredit.read(reinterpret_cast<char*> (&client), sizeof(ClientData));
//	}
//}
//
//void outputLine(ostream& output, const ClientData& record) {
//	output << left << setw(10) << record.getAccountNumber()
//		<< setw(16) << record.getLastName()
//		<< setw(11) << record.getFirstName()
//		<< setw(10) << setprecision(2) << right << fixed
//		<< showpoint << record.getBalance() << endl;
//}
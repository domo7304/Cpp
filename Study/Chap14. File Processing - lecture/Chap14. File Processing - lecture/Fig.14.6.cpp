//#include <iostream>
//#include <fstream>
//#include <iomanip>
//#include <string>
//#include <cstdlib>
//using namespace std;
//
//enum class RequestType {
//	ZERO_BALANCE = 1, CREDIT_BALANCE, DEBIT_BALANCE, END};
//RequestType getRequest();
//
//bool shouldDisplay(RequestType, double);
//void outputLine(int, const string&, double);
//
//int main() {
//	ifstream inClientFile("clients.txt", ios::in);
//
//	if (!inClientFile) {
//		cerr << "File could not be opened" << endl;
//		exit(EXIT_FAILURE);
//	}
//
//	RequestType request = getRequest();
//
//	while (request != RequestType::END) {
//		switch (request) {
//		case RequestType::ZERO_BALANCE:
//			cout << "\nAccounts with zero balances:\n";
//			break;
//		case RequestType::CREDIT_BALANCE:
//			cout << "\nAccounts with credit balances:\n";
//			break;
//		case RequestType::DEBIT_BALANCE:
//			cout << "\nAccounts with debit balances:\n";
//			break;
//		}
//
//		int account;
//		string name;
//		double balance;
//
//		inClientFile >> account >> name >> balance;
//
//		while (!inClientFile.eof()) {
//			if (shouldDisplay(request, balance))
//				outputLine(account, name, balance);
//
//			inClientFile >> account >> name >> balance;
//		}
//
//		inClientFile.clear();
//		inClientFile.seekg(0);
//		request = getRequest();
//	}
//	cout << "End of run." << endl;
//}
//
//RequestType getRequest() {
//	cout << "\nEnter request\n"
//		<< " 1 - List accounts with zero balances\n"
//		<< " 2 - List accounts with credit balances\n"
//		<< " 3 - List accounts with debit balances\n"
//		<< " 4 - End of run" << fixed << showpoint;
//	int type;
//
//	do {
//		cout << "\n?";
//		cin >> type;
//	} while (type < static_cast<int>(RequestType::ZERO_BALANCE) || 
//		type > static_cast<int>(RequestType::END));
//
//	return static_cast<RequestType>(type);
//}
//
//// if문과 활용하여 조건에 만족하는지 안하는지 편하게 true/false 를 반환해주도록 만든 함수
//bool shouldDisplay(RequestType type, double balance) {
//	if (type == RequestType::ZERO_BALANCE && balance == 0) return true;
//
//	if (type == RequestType::CREDIT_BALANCE && balance < 0) return true;
//
//	if (type == RequestType::DEBIT_BALANCE && balance > 0) return true;
//
//	return false;
//}
//
//// 출력 포맷 지정
//void outputLine(int account, const string& name, double balance) {
//	cout << left << setw(10) << account << setw(13) << name
//		<< setw(7) << setprecision(2) << right << balance << endl;
//}
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include "ClientData.h"
using namespace std;

enum class Choice {
	PRINT = 1, UPDATE, NEW, DELETE, END
};

Choice enterChoice();
void createTextFile(fstream&);
void updateRecord(fstream&);
void newRecord(fstream&);
void deleteRecord(fstream&);
void outputLine(ostream&, const ClientData&);
int getAccount(const char* const);

int main() {
	fstream inOutCredit("credit.dat", ios::in | ios::out | ios::binary);

	if (!inOutCredit) {
		cerr << "File could not be opened." << endl;
		exit(EXIT_FAILURE);
	}

	Choice choice;

	while ((choice = enterChoice()) != Choice::END) { // 선택지 입력을 enterChoice 함수에서 받게함
		switch (choice) {
		case Choice::PRINT:
			createTextFile(inOutCredit);
			break;
		case Choice::UPDATE:
			updateRecord(inOutCredit);
			break;
		case Choice::NEW:
			newRecord(inOutCredit);
			break;
		case Choice::DELETE:
			deleteRecord(inOutCredit);
			break;
		default:
			cerr << "Incorrect choice" << endl;
			break;
		}

		inOutCredit.clear();
	}
}

// 사용자 선택지를 출력 및 정수입력으로 선택한 값을 Choice 객체로 형변환하여 반환
Choice enterChoice() {
	cout << "\nEnter your choice\n"
		<< "1 - store a formatted text file of accounts\n"
		<< "    called \"print.txt\" for printing\n"
		<< "2 - update an account \n"
		<< "3 - add a new account \n"
		<< "4 - delete an account \n"
		<< "5 - end program\n?";

	int menuChoice;
	cin >> menuChoice;
	return static_cast<Choice> (menuChoice);
}

// 파일 포인터가 eof 에 도달하기 전까지 파일을 읽은 후 이를 다른 txt파일에 기록하여 저장
void createTextFile(fstream& readFromFile) {
	ofstream outPrintFile("Print.txt", ios::out);

	if (!outPrintFile) {
		cerr << "File could not be created." << endl;
		exit(EXIT_FAILURE);
	}

	outPrintFile << left << setw(10) << "Account" << setw(16)
		<< "Last Name" << setw(11) << "First Name" << right
		<< setw(10) << "Balance" << endl;

	// 파일포인터를 0으로 위치
	readFromFile.seekg(0);

	// eof를 만날 때까지 파일을 읽으며 readFromFile에서 읽어온 레코드를 client에 계속 복사
	ClientData client;
	readFromFile.read(reinterpret_cast <char*> (&client), sizeof(ClientData));

	while (!readFromFile.eof()) {
		// 복사한 객체의 계정번호가 0이 아니면 outputLine 함수를 통해 정보를 출력
		if (client.getAccountNumber() != 0) outputLine(outPrintFile, client);

		// 다음꺼 읽어오기
		readFromFile.read(reinterpret_cast<char*> (&client), sizeof(ClientData));
	}
}

// 레코드에 있는 잔액 (balance)를 업데이트
void updateRecord(fstream& updateFile) {
	int accountNumber = getAccount("Enter account to update");

	// getAccount를 통해 계좌번호를 입력받고, 해당 레코드로 랜덤액세스 진행
	updateFile.seekg((accountNumber - 1) * sizeof(ClientData));

	// 비어있는 client 객체 생성 후 updateFile 레코드의 값을 읽어와서 복사 진행
	ClientData client;
	updateFile.read(reinterpret_cast<char*> (&client), sizeof(ClientData));

	// 레코드 업데이트 진행
	if (client.getAccountNumber() != 0) {
		outputLine(cout, client); // 현재 정보 출력

		cout << "\nEnter charge (+) or payment (-): ";
		double transaction;
		cin >> transaction;

		// 현재 잔액을 oldBalance 변수에 저장 후 setBalance를 통해 + 혹은 - 헤줌 그 후 출력
		double oldBalance = client.getBalance();
		client.setBalance(oldBalance + transaction);
		outputLine(cout, client);

		updateFile.seekp((accountNumber - 1) * sizeof(ClientData));

		updateFile.write(reinterpret_cast <const char*> (&client), sizeof(ClientData));
	}
	else {
		cerr << "Account #" << accountNumber << " has no information." << endl;
	}
}

void newRecord(fstream& insertInFile) {
	int accountNumber = getAccount("Enter new account number");

	insertInFile.seekg((accountNumber - 1) * sizeof(ClientData));

	ClientData client;
	insertInFile.read(reinterpret_cast <char*> (&client), sizeof(ClientData));

	if (client.getAccountNumber() == 0) {
		string lastName;
		string firstName;
		double balance;

		cout << "Enter lastname, firstname, balance\n? ";
		cin >> setw(15) >> lastName;
		cin >> setw(10) >> firstName;
		cin >> balance;

		client.setLastName(lastName);
		client.setFirstName(firstName);
		client.setBalance(balance);
		client.setAccountNumber(accountNumber);

		// 입력스트림이므로 seekp! 해당 계정번호위치로 이동하여 write 진행
		insertInFile.seekp((accountNumber - 1) * sizeof(ClientData));

		insertInFile.write(reinterpret_cast<const char*> (&client), sizeof(ClientData));
	}
	else { // 계정번호가 0이 아니라면 이미 있는 정보이므로 에러 출력
		cerr << "Account #" << accountNumber << " already contains information." << endl;
	}
}

void deleteRecord(fstream& deleteFromFile) {
	int accountNumber = getAccount("Enter account to delete");

	deleteFromFile.seekg((accountNumber - 1) * sizeof(ClientData));

	ClientData client;
	deleteFromFile.read(reinterpret_cast <char*>(&client), sizeof(ClientData));

	if (client.getAccountNumber() != 0) {
		ClientData blankClient;

		// 해당 계정번호 위치로 이동한 후 비어있는 ClientData 객체를 덮어씌워줌으로써
		// 기존의 정보를 삭제하는 방식
		deleteFromFile.seekp((accountNumber - 1) * sizeof(ClientData));
		deleteFromFile.write(reinterpret_cast<const char*>(&blankClient), sizeof(ClientData));

		cout << "Account #" << accountNumber << " deleted.\n";
	}
	else { // 계정정보가 0이라면 없는 계정이므로 에러 출력
		cerr << "Account #" << accountNumber << " is empty.\n";
	}
}

// 레코드 출력 포맷
void outputLine(ostream& output, const ClientData& record) {
	output << left << setw(5) << record.getAccountNumber()
		<< setw(7) << record.getLastName()
		<< setw(7) << record.getFirstName()
		<< setw(7) << setprecision(2) << right << fixed
		<< showpoint << record.getBalance() << endl;
}

// 인자로 전달받은 문자열을 출력 후 accountNumber를 입력받아 조건에 맞으면 반환
int getAccount(const char* const prompt) {
	int accountNumber;
	do {
		cout << prompt << " (1 - 100): ";
		cin >> accountNumber;
	} while (accountNumber < 1 || accountNumber > 100);

	return accountNumber;
}
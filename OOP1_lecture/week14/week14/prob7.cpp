//#include <iostream>
//using namespace std;
//
//class BankAccount {
//private:
//	int bounce;
//public:
//	void setBounce(int bounce) { this->bounce = bounce; }
//	int getBounce() { return bounce; }
//
//	void deposit(int money) {
//		bounce += money;
//	}
//	void withdraw(int money) {
//		bounce -+money;
//	}
//};
//
//int main() {
//	BankAccount b;
//	b.setBounce(1000000);
//
//	cout << "ÇöÀç ÀÜ¾× : " << b.getBounce() << '\n';
//	b.deposit(1000000);
//	cout << "after deposit(1000000) ÇöÀç ÀÜ¾× : " << b.getBounce() << '\n';
//	b.withdraw(1000000);
//	cout << "after withdraw(1000000) ÇöÀç ÀÜ¾× : " << b.getBounce() << '\n';
//}
//#include <iostream>
//#include <cmath>
//using namespace std;
//
//bool isPrime(int);
//
//int main() {
//	int num;
//	cout << "������ ������ �Է��ϼ��� : ";
//	cin >> num;
//
//	for (int i = 1; i <= num; i++) {
//		if (isPrime(i)) cout << i << " ";
//	}
//	cout << '\n';
//}
//
//bool isPrime(int num) {
//	if (num == 1) return false;
//	else if (num == 2) return true;
//	else if (num % 2 == 0) return false;
//
//	for (int i = 3; i < sqrt(num); i++) {
//		if (num % i == 0) return false;
//	}
//	return true;
//}
#include <iostream>
using namespace std;

int reverse(int);

int main() {
	int num;
	cout << "������ ������ �Է��ϼ��� : ";
	cin >> num;
	
	cout << num << "�� �Ųٷ� ����ϸ� " << reverse(num) << "�Դϴ�." << '\n';
}

int reverse(int num) {
	int reverseNum = 0;
	while (num > 0) {
		reverseNum *= 10;
		reverseNum += (num % 10);
		num /= 10;
	}
	return reverseNum;
}
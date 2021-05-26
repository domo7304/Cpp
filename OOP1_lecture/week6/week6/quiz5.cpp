#include <iostream>
using namespace std;

int reverse(int);

int main() {
	int num;
	cout << "임의의 정수를 입력하세요 : ";
	cin >> num;
	
	cout << num << "를 거꾸로 출력하면 " << reverse(num) << "입니다." << '\n';
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
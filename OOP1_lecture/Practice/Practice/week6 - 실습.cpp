//#include <iostream>
//#include <cmath>
//using namespace std;
//
//bool isPrime(int);
//
//int main() {
//	int num;
//	cout << "Input a number : ";
//	cin >> num;
//
//	for (int i = 1; i <= num; i++) {
//		if (isPrime(i)) cout << i << " ";
//	}
//}
//
//bool isPrime(int n) {
//	if (n == 1) return false;
//	else if (n == 2) return true;
//	else if (n % 2 == 0) return false;
//
//	for (int i = 3; i <= sqrt(n); i++) {
//		if (n % i == 0) return false;
//	}
//	return true;
//}

//#include <iostream>
//using namespace std;
//
//int sumOfSquare(int, int);
//static int result = 0;
//
//int main() {
//	int mean = 2;
//
//	for (int i = 2; i < 10; i++) {
//		cout << "Sum of squares in x = " << i << " : " << sumOfSquare(i, mean) << '\n';
//	}
//}
//
//int sumOfSquare(int n, int mean) {
//	result += (n - mean) * (n - mean);
//	return result;
//}

//#include <iostream>
//using namespace std;
//
//int sumOfSquare(int, int);
//static int result = 0;
//
//int main() {
//	srand((unsigned)time(NULL));
//	int mean;
//	cout << "Input your mean : ";
//	cin >> mean;
//
//	for (int i = 2; i < 10; i++) {
//		int rand_num = rand() % 101;
//		cout << "Sum of squares in x = " << rand_num << " : " << sumOfSquare(rand_num, mean) << '\n';
//	}
//}
//
//int sumOfSquare(int n, int mean) {
//	result += (n - mean) * (n - mean);
//	return result;
//}

//#include <iostream>
//using namespace std;
//
//int main() {
//	int n, binary = 0;
//	cout << "Input decimal num : ";
//	cin >> n;
//
//	for (int i = 1; n > 0; i *= 10) {
//		binary += (n % 2) * i;
//		n /= 2;
//	}
//	cout << "to bainary : " << binary << '\n';
//}

//#include <iostream>
//using namespace std;
//
//int main() {
//	int num, reverse_num = 0;
//	cout << "임의의 정수를 입력하세요 : ";
//	cin >> num;
//	cout << num << "을(를) 거꾸로 출력하면 ";
//
//	while (num > 0) {
//		reverse_num *= 10;
//		reverse_num += (num % 10);
//		num /= 10;
//	}
//	cout << reverse_num << "입니다. \n";
//}
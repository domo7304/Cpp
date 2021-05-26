//#include <iostream>
//using namespace std;
//
//int main() {
//	int num;
//	cin >> num;
//
//	for (int i = 0; i < num; i++) {
//		for (int j = (num - i - 1); j > 0; j--) cout << " ";
//		for (int j = 1; j <= (2 * i + 1); j++) cout << "*";
//		cout << '\n';
//	}
//
//	for (int i = 1; i < num; i++) {
//		for (int j = 1; j <= i; j++) cout << " ";
//		for (int j = 2 * (num - i - 1) + 1; j > 0; j--) cout << "*";
//		cout << '\n';
//	}
//}

//#include <iostream>
//using namespace std;
//
//int main() {
//	int num, result = 1;
//	cout << "Please enter an integer : ";
//	cin >> num;
//
//	for (int i = num; i > 0; i--) {
//		result *= i;
//	}
//	cout << num << "! = " << result << '\n';
//}

//#include <iostream>
//#include <iomanip>
//using namespace std;
//
//int main() {
//	int N, M;
//	cout << "Input N, M : ";
//	cin >> N >> M;
//
//	for (int i = 0; i <= (N / M); i++) {
//		for (int k = 1; k <= N; k++){
//			for (int j = (i * M) + 1; j <= ((i * M) + M) && j <= N; j++)
//				cout << j << " x " << k << " = " << setw(2) << j * k << setw(5);
//			cout << '\n';
//		}
//		cout << '\n';
//	}
//}

//#include <iostream>
//#include <iomanip>
//using namespace std;
//
//int main() {
//	int N, M, cnt = 0;
//	cin >> N >> M;
//
//	for (int i = 1; i <= 100; i++) {
//		if (i % N == 0 || i % M == 0) {
//			cout << setw(3) << i << setw(2);
//			cnt++;
//			if (cnt !=0 && cnt % 5 == 0) cout << '\n';
//		}
//	}
//	cout << "\ntotal : " << cnt << '\n';
//}

//#include <iostream>
//using namespace std;
//
//int main() {
//	char ch;
//	int cnt1 = 0, cnt2 = 0;
//
//	while ((ch = cin.get()) != EOF) {
//		if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
//			ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') cnt1++;
//		else cnt2++;
//		cin.ignore();
//	}
//	cout << "모음 : " << cnt1 << ", 자음 : " << cnt2 << '\n';
//}
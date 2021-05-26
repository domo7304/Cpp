//#include <iostream>
//using namespace std;
//
//int main() {
//	int num;
//	cout << "Please enter number n : ";
//	cin >> num;
//
//	for (int i = 0; i < num; i++) {
//		for (int j = 0; j <= i; j++) cout << (j + 1) << " ";
//		cout << "\n";
//	}
//}

//#include <iostream>
//using namespace std;
//
//int main() {
//	int num;
//	cout << "Please enter number n : ";
//	cin >> num;
//
//	for (int i = 0; i < num; i++) {
//		for (int j = num; j > i; j--) cout << j << " ";
//		cout << '\n';
//	}
//}

//#include <iostream>
//using namespace std;
//
//int main() {
//	int num;
//	cout << "Please enter number n : ";
//	cin >> num;
//
//	for (int i = 0; i < num; i++) {
//		for (int j = 0; j < (num - i - 1); j++) cout << "  ";
//		for (int j = (i + 1); j > 0; j--) cout << j << " ";
//		cout << '\n';
//	}
//}

//#include <iostream>
//using namespace std;
//
//int main() {
//	int num;
//	cout << "Please enter number n : ";
//	cin >> num;
//
//	for (int i = 0; i < num; i++) {
//		for (int j = 0; j < (num - i - 1); j++) cout << "  ";
//		for (int j = (i + 1); j > 0; j--) cout << j << " ";
//		for (int j = 2; j <= (i + 1); j++) cout << j << " ";
//		cout << '\n';
//	}
//}

//#include <iostream>
//using namespace std;
//
//int main() {
//	int num, changed_num= 0;
//	cout << "Please enter number n : ";
//	cin >> num;
//
//	changed_num += (num % 10) * 10;
//	changed_num += num / 10;
//
//	cout << "When changed position the result is : " << changed_num << '\n';
//}
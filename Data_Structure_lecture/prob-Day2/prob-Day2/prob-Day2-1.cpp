//#include <iostream>
//#include <string>
//using namespace std;
//
//class Array {
//public:
//	int n;
//	int* arr;
//
//	Array(int size) {
//		this->n = 0;
//		this->arr = new int[size];
//		for (int i = 0; i < size; i++) {
//			arr[i] = 0;
//		}
//	}
//
//	int at(int idx) {
//		if (arr[idx] == 0) return 0;
//		else return arr[idx];
//	}
//
//	void set(int idx, int X) {
//		if (arr[idx] != 0) {
//			arr[idx] = X;
//		}
//		else {
//			cout << 0 << endl;
//		}
//	}
//
//	void add(int idx, int num) {
//		if (arr[idx] == 0) {
//			while (idx > 0 && (arr[idx - 1] == 0)) idx--;
//			arr[idx] = num;
//		}
//		else {
//			int cnt = 0;
//			while (arr[cnt] != 0) cnt++;
//
//			for (int j = (cnt - 1); j >= idx; j--) arr[j + 1] = arr[j];
//			
//			arr[idx] = num;
//		}
//	}
//};
//
//int main() {
//	Array arr(10000);
//
//	string str1 = "at", str2 = "add", str3 = "set";
//	int M;
//	cin >> M;
//
//	for (int i = 0; i < M; i++) {
//
//		int idx = 0, num = 0;
//		string str;
//		cin >> str;
//
//		if (str == str1) {
//			cin >> idx;
//			cout << arr.at(idx) << endl;
//		}
//		else if (str == str2) {
//			cin >> idx >> num;
//			arr.add(idx, num);
//		}
//		else if (str == str3) {
//			cin >> idx >> num;
//			arr.set(idx, num);
//		}
//	}
//	return 0;
//}
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
//		n = 0;
//		arr = new int[size];
//		for (int i = 0; i < size; i++) arr[i] = 0;
//	}
//
//	int at(int idx) {
//		if (arr[idx] == 0) return 0;
//
//		return arr[idx];
//	}
//
//	void set(int idx, int X) {
//		if (arr[idx] == 0) cout << 0 << endl;
//		else {
//			arr[idx] = X;
//		}
//	}
//
//	void add(int idx, int X) {
//		if (arr[idx] == 0) {
//			arr[n] = X;
//			n = n + 1;
//		}
//		else {
//			for (int i = n; i > idx; i--) arr[i] = arr[i - 1];
//			arr[idx] = X;
//			n = n + 1;
//		}
//	}
//
//	int remove(int idx) {
//		if (arr[idx] == 0) return 0;
//
//		int tmp = arr[idx];
//		for (int i = idx; i < n; i++) arr[i] = arr[i + 1];
//		n = n - 1;
//		return tmp;
//	}
//
//	void printArray() {
//		if (arr[0] == 0) cout << 0 << endl;
//		else {
//			for (int i = 0; i < n; i++) cout << arr[i] << " ";
//			cout << endl;
//		}
//	}
//};
//
//int main() {
//	string str1 = "at", str2 = "set", str3 = "add", str4 = "remove", str5 = "printArray";
//	Array arr(10000);
//	int N;
//	cin >> N;
//
//	for (int i = 0; i < N; i++) {
//		string str;
//		cin >> str;
//
//		int idx = 0, num = 0;
//		if (str == str1) {
//			cin >> idx;
//			cout << arr.at(idx) << endl;
//		}
//		else if (str == str2) {
//			cin >> idx >> num;
//			arr.set(idx, num);
//		}
//		else if (str == str3) {
//			cin >> idx >> num;
//			arr.add(idx, num);
//		}
//		else if (str == str4) {
//			cin >> idx;
//			cout << arr.remove(idx) << endl;
//		}
//		else if (str == str5) {
//			arr.printArray();
//		}
//	}
//	return 0;
//}
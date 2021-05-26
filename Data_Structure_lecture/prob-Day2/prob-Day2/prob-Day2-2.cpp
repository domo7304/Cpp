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
//		return arr[idx];
//	}
//
//	void set(int idx, int num) {
//		if (arr[idx] == 0) cout << 0 << endl;
//		else {
//			arr[idx] = num;
//		}
//	}
//
//	void add(int idx, int num) {
//		if (arr[idx] == 0) {
//			arr[n] = num;
//			n++;
//		}
//		else {
//			for (int i = n; i > idx; i--) arr[i] = arr[i - 1];
//			arr[idx] = num;
//			n++;
//		}
//	}
//
//	int remove(int idx) {
//		if (arr[idx] == 0) return 0;
//		
//		int tmp = arr[idx];
//		for (int i = idx; i < n; i++) arr[i] = arr[i + 1];
//		n--;
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
//
//	int N;
//	cin >> N;
//
//	for (int i = 0; i < N; i++) {
//		string str;
//		cin >> str;
//
//		if (str == str1) {
//			int idx;
//			cin >> idx;
//			cout << arr.at(idx) << endl;
//		}
//		else if (str == str2) {
//			int idx, num;
//			cin >> idx >> num;
//			arr.set(idx, num);
//		}
//		else if (str == str3) {
//			int idx, num;
//			cin >> idx >> num;
//			arr.add(idx, num);
//		}
//		else if (str == str4) {
//			int idx;
//			cin >> idx;
//			cout << arr.remove(idx) << endl;
//		}
//		else if (str == str5) {
//			arr.printArray();
//		}
//	}
//	return 0;
//}
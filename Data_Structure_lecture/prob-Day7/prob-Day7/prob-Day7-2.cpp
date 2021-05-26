//////#include <iostream>
//////#include <string>
//////#include <vector>
//////using namespace std;
//////
//////class Heap {
//////private:
//////	vector <int> v;
//////	int size;
//////public:
//////	Heap() {
//////		v.push_back(-1);
//////		size = 0;
//////	}
//////
//////	void insert(int e) {
//////		if (size == 0) {
//////			v.push_back(e);
//////			size++;
//////		}
//////		else {
//////			v.push_back(e);
//////			size++;
//////
//////			int i = size;
//////			while (i > 1 && v[i] < v[i / 2]) {
//////				swap(v[i], v[i / 2]);
//////				i = i / 2;
//////			}
//////		}
//////	}
//////
//////	int pop() {
//////		if (size == 0) return -1;
//////
//////		int tmp = v[1];
//////		swap(v[1], v[size]);
//////		v.erase(v.begin() + size);
//////		size--;
//////
//////		int i = 1;
//////		while (2 * i <= size) {
//////			int left = 2 * i, right = 2 * i + 1;
//////
//////			if (right <= size) {
//////				if (v[left] <= v[right] && v[left] < v[i]) {
//////					swap(v[left], v[i]);
//////					i = 2 * i;
//////				}
//////				else if (v[right] < v[left] && v[right] < v[i]) {
//////					swap(v[right], v[i]);
//////					i = 2 * i + 1;
//////				}
//////				else return tmp;
//////			}
//////			else if (left <= size && v[left] < v[i]){
//////				swap(v[left], v[i]);
//////				i = 2 * i;
//////			}
//////			else return tmp;
//////		}
//////		return tmp;
//////	}
//////
//////	int h_size() {
//////		return size;
//////	}
//////
//////	int isEmpty() {
//////		if (size == 0) return 1;
//////		return 0;
//////	}
//////
//////	int top() {
//////		if (size == 0) return -1;
//////		return v[1];
//////	}
//////
//////	void print() {
//////		if (size == 0) cout << -1 << endl;
//////		else {
//////			for (int i = 1; i <= size; i++) {
//////				cout << v[i] << " ";
//////			}
//////			cout << endl;
//////		}
//////	}
//////};
//////
//////int main() {
//////	string str1 = "insert", str2 = "size", str3 = "isEmpty", str4 = "pop", str5 = "top", str6 = "print";
//////	Heap h;
//////
//////	int N;
//////	cin >> N;
//////
//////	for (int i = 0; i < N; i++) {
//////		string str;
//////		cin >> str;
//////
//////		if (str == str1) {
//////			int e;
//////			cin >> e;
//////			h.insert(e);
//////		}
//////		else if (str == str2) cout << h.h_size() << endl;
//////		else if (str == str3) cout << h.isEmpty() << endl;
//////		else if (str == str4) cout << h.pop() << endl;
//////		else if (str == str5) cout << h.top() << endl;
//////		else if (str == str6) h.print();
//////	}
//////	return 0;
//////}
////
////
////#include <iostream>
////#include <vector>
////#include <string>
////using namespace std;
////
////class Heap {
////private:
////	vector <int> v;
////	int size;
////public:
////	Heap() {
////		v.push_back(-1);
////		size = 0;
////	}
////
////	void insert(int e) {
////		if (size == 0) {
////			v.push_back(e);
////			size++;
////		}
////		else {
////			v.push_back(e);
////			size++;
////
////			int i = size;
////			while (i > 1 && v[i] < v[i / 2]) {
////				swap(v[i], v[i / 2]);
////				i = i / 2;
////			}
////		}
////	}
////
////	int pop() {
////		if (size == 0) return -1;
////
////		int tmp = v[1];
////		swap(v[1], v[size]);
////		v.erase(v.begin() + size);
////		size--;
////
////		int i = 1;
////		while (2 * i <= size) {
////			int left = 2 * i, right = 2 * i + 1;
////
////			if (right <= size) {
////				if (v[left] <= v[right] && v[left] < v[i]) {
////					swap(v[left], v[i]);
////					i = 2 * i;
////				}
////				else if (v[right] < v[left] && v[right] < v[i]) {
////					swap(v[right], v[i]);
////					i = 2 * i + 1;
////				}
////				else return tmp;
////			}
////			else if (left <= size && v[left] < v[i]) {
////				swap(v[left], v[i]);
////				i = 2 * i;
////			}
////			else return tmp;
////		}
////		return tmp;
////	}
////
////	int heap_size() {
////		return size;
////	}
////
////	int isEmpty() {
////		if (size == 0) return 1;
////		return 0;
////	}
////
////	int top() {
////		if (size == 0) return -1;
////		return v[1];
////	}
////
////	void print() {
////		if (size == 0) cout << -1 << endl;
////		else {
////			for (int i = 1; i <= size; i++) cout << v[i] << " ";
////			cout << endl;
////		}
////	}
////};
////
////int main() {
////	string str1 = "insert", str2 = "size", str3 = "isEmpty", str4 = "pop", str5 = "top", str6 = "print";
////	Heap h;
////	int N;
////	cin >> N;
////
////	for (int i = 0; i < N; i++) {
////		string str;
////		cin >> str;
////		if (str == str1) {
////			int e;
////			cin >> e;
////			h.insert(e);
////		}
////		else if (str == str2) cout << h.heap_size() << endl;
////		else if (str == str3) cout << h.isEmpty() << endl;
////		else if (str == str4) cout << h.pop() << endl;
////		else if (str == str5) cout << h.top() << endl;
////		else if (str == str6) h.print();
////	}
////	return 0;
////}
//
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//
//class Heap {
//public:
//	int size;
//	vector <int> v;
//
//	Heap() {
//		size = 0;
//		v.push_back(-1);
//	}
//
//	void insert(int e) {
//		if (size == 0) {
//			v.push_back(e);
//			size++;
//		}
//		else {
//			v.push_back(e);
//			size++;
//
//			int i = size;
//			while (i > 1 && v[i] < v[i / 2]) {
//				swap(v[i], v[i / 2]);
//				i = i / 2;
//			}
//		}
//	}
//
//	int pop() {
//		if (size == 0) return -1;
//		
//		int tmp = v[1];
//		swap(v[1], v[size]);
//		v.erase(v.begin() + size);
//		size--;
//
//		int i = 1;
//		while (2 * i <= size) {
//			int left = 2 * i, right = 2 * i + 1;
//
//			if (right <= size) {
//				if (v[left] <= v[right] && v[left] < v[i]) {
//					swap(v[left], v[i]);
//					i = 2 * i;
//				}
//				else if (v[right] < v[left] && v[right] < v[i]) {
//					swap(v[right], v[i]);
//					i = 2 * i + 1;
//				}
//				else return tmp;
//			}
//			else if (left <= size && v[left] < v[i]) {
//				swap(v[left], v[i]);
//				i = 2 * i;
//			}
//			else return tmp;
//		}
//		return tmp;
//	}
//
//	int heap_size() {
//		return size;
//	}
//
//	int isEmpty() {
//		if (size == 0) return 1;
//		return 0;
//	}
//
//	int top() {
//		if (size == 0) return -1;
//		return v[1];
//	}
//
//	void print() {
//		if (size == 0) cout << -1 << endl;
//		else {
//			for (int i = 1; i <= size; i++) 
//				cout << v[i] << " ";
//			cout << endl;
//		}
//	}
//};
//
//int main() {
//	string str1 = "insert", str2 = "size", str3 = "isEmpty", str4 = "pop", str5 = "top", str6 = "print";
//	int N;
//	cin >> N;
//
//	Heap h;
//	for (int i = 0; i < N; i++){
//		string str;
//		cin >> str;
//		
//		if (str == str1) {
//			int e;
//			cin >> e;
//			h.insert(e);
//		}
//		else if (str == str2) cout << h.heap_size() << endl;
//		else if (str == str3) cout << h.isEmpty() << endl;
//		else if (str == str4) cout << h.pop() << endl;
//		else if (str == str5) cout << h.top() << endl;
//		else if (str == str6) h.print();
//	}
//	return 0;
//}
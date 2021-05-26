////#include <iostream>
////#include <vector>
////using namespace std;
////
////class Heap {
////private:
////	vector <int> v;
////	int size;
////	int dir;
////public:
////	Heap(int direction) {
////		v.push_back(-1);
////		size = 0;
////		this->dir = direction;
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
////			while (i > 1 && (v[i] * dir) < (v[i / 2] * dir)) {
////				swap(v[i], v[i / 2]);
////				i = i / 2;
////			}
////		}
////	}
////
////	int pop() {
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
////				if (v[left] * dir <= v[right] * dir && v[left] * dir < v[i] * dir) {
////					swap(v[left], v[i]);
////					i = 2 * i;
////				}
////				else if (v[right] * dir < v[left] * dir && v[right] * dir < v[i] * dir) {
////					swap(v[right], v[i]);
////					i = 2 * i + 1;
////				}
////				else return tmp;
////			}
////			else if (left <= size && v[left] * dir < v[i] * dir) {
////				swap(v[left], v[i]);
////				i = 2 * i;
////			}
////			else return tmp;
////		}
////		return tmp;
////	}
////
////	void getVector(int idx) {
////		cout << v[idx] << endl;
////	}
////};
////
////int main() {
////	int T;
////	cin >> T;
////
////	for (int i = 0; i < T; i++) {
////		Heap h1(1), h2(-1);
////		int N, p;
////		cin >> N >> p;
////
////		for (int i = 0; i < N; i++) {
////			int e;
////			cin >> e;
////			h1.insert(e);
////			h2.insert(e);
////		}
////
////		h1.getVector(p);
////		for (int i = 0; i < (p - 1); i++) h1.pop();
////		cout << h1.pop() << endl;
////
////		h2.getVector(p);
////		for (int i = 0; i < (p - 1); i++) h2.pop();
////		cout << h2.pop() << endl;
////	}
////	return 0;
////}
//
//#include <iostream>
//#include <vector>
//using namespace std;
//
//class Heap {
//private:
//	vector <int> v;
//	int size;
//	int dir;
//public:
//	Heap(int direction) {
//		v.push_back(-1);
//		size = 0;
//		dir = direction;
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
//			while (i > 1 && v[i] * dir < v[i / 2] * dir) {
//				swap(v[i], v[i / 2]);
//				i = i / 2;
//			}
//		}
//	}
//
//	int pop() {
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
//				if (v[left] * dir <= v[right] * dir && v[left] * dir < v[i] * dir) {
//					swap(v[left], v[i]);
//					i = 2 * i;
//				}
//				else if (v[right] * dir < v[left] * dir && v[right] * dir < v[i] * dir) {
//					swap(v[right], v[i]);
//					i = 2 * i + 1;
//				}
//				else return tmp;
//			}
//			else if (left <= size && v[left] * dir < v[i] * dir) {
//				swap(v[left], v[i]);
//				i = 2 * i;
//			}
//			else return tmp;
//		}
//		return tmp;
//	}
//
//	int getVector(int idx) {
//		return v[idx];
//	}
//};
//
//int main() {
//	int T;
//	cin >> T;
//
//	for (int i = 0; i < T; i++) {
//		Heap h1(1), h2(-1);
//		int N, p;
//		cin >> N >> p;
//
//		for (int j = 0; j < N; j++) {
//			int e;
//			cin >> e;
//			h1.insert(e);
//			h2.insert(e);
//		}
//
//		cout << h1.getVector(p) << endl;
//		for (int j = 0; j < (p - 1); j++) h1.pop();
//		cout << h1.pop() << endl;
//
//		cout << h2.getVector(p) << endl;
//		for (int j = 0; j < (p - 1); j++) h2.pop();
//		cout << h2.pop() << endl;
//	}
//}


#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Heap {
public:
	int size;
	vector <int> v;

	Heap() {
		size = 0;
		v.push_back(-1);
	}

	void insert(int e) {
		if (size == 0) {
			v.push_back(e);
			size++;
		}
		else {
			v.push_back(e);
			size++;

			int i = size;
			while (i > 1 && v[i] < v[i / 2]) {
				swap(v[i], v[i / 2]);
				i = i / 2;
			}
		}
	}

	int pop() {
		if (size == 0) return -1;

		int tmp = v[1];
		swap(v[1], v[size]);
		v.erase(v.begin() + size);
		size--;

		int i = 1;
		while (2 * i <= size) {
			int left = 2 * i, right = 2 * i + 1;

			if (right <= size) {
				if (v[left] <= v[right] && v[left] < v[i]) {
					swap(v[left], v[i]);
					i = 2 * i;
				}
				else if (v[right] < v[left] && v[right] < v[i]) {
					swap(v[right], v[i]);
					i = 2 * i + 1;
				}
				else return tmp;
			}
			else if (left <= size && v[left] < v[i]) {
				swap(v[left], v[i]);
				i = 2 * i;
			}
			else return tmp;
		}
		return tmp;
	}

	int heap_size() {
		return size;
	}

	int isEmpty() {
		if (size == 0) return 1;
		return 0;
	}

	int top() {
		if (size == 0) return -1;
		return v[1];
	}

	void print() {
		if (size == 0) cout << -1 << endl;
		else {
			for (int i = 1; i <= size; i++)
				cout << v[i] << " ";
			cout << endl;
		}
	}
};

int main() {
	string str1 = "insert", str2 = "size", str3 = "isEmpty", str4 = "pop", str5 = "top", str6 = "print";
	int N;
	cin >> N;

	Heap h;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;

		if (str == str1) {
			int e;
			cin >> e;
			h.insert(e);
		}
		else if (str == str2) cout << h.heap_size() << endl;
		else if (str == str3) cout << h.isEmpty() << endl;
		else if (str == str4) cout << h.pop() << endl;
		else if (str == str5) cout << h.top() << endl;
		else if (str == str6) h.print();
	}
	return 0;
}
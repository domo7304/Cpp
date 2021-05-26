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
//		this->dir = direction;
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
//			while (i > 1 && (v[i] * dir) < (v[i / 2] * dir)) {
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
//	void getVector(int idx) {
//		cout << v[idx] << endl;
//	}
//};
//
//int main() {
//	int T;
//	cin >> T;
//
//	for (int i = 0; i < T; i++) {
//		Heap h(1);
//		int N, p;
//		cin >> N >> p;
//
//		for (int i = 0; i < N; i++) {
//			int e;
//			cin >> e;
//			h.insert(e);
//		}
//
//		h.getVector(p);
//		for (int i = 0; i < (p - 1); i++) h.pop();
//		cout << h.pop() << endl;
//	}
//	return 0;
//}
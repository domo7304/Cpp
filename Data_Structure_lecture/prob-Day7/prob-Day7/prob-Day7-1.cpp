//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//
//class Heap {
//private:
//	vector <int> v;
//	int heap_size;
//public:
//	Heap() {
//		v.push_back(-1);
//		heap_size = 0;
//	}
//
//	void insert(int e) {
//		if (heap_size == 0) {
//			v.push_back(e);
//			heap_size++;
//		}
//		else {
//			v.push_back(e);
//			heap_size++;
//
//			int i = heap_size;
//			while (i > 1 && v[i] < v[i / 2]) {
//				swap(v[i], v[i / 2]);
//				i = i / 2;
//			}
//		}
//	}
//
//	int pop() {
//		if (heap_size == 0) return -1;
//
//		int tmp = v[1];
//		v[1] = v[heap_size];
//		v.erase(v.begin() + heap_size);
//		heap_size--;
//
//		int par = 1;
//		while (1) {
//			int left = 2 * par, right = 2 * par + 1;
//
//			if (right <= heap_size) { // �� �� ���� ��
//				if (v[left] <= v[right]) // ������ �����ʺ��� �� �۰ų� ����
//					if (v[left] < v[par]) {
//						swap(v[left], v[par]); // ������ par ���� ������ swap
//						par = par * 2;
//					}
//					else return tmp; // par�� ���ʺ��� �۰ų� ������ �׳� ������
//				else if (v[left] > v[right]) // �������� ���ʺ��� �� �۰ų� ����
//					if (v[right] < v[par]) {
//						swap(v[right], v[par]); // �������� par ���� ������ swap
//						par = par * 2 + 1;
//					}
//					else return tmp; // par �� �����ʺ��� �۰ų� ������ �׳� ������
//			}
//			else if (left <= heap_size) { // ���ʸ� ���� ��
//				if (v[left] < v[par]) { 
//					swap(v[left], v[par]); // ������ par ���� ������ swap
//					par = par * 2;
//				}
//				else return tmp;
//			}
//			else return tmp;
//		}
//	}
//
//	int top() {
//		if (heap_size == 0) return -1;
//		return v[1];
//	}
//
//	int size() {
//		return heap_size;
//	}
//
//	bool isEmpty() {
//		if (heap_size == 0) return 1;
//		return 0;
//	}
//
//	void print() {
//		if (heap_size == 0) cout << -1 << endl;
//		else {
//			for (int i = 1; i <= heap_size; i++) {
//				cout << v[i] << " ";
//			}
//			cout << endl;
//		}
//	}
//};
//
//int main() {
//	string str1 = "insert", str2 = "size", str3 = "isEmpty", str4 = "pop", str5 = "top", str6 = "print";
//	Heap H;
//
//	int N;
//	cin >> N;
//
//	for (int i = 0; i < N; i++) {
//		string str;
//		cin >> str;
//
//		if (str == str1) {
//			int e;
//			cin >> e;
//			H.insert(e);
//		}
//		else if (str == str2) cout << H.size() << endl;
//		else if (str == str3) cout << H.isEmpty() << endl;
//		else if (str == str4) cout << H.pop() << endl;
//		else if (str == str5) cout << H.top() << endl;
//		else if (str == str6) H.print();
//	}
//	return 0;
//}
//#include <iostream>
//using namespace std;
//
//
//int hashfunc(int idx) {
//	return idx % 353333;
//}
//
//class item {
//public:
//	int key;
//	bool flag_val;
//	bool flag_deleted;
//
//	item() {
//		key = -1;
//		flag_val = false;
//		flag_deleted = false;
//	}
//};
//
//class arr {
//public:
//	int size;
//	int capacity;
//	item* data;
//
//	arr(int capacity) {
//		size = 0;
//		this->capacity = capacity;
//		data = new item[capacity];
//	}
//
//	void erase(int e) {
//		int hash_value = hashfunc(e);
//		int prob = 1;
//
//		while (data[hash_value].key != -1 || data[hash_value].flag_deleted == true) {
//			if (data[hash_value].key == e) {
//				cout << 1 << " " << prob << endl;
//				data[hash_value].key = -1;
//				data[hash_value].flag_deleted = true;
//				data[hash_value].flag_val = false;
//				return;
//			} 
//			else {
//				hash_value = (hash_value + 1) % 353333;
//				prob++;
//			}
//		}
//		cout << 0 << " " << prob << endl;
//		return;
//	}
//
//	~arr() {
//		delete[]data;
//	}
//};
//
//int main() {
//	int T;
//	cin >> T;
//
//	for (int i = 0; i < T; i++) {
//		arr HashArr(353333);
//		int N;
//		cin >> N;
//
//		for (int j = 0; j < N; j++) {
//			int e;
//			cin >> e;
//			int hash_value = hashfunc(e);
//
//			while (1) {
//				if (HashArr.data[hash_value].flag_val == false) {
//					HashArr.data[hash_value].key = e;
//					HashArr.data[hash_value].flag_val = true;
//					HashArr.size++;
//					break;
//				}
//				else hash_value++;
//			}
//		}
//
//		int M;
//		cin >> M;
//		for (int j = 0; j < M; j++) {
//			int e;
//			cin >> e;
//			HashArr.erase(e);
//		}
//	}
//	return 0;
//}
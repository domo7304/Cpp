#include <iostream>
using namespace std;

int hashfunc(int idx) {
	return idx % 353333;
}

int hashfunc2(int idx) {
	return (17 - (idx % 17));
}

class item {
public:
	int key;
	bool flag;

	item() {
		key = -1;
		flag = false;
	}

	item(int key) {
		this->key = key;
		flag = false;
	}
};

class arr {
public:
	item* data;

	arr(int size) {
		data = new item[size];
	}

	~arr() {
		delete[]data;
	}

	void find(int e) {
		int prob = 1;
		int hash_value = hashfunc(e);
		int hash_value2 = hashfunc2(e);

		while (data[hash_value].key != -1) {
			if (data[hash_value].key == e) {
				cout << 1 << " " << prob << endl;
				return;
			}
			else {
				prob++;
				hash_value += hash_value2;
			}
		}
		cout << 0 << " " << prob << endl;
	}
};

int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		arr hash(353333);
		int N;
		cin >> N;

		for (int j = 0; j < N; j++) {
			int e;
			cin >> e;

			int hash_value = hashfunc(e);
			int hash_value2 = hashfunc2(e);

			while (1) {
				if (hash.data[hash_value].flag == false) {
					hash.data[hash_value].key = e;
					hash.data[hash_value].flag = true;
					break;
				}
				else hash_value += hash_value2;
			}
		}

		int M;
		cin >> M;

		for (int j = 0; j < M; j++) {
			int e;
			cin >> e;
			hash.find(e);
		}
	}
	return 0;
}
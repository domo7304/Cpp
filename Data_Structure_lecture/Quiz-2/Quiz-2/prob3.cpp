#include <iostream>
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

	void insertNode(int e) {
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
		int tmp = v[1];
		swap(v[1], v[size]);
		v.erase(v.begin() + size);
		size--;

		int i = 1;
		while (2 * i < size) {
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
			else if (left < size && v[left] < v[i]) {
				swap(v[left], v[i]);
				i = 2 * i;
			}
			else return tmp;
		}
		return tmp;
	}

	int getVector(int idx) {
		return v[idx];
	}
};

int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int N, p;
		cin >> N >> p;

		Heap h;
		for (int j = 0; j < N; j++) {
			int e;
			cin >> e;
			h.insertNode(e);
		}

		cout << h.getVector(p) << endl;
		for (int j = 0; j < (p - 1); j++) h.pop();
		cout << h.pop() << endl;
	}
	return 0;
}
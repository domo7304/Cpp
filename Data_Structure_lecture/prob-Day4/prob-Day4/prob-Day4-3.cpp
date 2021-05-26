//#include <iostream>
//#include <string>
//using namespace std;
//
//class arrayStack {
//public:
//	int* S;
//	int capacity;
//	int t;
//
//	arrayStack(int capacity) {
//		this->capacity = capacity;
//		S = new int[capacity];
//		t = -1;
//	}
//
//	void push(int e) {
//		t = t + 1;
//		S[t] = e;
//	}
//
//	int pop() {
//		if (t == -1) return -1;
//		
//		t = t - 1;
//		return S[t + 1];
//	}
//};
//
//int main() {
//	int N;
//	cin >> N;
//
//	for (int i = 0; i < N; i++) {
//		arrayStack s(100);
//
//		string str;
//		cin >> str;
//
//		for (int j = 0; j < str.length(); j++) {
//			if (str[j] == '+') {
//				int x = s.pop(), y = s.pop();
//				s.push(x + y);
//			}
//			else if (str[j] == '-') {
//				int x = s.pop(), y = s.pop();
//				s.push(y - x);
//			}
//			else if (str[j] == '*') {
//				int x = s.pop(), y = s.pop();
//				s.push(x * y);
//			}
//			else {
//				s.push(str[j] - '0');
//			}
//		}
//		cout << s.pop() << endl;
//	}
//	return 0;
//}



#include <iostream>
#include <string>
using namespace std;

class Arraystack {
public:
	int t;
	int* S;

	Arraystack(int size) {
		t = -1;
		S = new int[size];
	}

	void push(int X) {
		t = t + 1;
			S[t] = X;
	}

	int pop() {
		if (t == -1) return -1;

		int tmp = S[t];
		t = t - 1;
		return tmp;
	}
};


int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		Arraystack S(20000);
		string str;
		cin >> str;

		for (int j = 0; j < str.length(); j++) {
			if (str[j] == '+') {
				int x = S.pop(), y = S.pop();
				S.push(x + y);
			}
			else if (str[j] == '-') {
				int x = S.pop(), y = S.pop();
				S.push(y - x);
			}
			else if (str[j] == '*') {
				int x = S.pop(), y = S.pop();
				S.push(x * y);
			}
			else S.push(str[j] - '0');
		}
		cout << S.pop() << endl;
	}
	return 0;
}
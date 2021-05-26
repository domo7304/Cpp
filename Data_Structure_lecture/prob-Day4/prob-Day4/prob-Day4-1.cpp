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
//		this->S = new int[capacity];
//		this->t = -1;
//	}
//
//	int empty() {
//		if (t == -1) return 1;
//		return 0;
//	}
//
//	int top() {
//		if (t == -1) return -1;
//		return S[t];
//	}
//
//	void push(int e) {
//		t = t + 1;
//		S[t] = e;
//	}
//};
//
//int main() {
//	arrayStack s(20000);
//	string str1 = "empty", str2 = "top", str3 = "push";
//
//	int N;
//	cin >> N;
//
//	for (int i = 0; i < N; i++) {
//		string str;
//		cin >> str;
//
//		if (str == str1) cout << s.empty() << endl;
//		else if (str == str2) cout << s.top() << endl;
//		else if (str == str3) {
//			int num;
//			cin >> num;
//			s.push(num);
//		}
//	}
//	return 0;
//}
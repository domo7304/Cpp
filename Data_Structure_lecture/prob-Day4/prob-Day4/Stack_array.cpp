//#include <iostream>
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
//	int size() {
//		return (t + 1);
//	}
//	bool empty() {
//		return (t == -1);
//	}
//	int top() {
//		if (t == -1) return -1;
//		else return S[t];
//	}
//	void push(int e) {
//		t = t + 1;
//		S[t] = e;
//	}
//	int pop() {
//		if (t == -1) return -1;
//		t = t - 1;
//		return S[t + 1];
//	}
//};
//
//int main() {
//	string str1 = "empty", str2 = "top", str3 = "push", str4 = "pop", str5 = "size";
//	arrayStack s(10000);
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
//		else if (str == str4) cout << s.pop() << endl;
//		else if (str == str5) cout << s.size() << endl;
//	}
//	return 0;
//}
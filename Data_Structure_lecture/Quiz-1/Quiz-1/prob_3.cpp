//#include <iostream>
//#include <string>
//using namespace std;
//
//class Arraystack {
//public:
//	int t;
//	int* S;
//
//	Arraystack(int size) {
//		t = -1;
//		S = new int[size];
//	}
//
//	void push(int e) {
//		t = t + 1;
//		S[t] = e;
//	}
//
//	int pop(){
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
//		Arraystack S(10000);
//		string str;
//		cin >> str;
//
//		for (int j = 0; j < str.length(); j++) {
//			if (str[j] == '+'){
//				int x = S.pop(), y = S.pop();
//				S.push(x + y);
//			}
//			else if (str[j] == '-') {
//				int x = S.pop(), y = S.pop();
//				S.push(y - x);
//			}
//			else if (str[j] == '*') {
//				int x = S.pop(), y = S.pop();
//				S.push(x * y);
//			}
//			else S.push(str[j] - '0');
//		}
//		cout << S.pop() << endl;
//	}
//	return 0;
//}
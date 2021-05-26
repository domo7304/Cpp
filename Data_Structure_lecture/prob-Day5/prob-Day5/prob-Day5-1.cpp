//#include <iostream>
//#include <string>
//using namespace std;
//
//class arrQueue {
//public:
//	int* Q;
//	int capacity;
//	int f;
//	int r;
//	int n;
//
//	arrQueue(int size);
//	void enqueue(int data);
//	int size();
//	int isEmpty();
//};
//
//arrQueue::arrQueue(int size) {
//	Q = new int[size];
//	capacity = size;
//	f = 0;
//	r = 0;
//	n = 0;
//}
//
//void arrQueue::enqueue(int data) {
//  if (n == capacity) cout << "Full" << endl;
//	else {
//		Q[r] = data;
//		r = r + 1;
//		n = n + 1;
//	}
//}
//
//int arrQueue::size() {
//	return n;
//}
//
//int arrQueue::isEmpty() {
//	if (n == 0) return 1;
//	return 0;
//}
//
//arrQueue::~arrQueue() {
//delete[]Q;
//}
//
//int main() {
//	string str1 = "enqueue", str2 = "size", str3 = "isEmpty";
//	int S, N;
//	cin >> S >> N;
//
//	arrQueue Q(S);
//	for (int i = 0; i < N; i++) {
//		string str;
//		cin >> str;
//
//		if (str == str1) {
//			int num;
//			cin >> num;
//			Q.enqueue(num);
//		}
//		else if (str == str2) cout << Q.size() << endl;
//		else if (str == str3) cout << Q.isEmpty() << endl;
//	}
//	return 0;
//}
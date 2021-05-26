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
//
//	arrQueue(int size);
//	void enqueue(int data);
//	int dequeue();
//	int front();
//	~arrQueue();
//};
//
//arrQueue::arrQueue(int size) {
//	Q = new int[size];
//	capacity = size;
//	f = 0;
//	r = -1;
//}
//
//void arrQueue::enqueue(int data) {
//	r = (r + 1) % capacity;
//	Q[r] = data;
//}
//
//int arrQueue::dequeue() {
//	int tmp = Q[f];
//	f = (f + 1) % capacity;
//	return tmp;
//}
//
//int arrQueue::front() {
//	return Q[f];
//}
//
//arrQueue::~arrQueue() {
//	delete[]Q;
//}
//
//int main() {
//	int T;
//	cin >> T;
//
//	for (int i = 0; i < T; i++) {
//		int size;
//		cin >> size;
//		arrQueue Q1(size), Q2(size);
//
//		for (int j = 0; j < size; j++) {
//			int num;
//			cin >> num;
//			Q1.enqueue(num);
//		}
//
//		for (int j = 0; j < size; j++) {
//			int num;
//			cin >> num;
//			Q2.enqueue(num);
//		}
//
//		int score_q1 = 0, score_q2 = 0;
//		for (int j = 0; j < size; j++) {
//			if (Q1.front() > Q2.front()) {
//				Q1.dequeue();
//				Q2.dequeue();
//				score_q1++;
//			}
//			else if (Q1.front() < Q2.front()) {
//				Q1.dequeue();
//				Q2.dequeue();
//				score_q2++;
//			}
//			else {
//				Q1.dequeue();
//				Q2.dequeue();
//			}
//		}
//		if (score_q1 > score_q2) cout << 1 << endl;
//		else if (score_q1 < score_q2) cout << 2 << endl;
//		else cout << 0 << endl;
//	}
//	return 0;
//}
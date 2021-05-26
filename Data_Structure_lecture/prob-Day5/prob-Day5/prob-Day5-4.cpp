////#include <iostream>
////#include <string>
////using namespace std;
////
////class arrQueue {
////public:
////	int* Q;
////	int capacity;
////	int f;
////	int r;
////
////	arrQueue(int size);
////	void enqueue(int data);
////	int dequeue();
////	int front();
////	~arrQueue();
////};
////
////arrQueue::arrQueue(int size) {
////	Q = new int[size];
////	capacity = size;
////	f = 0;
////	r = -1;
////}
////
////void arrQueue::enqueue(int data) {
////	r = (r + 1) % capacity;
////	Q[r] = data;
////}
////
////int arrQueue::dequeue() {
////	int tmp = Q[f];
////	f = (f + 1) % capacity;
////	return tmp;
////}
////
////int arrQueue::front() {
////	return Q[f];
////}
////
////arrQueue::~arrQueue() {
////	delete[]Q;
////}
////
////int main() {
////	int T;
////	cin >> T;
////
////	for (int i = 0; i < T; i++) {
////		int N;
////		cin >> N;
////		arrQueue Q1(N), Q2(N);
////
////		for (int j = 0; j < N; j++) {
////			int n;
////			cin >> n;
////			Q1.enqueue(n);
////		}
////
////		for (int j = 0; j < N; j++) {
////			int n;
////			cin >> n;
////			Q2.enqueue(n);
////		}
////		
////		int tmp_q1 = 0, tmp_q2 = 0;
////		int score_q1 = 0, score_q2 = 0;
////		for (int j = 0; j < N; j++) {
////			if ((Q1.front() + tmp_q1) > (Q2.front() + tmp_q2)) {
////				tmp_q1 = (Q1.dequeue() + tmp_q1) - (Q2.dequeue() + tmp_q2) - 1;
////				tmp_q2 = 0;
////				score_q1++;
////			}
////			else if ((Q1.front() + tmp_q1) < (Q2.front() + tmp_q2)) {
////				tmp_q2 = (Q2.dequeue() + tmp_q2) - (Q1.dequeue() + tmp_q1) - 1;
////				tmp_q1 = 0;
////				score_q2++;
////			}
////			else {
////				Q1.dequeue();
////				Q2.dequeue();
////				tmp_q1 = tmp_q2 = 0;
////			}
////		}
////		if (score_q1 > score_q2) cout << 1 << endl;
////		else if (score_q1 < score_q2) cout << 2 << endl;
////		else cout << 0 << endl;
////	}
////	return 0;
////}
//
//
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
//	arrQueue(int size) {
//		Q = new int[size];
//		capacity = size;
//		f = 0;
//		r = -1;
//	}
//
//	void enqueue(int data) {
//		r = (r + 1) % capacity;
//		Q[r] = data;
//	}
//
//	int dequeue() {
//		int tmp = Q[f];
//		f = (f + 1) % capacity;
//		return tmp;
//	}
//
//	int front() {
//		return Q[f];
//	}
//
//	~arrQueue() {
//		delete[]Q;
//	}
//};
//
//int main() {
//	int T;
//	cin >> T;
//
//	for (int i = 0; i < T; i++) {
//		int N;
//		cin >> N;
//
//		arrQueue q1(N), q2(N);
//		for (int j = 0; j < N; j++) {
//			int e;
//			cin >> e;
//			q1.enqueue(e);
//		}
//
//		for (int j = 0; j < N; j++) {
//			int e;
//			cin >> e;
//			q2.enqueue(e);
//		}
//
//		int tmp_q1 = 0, tmp_q2 = 0;
//		int score_q1 = 0, score_q2 = 0;
//		for (int j = 0; j < N; j++) {
//			if ((q1.front() + tmp_q1) > (q2.front() + tmp_q2)) {
//				tmp_q1 = (q1.dequeue() + tmp_q1) - (q2.dequeue() + tmp_q2) - 1;
//				tmp_q2 = 0;
//				score_q1++;
//			}
//			else if ((q1.front() + tmp_q1) < (q2.front() + tmp_q2)) {
//				tmp_q2 = (q2.dequeue() + tmp_q2) - (q1.dequeue() + tmp_q1) - 1;
//				tmp_q1 = 0;
//				score_q2++;
//			}
//			else {
//				q1.dequeue();
//				q2.dequeue();
//				tmp_q1 = tmp_q2 = 0;
//			}
//		}
//		if (score_q1 > score_q2) cout << 1 << endl;
//		else if (score_q1 < score_q2) cout << 2 << endl;
//		else cout << 0 << endl;
//	}
//	return 0;
//}
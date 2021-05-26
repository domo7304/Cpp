//#include <iostream>
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
//	arrQueue(int size) {
//		Q = new int[size];
//		capacity = size;
//		f = 0;
//		r = -1;
//		n = 0;
//	}
//
//	void enqueue(int e) {
//		r = (r + 1) % capacity;
//		n = n + 1;
//		Q[r] = e;
//	}
//
//	int dequeue() {
//		int tmp = Q[f];
//		f = (f + 1) % capacity;
//		n = n - 1;
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
//		arrQueue q1(N), q2(N);
//
//		for (int j = 0; j < N; j++) {
//			int e;
//			cin >> e;
//			q1.enqueue(e);
//		}
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
//			else if ((q2.front() + tmp_q2) > (q1.front() + tmp_q1)) {
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
//		else if (score_q2 > score_q1) cout << 2 << endl;
//		else cout << 0 << endl;
//	}
//	return 0;
//}
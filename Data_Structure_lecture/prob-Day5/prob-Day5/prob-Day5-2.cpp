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
//	void dequeue();
//	int size();
//	int isEmpty();
//	void front();
//	void rear();
//	~arrQueue();
//};
//
//arrQueue::arrQueue(int size) {
//	Q = new int[size];
//	capacity = size;
//	f = 0;
//	r = -1;
//	n = 0;
//}
//
//void arrQueue::enqueue(int data) {
//	if (n == capacity) cout << "Full" << endl;
//	else {
//		r = (r + 1) % capacity;
//		n = n + 1;
//		Q[r] = data;
//	}
//}
//
//void arrQueue::dequeue() {
//	if (n == 0) cout << "Empty" << endl;
//	else {
//		int tmp = Q[f];
//		f = (f + 1) % capacity;
//		n = n - 1;
//		cout << tmp << endl;
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
//void arrQueue::front() {
//	if (n == 0) cout << "Empty" << endl;
//	else cout << Q[f] << endl;
//}
//
//void arrQueue::rear() {
//	if (n == 0) cout << "Empty" << endl;
//	else cout << Q[r] << endl;
//}
//
//arrQueue::~arrQueue() {
//	delete[]Q;
//}
//
//int main() {
//	string str1 = "enqueue", str2 = "dequeue", str3 = "size", str4 = "isEmpty", str5 = "front", str6 = "rear";
//	int S, N;
//	cin >> S >> N;
//
//	arrQueue q(S)
//	for (int i = 0; i < N; i++) {
//		string str;
//		cin >> str;
//
//		if (str == str1) {
//			int num;
//			cin >> num;
//			q.enqueue(num);
//		}
//		else if (str == str2) q.dequeue();
//		else if (str == str3) cout << q.size() << endl;
//		else if (str == str4) cout << q.isEmpty() << endl;
//		else if (str == str5) q.front();
//		else if (str == str6) q.rear();
//	}
//	return 0;
//}
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
//	void enqueue(int X) {
//		if (n == capacity) cout << "Full" << endl;
//		else {
//			r = (r + 1) % capacity;
//			Q[r] = X;
//			n = n + 1;
// 		}
//	}
//
//	void dequeue() {
//		if (n == 0) cout << "Empty" << endl;
//		else {
//			int tmp = Q[f];
//			f = (f + 1) % capacity;
//			n = n - 1;
//			cout << tmp << endl;
//		}
//	}
//
//	int size() {
//		return n;
//	}
//
//	int isEmpty() {
//		if (n == 0) return 1;
//		return 0;
//	}
//
//	void front() {
//		if (n == 0) cout << "Empty" << endl;
//		else cout << Q[f] << endl;
//	}
//
//	void rear() {
//		if (n == 0) cout << "Empty" << endl;
//		else cout << Q[r] << endl;
//	}
//};
//
//int main() {
//	string str1 = "enqueue", str2 = "dequeue", str3 = "size", str4 = "isEmpty", str5 = "front", str6 = "rear";
//	int S, N;
//	cin >> S >> N;
//
//	arrQueue q(S);
//	for (int i = 0; i < N; i++) {
//		string str;
//		cin >> str;
//
//		if (str == str1) {
//			int X;
//			cin >> X;
//			q.enqueue(X);
//		}
//		else if (str == str2) q.dequeue();
//		else if (str == str3) cout << q.size() << endl;
//		else if (str == str4) cout << q.isEmpty() << endl;
//		else if (str == str5) q.front();
//		else if (str == str6) q.rear();
//	}
//	return 0;
//}
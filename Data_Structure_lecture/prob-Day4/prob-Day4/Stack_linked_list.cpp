//#include <iostream>
//using namespace std;
//
//class Node {
//public:
//	int data;
//	Node* next;
//
//	Node(int e) {
//		data = e;
//		next = NULL;
//	}
//};
//
//class SLinkedList {
//public:
//	Node* head;
//
//	SLinkedList() {
//		head = NULL;
//	}
//
//	void addFront(int X) {
//		Node* v = new Node(X);
//		if (head == NULL) head = v;
//		else {
//			v->next = head;
//			head = v;
//		}
//	}
//	int removeFront() {
//		if (head == NULL) return -1;
//
//		int tmp = head->data;
//		head = head->next;
//		return tmp;
//	}
//	int front() {
//		return head->data;
//	}
//};
//
//class linkedStack {
//public:
//	int n;
//	SLinkedList* S;
//
//	linkedStack() {
//		this->S = new SLinkedList();
//		this->n = 0;
//	}
//	int size() {
//		return n;
//	}
//	bool empty() {
//		return !n;
//	}
//	int top() {
//		if (n == 0) return -1;
//		return S->front();
//	}
//	void push(int e) {
//		S->addFront(e);
//		n++;
//	}
//	int pop() {
//		if (n == 0) return -1;
//
//		n--;
//		return S->removeFront();
//	}
//};
//
//int main() {
//	string str1 = "empty", str2 = "top", str3 = "push", str4 = "pop", str5 = "size";
//	linkedStack s;
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
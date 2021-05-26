//#include <iostream>
//#include <string>
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
//
//	int removeFront() {
//		if (head == NULL) return -1;
//		else {
//			int tmp = head->data;
//			head = head->next;
//			return tmp;
//		}
//	}
//
//	int front() {
//		if (head == NULL) return -1;
//		else return head->data;
//	}
//
//	int empty() {
//		if (head == NULL) return 1;
//		else return 0;
//	}
//};
//
//int main() {
//	SLinkedList list;
//	string str1 = "addFront", str2 = "removeFront", str3 = "front", str4 = "empty";
//
//	int N;
//	cin >> N;
//
//	for (int i = 0; i < N; i++) {
//		string str;
//		cin >> str;
//
//		if (str == str1) {
//			int num;
//			cin >> num;
//			list.addFront(num);
//		}
//		else if (str == str2) cout << list.removeFront() << endl;
//		else if (str == str3) cout << list.front() << endl;
//		else if (str == str4) cout << list.empty() << endl;
//	}
//	return 0;
//}


//#include <iostream>
//#include <string>
//using namespace std;
//
//class Node {
//public:
//	int data;
//	Node* next;
//
//	Node(int e) {
//		this->data = e;
//		this->next = NULL;
//	}
//};
//
//class SLinkedList {
//public:
//	Node* head;
//	Node* tail;
//
//	SLinkedList() {
//		head = NULL;
//		tail = NULL;
//	}
//
//	void addFront(int X) {
//		Node* v = new Node(X);
//		if (empty()) {
//			tail = v;
//		}
//		v->next = head;
//		head = v;
//	}
//
//	int removeFront() {
//		if (empty()) return -1;
//		else {
//			int tmp = head->data;
//			head = head->next;
//			return tmp;
//		}
//	}
//
//	int front() {
//		if (empty()) return -1;
//		else return head->data;
//	}
//
//	int empty() {
//		if (head == NULL) return 1;
//		else return 0;
//	}
//};
//
//int main() {
//	string str1 = "addFront", str2 = "removeFront", str3 = "front", str4 = "empty";
//	SLinkedList list;
//
//	int N;
//	cin >> N;
//
//	for (int i = 0; i < N; i++) {
//		string str;
//		cin >> str;
//
//		if (str == str1) {
//			int num;
//			cin >> num;
//			list.addFront(num);
//		}
//		else if (str == str2) cout << list.removeFront() << endl;
//		else if (str == str3) cout << list.front() << endl;
//		else if (str == str4) cout << list.empty() << endl;
//	}
//	return 0;
//}
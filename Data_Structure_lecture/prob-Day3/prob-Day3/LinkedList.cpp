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
//
//	void showList() {
//		if (empty()) cout << -1 << endl;
//		else {
//			Node* cur = head;
//
//			while (cur->next != NULL) {
//				cout << cur->data << " ";
//				cur = cur->next;
//			}
//			cout << cur->data << endl;
//		}
//	}
//
//	void addBack(int X) {
//		Node* v = new Node(X);
//		if (empty()) {
//			head = tail = v;
//		}
//		else {
//			tail->next = v;
//			tail = v;
//		}
//	}
//
//	int removeBack() {
//		if (empty()) return -1;
//		else {
//			Node* cur = head;
//
//			if (cur == tail) {
//				int tmp = cur->data;
//				head = tail = NULL;
//				return tmp;
//			}
//
//			while (cur->next != tail) cur = cur->next;
//			int tmp = tail->data;
//			tail = cur;
//			tail->next = NULL;
//			return tmp;
//		}
//	}
//};
//
//int main() {
//	string str1 = "addFront", str2 = "removeFront", str3 = "front", str4 = "empty", str5 = "showList",
//		str6 = "addBack", str7 = "removeBack";
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
//		else if (str == str5) list.showList();
//		else if (str == str6) {
//			int num;
//			cin >> num;
//			list.addBack(num);
//		}
//		else if (str == str7) cout << list.removeBack() << endl;
//	}
//	return 0;
//}
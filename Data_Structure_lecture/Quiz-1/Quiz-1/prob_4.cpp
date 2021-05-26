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
//class CLinkedlist {
//public:
//	Node* head;
//	Node* tail;
//
//	CLinkedlist() {
//		head = NULL;
//		tail = NULL;
//	}
//
//	void addBack(int e) {
//		Node* v = new Node(e);
//		if (head == NULL) head = tail = v;
//		else {
//			tail->next = v;
//			tail = v;
//			tail->next = head;
//		}
//	}
//
//	void Delete(int idx) {
//		if (idx == 0) {
//			head = head->next;
//			tail->next = head;
//		}
//		else {
//			Node* cur = head;
//			for (int i = 0; i < (idx - 1); i++) cur = cur->next;
//
//			if (cur->next == head) {
//				head = head->next;
//				tail->next = head;
//			}
//			else if (cur->next == tail) {
//				tail = cur;
//				tail->next = head;
//			}
//			else {
//				Node* curNext = cur->next;
//				cur->next = curNext->next;
//			}
//		}
//	}
//
//	void showList() {
//		Node* cur = head;
//
//		while (cur->next != head) {
//			cout << cur->data << " ";
//			cur = cur->next;
//		}
//		cout << cur->data << endl;
//	}
//};
//
//int main() {
//	int N;
//	cin >> N;
//
//	for (int i = 0; i < N; i++) {
//		CLinkedlist list;
//
//		for (int j = 0; j < 10; j++) {
//			int num;
//			cin >> num;
//			list.addBack(num);
//		}
//
//		for (int j = 0; j < 3; j++) {
//			string str;
//			cin >> str;
//			if (str == "Delete") {
//				int idx;
//				cin >> idx;
//				list.Delete(idx);
//			}
//		}
//		list.showList();
//	}
//	return 0;
//}
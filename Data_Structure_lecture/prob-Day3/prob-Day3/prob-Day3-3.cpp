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
//class CLinkedList {
//public:
//	Node* head;
//	Node* tail;
//
//	CLinkedList() {
//		head = NULL;
//		tail = NULL;
//	}
//
//	void addBack(int X) {
//		Node* v = new Node(X);
//		if (head == NULL) head = tail = v;
//		else if (head == tail) {
//			tail = v;
//			head->next = tail;
//			tail->next = head;
//		}
//		else {
//			tail->next = v;
//			v->next = head;
//			tail = v;
//		}
//	}
//
//	void Delete(int idx) {
//		if (idx == 0) {
//			tail->next = head->next;
//			head = tail->next;
//		}
//		else {
//			Node* cur = head;
//			for (int i = 0; i < (idx - 1); i++) cur = cur->next;
//
//			if (cur->next == head) {
//				tail->next = head->next;
//				head = tail->next;
//			}
//			else if (cur->next == tail) {
//				cur->next = head;
//				tail = cur;
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
//		CLinkedList list;
//		string str1 = "Delete";
//
//		for (int j = 0; j < 10; j++) {
//			int num;
//			cin >> num;
//
//			list.addBack(num);
//		}
//
//		for (int j = 0; j < 3; j++) {
//			string str;
//			cin >> str;
//
//			if (str == str1) {
//				int num;
//				cin >> num;
//
//				list.Delete(num);
//			}
//		}
//		list.showList();
//	}
//	return 0;
//}


//#include <iostream>
//#include <string>
//using namespace std;
//
//class node {
//public:
//	int data;
//	node* next;
//
//	node(int x) {
//		data = x;
//		next = NULL;
//	}
//};
//
//class clinkedlist {
//public:
//	node* head;
//	node* tail;
//
//	clinkedlist() {
//		head = NULL;
//		tail = NULL;
//	}
//
//	void add(int x) {
//		node* v = new node(x);
//
//		if (head == NULL) {
//			head = v;
//		}
//		else if (tail == NULL){
//			tail = v;
//			head->next = tail;
//			tail->next = head;
//		}
//		else {
//			tail->next = v;
//			tail = v;
//			tail->next = head;
//		}
//	}
//
//	void Delete(int idx) {
//		node* cur = head;
//
//		if (idx == 0) {
//			tail->next = head->next;
//			head = head->next;
//		}
//	
//		else {
//			for (int i = 0; i < (idx - 1); i++) cur = cur->next;
//
//			if (cur->next == head) {
//				tail->next = head->next;
//				head = head->next;
//			}
//			else if (cur->next == tail) {
//				cur->next = tail->next;
//				tail = cur;
//			}
//			else {
//				node* curnext = cur->next;
//				cur->next = curnext->next;
//			}
//		}
//	}
//	
//	void showlist() {
//		node* cur = head;
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
//	string str1 = "Delete";
//
//	int n;
//	cin >> n;
//
//	for (int i = 0; i < n; i++) {
//		clinkedlist list;
//		for (int j = 0; j < 10; j++) {
//			int m;
//			cin >> m;
//
//			list.add(m);
//		}
//
//		for (int j = 0; j < 3; j++) {
//			string str;
//			cin >> str;
//			if (str == str1) {
//				int idx;
//				cin >> idx;
//
//				list.Delete(idx);
//			}
//		}
//		list.showlist();
//	}
//	return 0;
//}


#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int data;
	Node* next;

	Node(int e) {
		data = e;
		next = NULL;
	}
};

class CLinkedList {
public:
	Node* head;
	Node* tail;

	CLinkedList() {
		head = NULL;
		tail = NULL;
	}

	void addBack(int e) {
		Node* v = new Node(e);
		if (head == NULL) head = tail = v;
		else {
			tail->next = v;
			tail = v;
			tail->next = head;
		}
	}

	void Delete(int idx) {
		if (idx == 0) {
			head = head->next;
			tail->next = head;
		}
		else {
			Node* cur = head;
			for (int i = 0; i < (idx - 1); i++) cur = cur->next;
			
			if (cur->next == head) {
				head = head->next;
				tail->next = head;
			}
			else if (cur->next == tail) {
				tail = cur;
				cur->next = head;
			}
			else {
				Node* curNext = cur->next;
				cur->next = curNext->next;
			}
		}
	}

	void showList() {
		Node* cur = head;
		while (cur->next != head) {
			cout << cur->data << " ";
			cur = cur->next;
		}
		cout << cur->data << endl;
	}
};

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		CLinkedList list;
		for (int j = 0; j < 10; j++) {
			int e;
			cin >> e;
			list.addBack(e);
		}

		for (int j = 0; j < 3; j++) {
			string str;
			cin >> str;

			if (str == "Delete") {
				int idx;
				cin >> idx;
				list.Delete(idx);
			}
		}
		list.showList();
	}
	return 0;
}
//#include <iostream>
//#include <string>
//using namespace std;
//
//class arrayStack {
//public:
//	int* S;
//	int capacity;
//	int t;
//
//	arrayStack(int capacity) {
//		this->capacity = capacity;
//		this->S = new int[capacity];
//		this->t = -1;
//	}
//
//	int empty() {
//		if (t == -1) return 1;
//		return 0;
//	}
//
//	int top() {
//		if (t == -1) return -1;
//		return S[t];
//	}
//
//	void push(int e) {
//		t = t + 1;
//		S[t] = e;
//	}
//
//	int pop() {
//		if (t == -1) return -1;
//		
//		t = t - 1;
//		return S[t + 1];
//	}
//
//	int size() {
//		return (t + 1);
//	}
//};
//
//int main() {
//	arrayStack s(20000);
//	string str1 = "empty", str2 = "top", str3 = "push", str4 = "pop", str5 = "size";
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

//#include <iostream>
//#include <string>
//using namespace std;
//
//class Node {
//public:
//	int data;
//	Node* next;
//
//	Node(int X) {
//		data = X;
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
//	void addFront(int e) {
//		Node* v = new Node(e);
//		if (head == NULL) head = v;
//		else {
//			v->next = head;
//			head = v;
//		}
//	}
//
//	int removeFront() {
//		int tmp = head->data;
//		head = head->next;
//		return tmp;
//	}
//
//	int front() {
//		if (head == NULL) return -1;
//
//		int tmp = head->data;
//		return tmp;
//	}
//};
//
//class ListStack {
//public:
//	int n;
//	SLinkedList* S;
//
//	ListStack() {
//		n = 0;
//		S = new SLinkedList();
//	}
//
//	int empty() {
//		if (n == 0) return 1;
//		return 0;
//	}
//
//	int top() {
//		return S->front();
//	}
//
//	void push(int e) {
//		n++;
//		S->addFront(e);
//	}
//
//	int pop() {
//		if (n == 0) return -1;
//
//		n--;
//		return S->removeFront();
//	}
//
//	int size() {
//		return n;
//	}
//};
//
//int main() {
//	ListStack s;
//	string str1 = "empty", str2 = "top", str3 = "push", str4 = "pop", str5 = "size";
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


//
//#include <iostream>
//#include <string>
//using namespace std;
//
//class Arraystack {
//public:
//	int t;
//	int* S;
//
//	Arraystack(int size) {
//		t = -1;
//		S = new int[size];
//	}
//
//	int empty() {
//		if (t == -1) return 1;
//		return 0;
//	}
//
//	int top() {
//		if (t == -1) return -1;
//		return S[t];
//	}
//
//	void push(int X) {
//		t = t + 1;
//		S[t] = X;
//	}
//
//	int pop() {
//		if (t == -1) return -1;
//
//		int tmp = S[t];
//		t = t - 1;
//		return tmp;
//	}
//
//	int size() {
//		return (t + 1);
//	}
//};
//
//int main() {
//	string str1 = "empty", str2 = "top", str3 = "push", str4 = "pop", str5 = "size";
//	Arraystack S(20000);
//	int N;
//	cin >> N;
//
//	for (int i = 0; i < N; i++) {
//		string str;
//		cin >> str;
//
//		if (str == str1) cout << S.empty() << endl;
//		else if (str == str2) cout << S.top() << endl;
//		else if (str == str3) {
//			int num;
//			cin >> num;
//			S.push(num);
//		}
//		else if (str == str4) cout << S.pop() << endl;
//		else if (str == str5) cout << S.size() << endl;
//	}
//	return 0;
//}

//
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
//	void addFront(int e) {
//		Node* v = new Node(e);
//		if (head == NULL) head = v;
//		else {
//			v->next = head;
//			head = v;
//		}
//	}
//	int front() {
//		return head->data;
//	}
//	int removeFront() {
//		int tmp = head->data;
//		head = head->next;
//		return tmp;
//	}
//};
//
//class Liststack {
//public:
//	int n;
//	SLinkedList* S;
//
//	Liststack() {
//		n = 0;
//		S = new SLinkedList();
//	}
//
//	int empty() {
//		if (n == 0) return 1;
//		return 0;
//	}
//
//	int top() {
//		if (n == 0) return -1;
//		return S->front();
//	}
//
//	void push(int X) {
//		S->addFront(X);
//		n++;
//	}
//
//	int pop() {
//		if (n == 0) return -1;
//
//		n--;
//		return S->removeFront();
//	}
//
//	int size() {
//		return n;
//	}
//};
//
//int main() {
//	string str1 = "empty", str2 = "top", str3 = "push", str4 = "pop", str5 = "size";
//	Liststack S;
//
//	int N;
//	cin >> N;
//
//	for (int i = 0; i < N; i++) {
//		string str;
//		cin >> str;
//
//		if (str == str1) cout << S.empty() << endl;
//		else if (str == str2) cout << S.top() << endl;
//		else if (str == str3) {
//			int num;
//			cin >> num;
//			S.push(num);
//		}
//		else if (str == str4) cout << S.pop() << endl;
//		else if (str == str5) cout << S.size() << endl;
//	}
//	return 0;
//}
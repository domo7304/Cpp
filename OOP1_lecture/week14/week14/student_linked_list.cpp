#include <iostream>
using namespace std;

// studetn node class ����
class StudentNode {
private:
	int id;
	string name;
	StudentNode* next;
public:
	StudentNode(const int id, const string name) {
		this->id = id;
		this->name = name;
		this->next = NULL;
	}
	void setId(int id) {
		this->id = id;
	}
	int getId() {
		return id;
	}
	void setName(string name) {
		this->name = name;
	}
	string getName() {
		return name;
	}
	void setNext(StudentNode* next) {
		this->next = next;
	}
	StudentNode* getNext() {
		return next;
	}
};

// student node�� ��������� ������ studentlist ����
class StudetnList {
private:
	StudentNode* head;
	StudentNode* tail;
public:
	// ����Ʈ�����ڷ� head�κа� tail�κ� NULL ����
	StudetnList() {
		head = NULL;
		tail = NULL;
	}

	void addFront(int id, string str) {
		StudentNode* v = new StudentNode(id, str);
		if (head == NULL) {
			head = tail = v;
		}
		else {
			v->setNext(head);
			head = v;
		}
	}

	// str�� ���ڷ� ������ Student node ��ü�� ���� ����� tail�� ����
	void addBack(int id, string str) {
		StudentNode* v = new StudentNode(id, str);
		if (head == NULL) {
			head = tail = v;
		}
		else {
			tail->setNext(v);
			tail = v;
		}
	}
	// cur = head �� ���� �� cur->getNext() �� ���� ������ 
	// ��, cur�� ������ ������ ������ while�� �ݺ��Ͽ� ���� ���
	void print() {
		StudentNode* cur = head;

		if (cur == NULL) cout << "empty list" << "\n\n";
		else {
			while (cur->getNext() != NULL) {
				cout << cur->getId() << " " <<  cur->getName() << " ";
				cur = cur->getNext();
			}
			cout << cur->getId() << " " << cur->getName() << "\n\n";
		}
	}

	void searchId(string str) {
		StudentNode* cur = head;

		while (cur != NULL && cur->getName() != str) cur = cur->getNext();
		
		if (cur == NULL) cout << "That string doesn't exist in this list" << "\n\n";
		else cout << cur->getId() << " " << cur->getName() << "\n\n";
	}
};

int main() {
	StudetnList list;

	cout << "Before ad Student nodes : \n";
	list.print();

	list.addBack(1, "Kim");
	cout << "After add Student node 'Kim' : \n";
	list.print();

	list.addBack(2, "Lee");
	cout << "After add Student node 'Kim' : \n";
	list.print();

	list.addFront(3, "Park");
	cout << "After add Student node 'Park' : \n";
	list.print();

	cout << "Search id of 'Lee' : ";
	list.searchId("Lee");

	cout << "Search id of node doesn't exist : ";
	list.searchId("Choi");
}
#include <iostream>
using namespace std;

// studetn node class ����
class StudentNode {
private:
	string name;
	StudentNode* next;
public:
	StudentNode(const string name) {
		this->name = name;
		this->next = NULL;
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
	// str�� ���ڷ� ������ Student node ��ü�� ���� ����� tail�� ����
	void addBack(string str) {
		StudentNode* v = new StudentNode(str);
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

		if (cur == NULL) cout << "empty list" << '\n';
		else {
			while (cur->getNext() != NULL) {
				cout << cur->getName() << " ";
				cur = cur->getNext();
			}
			cout << cur->getName() << '\n';
		}
	}
};

int main() {
	StudetnList list;

	cout << "Before ad Student nodes : \n";
	list.print();

	list.addBack("Kim");
	cout << "After add Student node 'Kim' : \n";
	list.print();

	list.addBack("Lee");
	cout << "After add Student node 'Kim' : \n";
	list.print();
}
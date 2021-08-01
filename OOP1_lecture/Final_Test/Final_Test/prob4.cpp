//#include <iostream>
//using namespace std;
//
//class StudentNode {
//private:
//	string name;
//	int studentID;
//	string major;
//	StudentNode* next;
//public:
//	StudentNode(string name, int studentID, string major) {
//		this->name = name;
//		this->studentID = studentID;
//		this->major = major;
//	}
//	void setName(string name) {
//		this->name = name;
//	}
//	void setStudentID(int studentID) {
//		this->studentID = studentID;
//	}
//	void setMajor(string major) {
//		this->major = major;
//	}
//	void setNext(StudentNode* next) {
//		this->next = next;
//	}
//	string getName() { return name; }
//	int getStudentID() { return studentID; }
//	string getMajor() { return major; }
//	StudentNode* getNext() { return next; }
//
//	~StudentNode() {
//
//	}
//};
//
//class StudentList {
//private:
//	StudentNode* head;
//public:
//	StudentList() {
//		head = NULL;
//	}
//
//	void addToHead(StudentNode* v) {
//		if (head == NULL) {
//			head = v;
//		}
//		else {
//			v->setNext(head);
//			head = v;
//		}
//	}
//
//	void printALLName() {
//		StudentNode* cur = head;
//		while (cur->getNext() != NULL) {
//			cout << "name : " << cur->getName()
//				<< ", studentID : " << cur->getStudentID()
//				<< ", major : " << cur->getMajor() << "\n\n";
//			cur = cur->getNext();
//		}
//		cout << "name : " << cur->getName()
//			<< ", studentID : " << cur->getStudentID()
//			<< ", major : " << cur->getMajor() << "\n\n";
//	}
//};
//
//int main() {
//	StudentNode s1("Kim", 12190000, "��ǻ�Ͱ���"),
//		s2("Min", 12190001, "��ǻ�Ͱ���"),
//		s3("Lee", 12190002, "��ǻ�Ͱ���"),
//		s4("Hwang", 12190003, "��ǻ�Ͱ���"),
//		s5("Park", 12190004, "��ǻ�Ͱ���"),
//		s6("Jonh", 12190005, "������"),
//		s7("Anna", 12190006, "������"),
//		s8("Jaehee", 12190007, "������"),
//		s9("Sofia", 12190008, "ȯ�����"),
//		s10("Choi", 12190009, "ȯ�����");
//
//	StudentList list1, list2, list3;
//
//	list1.addToHead(&s1);
//	list1.addToHead(&s2);
//	list1.addToHead(&s3);
//	list1.addToHead(&s4);
//	list1.addToHead(&s5);
//	list2.addToHead(&s6);
//	list2.addToHead(&s7);
//	list2.addToHead(&s8);
//	list3.addToHead(&s9);
//	list3.addToHead(&s10);
//	
//	cout << "< ��ǻ�Ͱ��а� List >" << '\n';
//	list1.printALLName();
//
//	cout << "\n< �����а� List >" << '\n';
//	list2.printALLName();
//
//	cout << "\n< ȯ����а� List > " << '\n';
//	list3.printALLName();
//}
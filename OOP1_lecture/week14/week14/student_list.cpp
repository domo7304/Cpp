//#include <iostream>
//using namespace std;
//
//class StudentNode {
//private:
//	string name;
//	int id;
//	StudentNode* next;
//public:
//	StudentNode(const string name, int id, StudentNode* next) {
//		this->name = name;
//		this->id = id;
//		this->next = next;
//	}
//	StudentNode(const string name, int id) {
//		this->name = name;
//		this->id = id;
//		this->next = NULL;
//	}
//
//	void setNext(StudentNode* next) {
//		this->next = next;
//	}
//	StudentNode* getNext() {
//		return next;
//	}
//	void printElements() {
//		cout << "id : " << id << ", name : " << name << '\n';
//	}
//};
//
//int main() {
//	const string name[3] = { "kim", "lee", "park" };
//	
//	StudentNode s1(name[0], 1111);
//	StudentNode s2(name[1], 2222);
//	StudentNode s3(name[2], 3333);
//
//	s1.setNext(&s2);
//	s2.setNext(&s3);
//
//	s1.printElements();
//	s1.getNext()->printElements();
//	s1.getNext()->getNext()->printElements();
//}
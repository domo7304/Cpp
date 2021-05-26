//#include <iostream>
//#include <vector>
//using namespace std;
//
//class Node {
//public:
//	int data;
//	Node* par;
//	vector <Node*> chil;
//
//	Node() {
//		data = NULL;
//		par = NULL;
//	}
//	Node(int data) {
//		this->data = data;
//		par = NULL;
//	}
//	~Node() {}
//
//	void insertChild(Node* chil) {
//		this->chil.push_back(chil);
//	}
//
//	void deleteChild(Node* chil) {
//		for (int i = 0; i < this->chil.size(); i++) {
//			if (this->chil[i] == chil) {
//				this->chil.erase(this->chil.begin() + i);
//				break;
//			}
//		}
//	}
//};
//
//class GenaralTree {
//private:
//	Node* root;
//	vector <Node*> node_list;
//public:
//	GenaralTree() {
//		root = NULL;
//	}
//	GenaralTree(int data) {
//		root = new Node(data);
//		node_list.push_back(root);
//	}
//	~GenaralTree() {}
//
//	void setRoot(int data) {
//		root = new Node(data);
//		node_list.push_back(root);
//	}
//
//	Node* getRoot() {
//		return root;
//	}
//
//	void insertNode(int parent_data, int data) {
//		Node* v = new Node(data);
//		v->par = findNode(parent_data);
//		v->par->insertChild(v);
//		
//		node_list.push_back(v);
//	}
//
//	Node* findNode(int data) {
//		for (int i = 0; i < node_list.size(); i++) {
//			if (node_list[i]->data == data) return node_list[i];
//		}
//	}
//
//	void printChild(int data) {
//		Node* par = findNode(data);
//		for (int i = 0; i < par->chil.size(); i++) cout << par->chil[i]->data << " ";
//		cout << endl;
//	}
//};
//
//int main() {
//	string str1 = "insert", str2 = "printChild";
//	GenaralTree tree(1);
//	int N;
//	cin >> N;
//
//	for (int i = 0; i < N; i++) {
//		string str;
//		cin >> str;
//
//		if (str == str1) {
//			int parent, child;
//			cin >> parent >> child;
//			tree.insertNode(parent, child);
//		}
//		else if (str == str2) {
//			int parent;
//			cin >> parent;
//			tree.printChild(parent);
//		}
//	}
//	return 0;
//}
////#include <iostream>
////#include <vector>
////using namespace std;
////
////class Node {
////public:
////	int data;
////	int depth;
////	Node* par;
////	vector <Node*> chil;
////
////	Node() {
////		data = NULL;
////		depth = NULL;
////		par = NULL;
////	}
////	Node(int data) {
////		this->data = data;
////		depth = NULL;
////		par = NULL;
////	}
////	~Node() {}
////
////	void insertChild(Node* chil) {
////		this->chil.push_back(chil);
////	}
////
////	void deleteChild(Node* chil) {
////		for (int i = 0; i < this->chil.size(); i++) {
////			if (this->chil[i] == chil) {
////				this->chil.erase(this->chil.begin() + i);
////				break;
////			}
////		}
////	}
////};
////
////class GenaralTree {
////private:
////	Node* root;
////	vector <Node*> node_list;
////public:
////	GenaralTree() {
////		root = NULL;
////	}
////	GenaralTree(int data) {
////		root = new Node(data);
////		node_list.push_back(root);
////	}
////	~GenaralTree() {}
////
////	void setRoot(int data) {
////		root = new Node(data);
////		node_list.push_back(root);
////	}
////
////	Node* getRoot() {
////		return root;
////	}
////
////	void insertNode(int parent_data, int data) {
////		Node* v = new Node(data);
////		v->par = findNode(parent_data);
////		
////		if (v->par == NULL) cout << -1 << endl;
////		else {
////			v->par->insertChild(v);
////			v->depth = v->par->depth + 1;
////		}
////		node_list.push_back(v);
////	}
////
////	Node* findNode(int data) {
////		for (int i = 0; i < node_list.size(); i++) {
////			if (node_list[i]->data == data) return node_list[i];
////		}
////		return NULL;
////	}
////
////	void printChild(int data) {
////		Node* par = findNode(data);
////		if (par == NULL) cout << -1 << endl;
////		else if (par->chil.size() == 0) cout << 0 << endl;
////		else {
////			for (int i = 0; i < par->chil.size(); i++) cout << par->chil[i]->data << " ";
////			cout << endl;
////		}
////	}
////
////	int printDepth(int data) {
////		Node* cur = findNode(data);
////		if (cur == NULL) return -1;
////		return cur->depth;
////	}
////};
////
////int main() {
////	string str1 = "insert", str2 = "printChild", str3 = "printDepth";
////	GenaralTree tree(1);
////	int N;
////	cin >> N;
////
////	for (int i = 0; i < N; i++) {
////		string str;
////		cin >> str;
////
////		if (str == str1) {
////			int parent, child;
////			cin >> parent >> child;
////			tree.insertNode(parent, child);
////		}
////		else if (str == str2) {
////			int parent;
////			cin >> parent;
////			tree.printChild(parent);
////		}
////		else if (str == str3) {
////			int data;
////			cin >> data;
////			cout << tree.printDepth(data) << endl;
////		}
////	}
////	return 0;
////}
//
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//
//class Node {
//public:
//	int data;
//	int depth;
//	Node* par;
//	vector <Node*> chil;
//
//	Node() {
//		data = 0;
//		depth = 0;
//		par = NULL;
//	}
//
//	Node(int data) {
//		this->data = data;
//		depth = 0;
//		par = NULL;
//	}
//
//	void insertChild(Node* node) {
//		chil.push_back(node);
//	}
//};
//
//
//class GeneralTree {
//public:
//	Node* root;
//	vector <Node*> node_list;
//
//	GeneralTree(int data) {
//		root = new Node(data);
//		node_list.push_back(root);
//	}
//
//	void insertNode (int parent_data, int data) {
//		Node* v = new Node(data);
//
//		v->par = findNode(parent_data);
//		if (v->par == NULL) cout << -1 << endl;
//		else {
//			v->par->insertChild(v);
//			v->depth = v->par->depth + 1;
//			node_list.push_back(v);
//		}
//	}
//
//	Node* findNode(int data) {
//		for (int i = 0; i < node_list.size(); i++) {
//			if (node_list[i]->data == data) return node_list[i];
//		}
//		return NULL;
//	}
//
//	void printChild(int data) {
//		Node* v = findNode(data);
//
//		if (v == NULL) cout << -1 << endl;
//		else if (v->chil.size() == 0) cout << 0 << endl;
//		else {
//			for (int i = 0; i < v->chil.size(); i++) cout << v->chil[i]->data << " ";
//			cout << endl;
//		}
//	}
//
//	int printDepth(int data) {
//		Node* cur = findNode(data);
//		if (cur == NULL) return -1;
//		return cur->depth;
//	}
//};
//
//int main() {
//	string str1 = "insert", str2 = "printChild", str3 = "printDepth";
//	int N;
//	cin >> N;
//
//	GeneralTree tree(1);
//	for (int i = 0; i < N; i++) {
//		string str;
//		cin >> str;
//
//		if (str == str1) {
//			int parent_data, child_data;
//			cin >> parent_data >> child_data;
//			tree.insertNode(parent_data, child_data);
//		}
//		else if (str == str2) {
//			int data;
//			cin >> data;
//			tree.printChild(data);
//		}
//		else if (str == str3) {
//			int data;
//			cin >> data;
//			cout << tree.printDepth(data) << endl;
//		}
//	}
//	return 0;
//}
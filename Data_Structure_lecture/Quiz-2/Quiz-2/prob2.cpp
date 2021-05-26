//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//
//class Node {
//public:
//	int data;
//	Node* par;
//	vector <Node*> chil;
//
//	Node(int data) {
//		this->data = data;
//		par = NULL;
//	}
//
//	void insertChil(Node* chil) {
//		this->chil.push_back(chil);
//	}
//};
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
//	void insert(int parent_data, int data) {
//		Node* v = new Node(data);
//		v->par = findNode(parent_data);
//
//		v->par->insertChil(v);
//		node_list.push_back(v);
//	}
//
//	Node* findNode(int data) {
//		for (int i = 0; i < node_list.size(); i++) {
//			if (node_list[i]->data == data) return node_list[i];
//		}
//	}
//
//	void printChild(int X) {
//		Node* par = findNode(X);
//		for (int i = 0; i < par->chil.size(); i++) {
//			cout << par->chil[i]->data << " ";
//		}
//		cout << endl;
//	}
//};
//
//int main() {
//	string str1 = "insert", str2 = "printChild";
//	int N;
//	cin >> N;
//
//	GeneralTree tree(1);
//	for (int i = 0; i < N; i++) {
//		string str;
//		cin >> str;
//
//		if (str == str1) {
//			int parent_data, data;
//			cin >> parent_data >> data;
//			tree.insert(parent_data, data);
//		}
//		else if (str == str2) {
//			int X;
//			cin >> X;
//			tree.printChild(X);
//		}
//	}
//	return 0;
//}
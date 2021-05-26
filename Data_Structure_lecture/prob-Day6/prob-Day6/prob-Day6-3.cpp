//#include <iostream>
//#include <string>
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
//		node_list.push_back(v);
//
//		v->par = findNode(parent_data);
//		v->par->insertChild(v);
//	}
//
//	Node* findNode(int data) {
//		for (int i = 0; i < node_list.size(); i++) {
//			if (node_list[i]->data == data) return node_list[i];
//		}
//		return NULL;
//	}
//
//	void preorder(Node* node) {
//		cout << node->data << " ";
//		
//		for (int i = 0; i < node->chil.size(); i++) {
//			preorder(node->chil[i]);
//		}
//	}
//
//	void postorder(Node* node) {
//		for (int i = 0; i < node->chil.size(); i++) {
//			postorder(node->chil[i]);
//		}
//		cout << node->data << " ";
//	}
//};
//
//int main() {
//	int N;
//	cin >> N;
//
//	for (int i = 0; i < N; i++){
//		GenaralTree tree(1);
//		int M;
//		cin >> M;
//
//		for (int j = 0; j < M; j++) {
//			int parent, chil;
//			cin >> parent >> chil;
//			tree.insertNode(parent, chil);
//		}
//		tree.preorder(tree.getRoot());
//		cout << endl;
//		tree.postorder(tree.getRoot());
//		cout << endl;
//	}
//	return 0;
//}
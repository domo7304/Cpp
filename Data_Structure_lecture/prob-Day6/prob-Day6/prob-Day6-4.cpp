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
//		data = NULL;
//		depth = NULL;
//		par = NULL;
//	}
//	Node(int data) {
//		this->data = data;
//		depth = NULL;
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
//	int height;
//	Node* root;
//	vector <Node*> node_list;
//public:
//	GenaralTree() {
//		height = 0;
//		root = NULL;
//	}
//	GenaralTree(int data) {
//		height = 0;
//		root = new Node(data);
//		root->depth = 0;
//		node_list.push_back(root);
//	}
//
//	void setRoot(int data) {
//		height = 0;
//		root = new Node(data);
//		root->depth = 0;
//		node_list.push_back(root);
//	}
//
//	Node* getRoot() {
//		return root;
//	}
//
//	int getHeight() {
//		return height;
//	}
//
//	void insertNode(int parent_data, int data) {
//		Node* v = new Node(data);
//
//		v->par = findNode(parent_data);
//		v->depth = v->par->depth + 1;
//		v->par->insertChild(v);
//		node_list.push_back(v);
//
//		if (v->depth > height) height = v->depth;
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
//	for (int i = 0; i < N; i++) {
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
//		cout << tree.getHeight() << endl;
//	}
//	return 0;
//}


#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
	int data;
	int depth;
	Node* par;
	vector <Node*> chil;

	Node(int data) {
		this->data = data;
		depth = 0;
		par = NULL;
	}

	void insertChil(Node* chil) {
		this->chil.push_back(chil);
	}
};

class GeneralTree {
public:
	int height;
	Node* root;
	vector <Node*> node_list;

	GeneralTree(int data) {
		height = 0;
		root = new Node(data);
		node_list.push_back(root);
	}

	void insertNode(int parent_data, int data) {
		Node* v = new Node(data);
		v->par = findNode(parent_data);

		v->depth = v->par->depth + 1;
		v->par->insertChil(v);
		node_list.push_back(v);

		if (v->depth > height) height = v->depth;
	}

	Node* findNode(int data) {
		for (int i = 0; i < node_list.size(); i++) {
			if (node_list[i]->data == data) 
				return node_list[i];
		}
	}

	void preorder(Node* node) {
		cout << node->data << " ";
		for (int i = 0; i < node->chil.size(); i++) {
			preorder(node->chil[i]);
		}
	}

	void postorder(Node* node) {
		for (int i = 0; i < node->chil.size(); i++) {
			postorder(node->chil[i]);
		}
		cout << node->data << " ";
	}
};

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		GeneralTree tree(1);
		int M;
		cin >> M;

		for (int j = 0; j < M; j++) {
			int parent, chil;
			cin >> parent >> chil;
			tree.insertNode(parent, chil);
		}

		tree.preorder(tree.root);
		cout << endl;
		tree.postorder(tree.root);
		cout << endl;
		cout << tree.height << endl;
	}
	return 0;
}
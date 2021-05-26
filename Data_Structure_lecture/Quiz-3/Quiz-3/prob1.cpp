//#include <iostream>
//#include <string>
//using namespace std;
//
//class Node {
//public:
//	int data;
//	int depth;
//	Node* par;
//	Node* lchil;
//	Node* rchil;
//
//	Node(int data) {
//		this->data = data;
//		depth = 0;
//		par = NULL;
//		lchil = NULL;
//		rchil = NULL;
//	}
//};
//
//class BST {
//public:
//	Node* root;
//	int height;
//
//	BST() {
//		root = NULL;
//		height = 0;
//	}
//	
//	~BST() {
//		treedestructor(root);
//	}
//
//	void insert(int data) {
//		if (root == NULL) root = new Node(data);
//		else {
//			Node* v = new Node(data);
//
//			Node* cur = root;
//			Node* cur_par = NULL;
//
//			while (cur != NULL) {
//				cur_par = cur;
//				if (cur == NULL) break;
//				
//				if (data < cur->data) cur = cur->lchil;
//				else if (data > cur->data) cur = cur->rchil;
//			}
//
//			v->par = cur_par;
//			v->depth = v->par->depth + 1;
//
//			if (v->data < v->par->data) v->par->lchil = v;
//			else if (v->data > v->par->data) v->par->rchil = v;
//
//			if (v->depth > height) height = v->depth;
//		}
//	}
//
//	void treedestructor(Node* root) {
//		if (root == NULL) return;
//		
//		if (root->lchil != NULL) treedestructor(root->lchil);
//		if (root->rchil != NULL) treedestructor(root->rchil);
//		delete(root);
//	}
//};
//
//int main() {
//	int T;
//	cin >> T;
//
//	for (int i = 0; i < T; i++) {
//		int N;
//		cin >> N;
//		BST tree;
//		
//		for (int j = 0; j < N; j++) {
//			int data;
//			cin >> data;
//			tree.insert(data);
//		}
//		cout << tree.height << endl;
//	}
//	return 0;
//}
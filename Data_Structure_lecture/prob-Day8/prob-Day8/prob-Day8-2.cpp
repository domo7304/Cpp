#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int data;
	int depth;
	Node* par;
	Node* rChil;
	Node* lChil;

	Node(int data) {
		this->data = data;
		depth = 0;
		par = NULL;
		rChil = NULL;
		lChil = NULL;
	}
};

class BST {
public:
	Node* root;
	int height;

	BST() {
		height = 0;
		root = NULL;
	}

	~BST() {
		this->treeDestructor(this->root);
	}

	void insert(int e) {
		if (root == NULL) root = new Node(e);
		else {
			Node* v = new Node(e);

			Node* cur = root;
			Node* cur_par = NULL;

			while (cur != NULL) {
				if (cur->data == e) return;
				cur_par = cur;
				if (e < cur->data) cur = cur->lChil;
				else if (e > cur->data) cur = cur->rChil;
			}

			v->par = cur_par;
			v->depth = v->par->depth + 1;
			if (e < v->par->data) v->par->lChil = v;
			else if (e > v->par->data) v->par->rChil = v;

			if (v->depth > height) height = v->depth;
		}
	}
	
	void treeDestructor(Node* root) {
		if (root == NULL) return;
		if (root->lChil != NULL)
			this->treeDestructor(root->lChil);
		if (root->rChil != NULL)
			this->treeDestructor(root->rChil);
		delete(root);
	}

	int getHeight() {
		return height;
	}
};

int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int N;
		cin >> N;
		BST t;

		for (int j = 0; j < N; j++) {
			int e;
			cin >> e;
			t.insert(e);
		}

		cout << t.getHeight() << endl;
	}
	return 0;
}
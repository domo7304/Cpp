//#include <iostream>
//#include <string>
//using namespace std;
//
//class Node {
//public:
//	int data;
//	int depth;
//	Node* par;
//	Node* rChil;
//	Node* lChil;
//
//	Node(int data) {
//		this->data = data;
//		depth = 0;
//		par = NULL;
//		rChil = NULL;
//		lChil = NULL;
//	}
//
//	int printDegree() {
//		if (rChil != NULL && lChil != NULL) return 2;
//		else if (rChil != NULL || lChil != NULL) return 1;
//		return 0;
//	}
//
//	int printDepth() {
//		return depth;
//	}
//};
//
//class BST {
//public:
//	Node* root;
//
//	BST(){
//		root = NULL;
//	}
//
//	void insert(int e) {
//		if (root == NULL) root = new Node(e);
//		else {
//			Node* v = new Node(e);
//			v->par = findNode(e);
//			v->depth = v->par->depth + 1;
//			if (v->par->data < e) v->par->rChil = v;
//			else if (v->par->data > e) v->par->lChil = v;
//		}
//	}
//
//	Node* findNode(int data) {
//		Node* cur = root;
//		while (1) {
//			if (cur->data == data) return cur;
//			else {
//				if ((cur->data > data && cur->lChil == NULL) || (cur->data < data && cur->rChil == NULL)) return cur;
//				else if (cur->data < data) cur = cur->rChil;
//				else if (cur->data > data) cur = cur->lChil;
//			}
//		}
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
//		BST t;
//
//		for (int j = 0; j < N; j++) {
//			int e;
//			cin >> e;
//			t.insert(e);
//		}
//
//		int M;
//		cin >> M;
//		for (int j = 0; j < M; j++) {
//			int node;
//			cin >> node;
//			Node* v = t.findNode(node);
//			if (v->data != node) cout << 0 << endl;
//			else cout << v->printDegree() << " " << v->printDepth() << endl;
//		}
//	}
//	return 0;
//}


//void findNode(int data) {
//    Node* tmp = root;
//    while (tmp != NULL) {
//        if (tmp->data == data) {
//            //차수 깊이 출력하는 함수
//            tmp->printDegree();
//            tmp->printDepth();
//            return;
//        }
//        else {
//            if (tmp->data < data) tmp = tmp->rchild; //큰
//            else tmp = tmp->lchild; //작
//        }
//
//    }
//    cout << "0" << endl;
//    return;
//}
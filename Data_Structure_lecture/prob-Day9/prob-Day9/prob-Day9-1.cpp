//#include <iostream>
//#include <string>
//using namespace std;
//
//class vertex {
//public:
//	vertex* prev;
//	vertex* next;
//	int data;
//
//	vertex(int data) {
//		prev = NULL;
//		next = NULL;
//		this->data = data;
//	}
//};
//
//class edge {
//public:
//	edge* prev;
//	edge* next;
//	vertex* source;
//	vertex* destination;
//
//	edge(vertex* source, vertex* destination) {
//		prev = NULL;
//		next = NULL;
//		this->source = source;
//		this->destination = destination;
//	}
//};
//
//class DoublyVertexLinkedList {
//public:
//	vertex* head;
//	vertex* tail;
//	int size;
//
//	DoublyVertexLinkedList() {
//		head = NULL;
//		tail = NULL;
//		size = 0;
//	}
//
//	void insert(vertex* v) {
//		if (head == NULL) head = tail = v;
//		else {
//			tail->next = v;
//			v->prev = tail;
//			tail = v;
//		}
//		size++;
//	}
//
//	int getVertexsize() {
//		return size;
//	}
//};
//
//class DoublyEdgeLinkedList {
//public:
//	edge* head;
//	edge* tail;
//	int size;
//
//	DoublyEdgeLinkedList() {
//		head = NULL;
//		tail = NULL;
//		size = 0;
//	}
//
//	void insert(edge* e) {
//		if (head == NULL) head = tail = e;
//		else {
//			tail->next = e;
//			e->prev = tail;
//			tail = e;
//		}
//		size++;
//	}
//
//	int getEdgesize() {
//		return size;
//	}
//};
//
//class graph {
//public:
//	edge*** edgeMatrix;
//	DoublyVertexLinkedList* VertexList;
//	DoublyEdgeLinkedList* EdgeList;
//
//	graph() {
//		edgeMatrix = new edge**[1];
//		edgeMatrix[0] = new edge*[1];
//		edgeMatrix[0][0] = NULL;
//		VertexList = new DoublyVertexLinkedList();
//		EdgeList = new DoublyEdgeLinkedList();
//	}
//
//	// 입력된 vertex 가 존재하는지 bool type return
//	bool isfindVertex(int data) {
//		vertex* cur = VertexList->head;
//		while (cur != NULL) {
//			if (cur->data == data) return true;
//			cur = cur->next;
//		}
//		return false;
//	}
//
//	// 입력된 vertex data를 가지는 vertex return
//	vertex* findvertex(int data) {
//		vertex* cur = VertexList->head;
//		while (cur != NULL) {
//			if (cur->data == data) return cur;
//			cur = cur->next;
//		}
//	}
//
//	// 입력된 vertex의 idx return
//	int findVertexIdx(int data) {
//		vertex* cur = VertexList->head;
//		for (int i = 0; i < VertexList->size; i++) {
//			if (cur->data == data) return i;
//			cur = cur->next;
//		}
//	}
//
//	void insertVertex(int data) {
//		if (isfindVertex(data)) return;
//		
//		// 기존의 matrix 보다 1만큼 더 큰 matrix 생성
//		edge*** tmp_Matrix = new edge**[VertexList->size + 1];
//		for (int i = 0; i < VertexList->size + 1; i++) {
//			tmp_Matrix[i] = new edge*[VertexList->size + 1]; {
//				for (int j = 0; j < VertexList->size + 1; j++) tmp_Matrix[i][j] = NULL;
//			}
//		}
//
//		// 기존의 값 복사해주기
//		for (int i = 0; i < VertexList->size; i++) {
//			for (int j = 0; j < VertexList->size; j++) {
//				tmp_Matrix[i][j] = edgeMatrix[i][j];
//			}
//		}
//		
//		// 주소 옮겨주기
//		edgeMatrix = tmp_Matrix;
//
//		// vertexList 에 새로운 vertex로 저장
//		vertex* v = new vertex(data);
//		VertexList->insert(v);
//	}
//
//	void insertEdge(int source, int destination) {
//		// 존재하지 않는 vertex를 입력했을 경우
//		if (isfindVertex(source) == false || isfindVertex(destination) == false) {
//			cout << -1 << endl;
//			return;
//		}
//
//		// vertex가 저장된 idx탐색
//		int source_idx = findVertexIdx(source);
//		int destination_idx = findVertexIdx(destination);
//
//		// 이미 존재하는 edge를 입력했을 경우
//		if (edgeMatrix[source_idx][destination_idx] != NULL || edgeMatrix[destination_idx][source_idx] != NULL) {
//			cout << -1 << endl;
//			return;
//		} 
//
//		// edgeList, matrix에 새로운 edge로 저장
//		edge* e = new edge(findvertex(source), findvertex(destination));
//		edgeMatrix[source_idx][destination_idx] = e;
//		edgeMatrix[destination_idx][source_idx] = e;
//		EdgeList->insert(e);
//	}
//
//	void print() {
//		cout << VertexList->getVertexsize() << " " << EdgeList->getEdgesize() << endl;
//	}
//};
//
//int main() {
//	graph g;
//	int N, M;
//	cin >> N >> M;
//
//	for (int i = 0; i < N; i++) {
//		int vertex;
//		cin >> vertex;
//		g.insertVertex(vertex);
//	}
//
//	for (int i = 0; i < M; i++) {
//		int source, destination;
//		cin >> source >> destination;
//		g.insertEdge(source, destination);
//	}
//
//	g.print();
//	return 0;
//}
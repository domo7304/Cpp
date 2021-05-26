//#include <iostream>
//using namespace std;
//
//class vertex {
//public:
//	int data;
//	vertex* prev;
//	vertex* next;
//
//	vertex(int data) {
//		this->data = data;
//		prev = NULL;
//		next = NULL;
//	}
//};
//
//class edge {
//public:
//	vertex* source;
//	vertex* destination;
//	edge* prev;
//	edge* next;
//
//	edge(vertex* source, vertex* destination) {
//		this->source = source;
//		this->destination = destination;
//		prev = NULL;
//		next = NULL;
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
//};
//
//class graph {
//public:
//	edge*** edgeMatrix;
//	DoublyVertexLinkedList* vertexList;
//	DoublyEdgeLinkedList* edgeList;
//
//	graph() {
//		edgeMatrix = new edge * *[1];
//		edgeMatrix[0] = new edge * [1];
//		edgeMatrix[0][0] = NULL;
//		vertexList = new DoublyVertexLinkedList();
//		edgeList = new DoublyEdgeLinkedList();
//	}
//
//	bool isfindvertex(int data) {
//		vertex* cur = vertexList->head;
//		for (int i = 0; i < vertexList->size; i++) {
//			if (cur->data == data) return true;
//			cur = cur->next;
//		}
//		return false;
//	}
//
//	vertex* findvertex(int data) {
//		vertex* cur = vertexList->head;
//		for (int i = 0; i < vertexList->size; i++) {
//			if (cur->data == data) return cur;
//			cur = cur->next;
//		}
//		return NULL;
//	}
//
//	int findvertexidx(int data) {
//		vertex* cur = vertexList->head;
//		for (int i = 0; i < vertexList->size; i++) {
//			if (cur->data == data) return i;
//			cur = cur->next;
//		}
//		return NULL;
//	}
//
//	void insertVertex(int data) {
//		if (isfindvertex(data)) return;
//
//		edge*** tmp = new edge * *[vertexList->size + 1];
//		for (int i = 0; i < vertexList->size + 1; i++) {
//			tmp[i] = new edge * [vertexList->size + 1];
//			for (int j = 0; j < vertexList->size + 1; j++) tmp[i][j] = NULL;
//		}
//
//		for (int i = 0; i < vertexList->size; i++) {
//			for (int j = 0; j < vertexList->size; j++) {
//				tmp[i][j] = edgeMatrix[i][j];
//			}
//		}
//
//		edgeMatrix = tmp;
//
//		vertex* v = new vertex(data);
//		vertexList->insert(v);
//	}
//
//	void insertEdge(int source, int destination) {
//		if (isfindvertex(source) == false || isfindvertex(destination) == false) {
//			cout << -1 << endl;
//			return;
//		}
//
//		int source_idx = findvertexidx(source);
//		int destination_idx = findvertexidx(destination);
//
//		if (edgeMatrix[source_idx][destination_idx] != NULL || edgeMatrix[destination_idx][source_idx] != NULL) {
//			cout << -1 << endl;
//			return;
//		}
//
//		edge* e = new edge(findvertex(source), findvertex(destination));
//		edgeMatrix[source_idx][destination_idx] = e;
//		edgeMatrix[destination_idx][source_idx] = e;
//		edgeList->insert(e);
//	}
//
//	void adjacency(int source, int destination) {
//		if (isfindvertex(source) == false || isfindvertex(destination) == false) {
//			cout << -1 << endl;
//			return;
//		}
//
//		int source_idx = findvertexidx(source);
//		int destination_idx = findvertexidx(destination);
//
//		if (edgeMatrix[source_idx][destination_idx] != NULL || edgeMatrix[destination_idx][source_idx] != NULL) {
//			cout << 1 << endl;
//			return;
//		}
//		else {
//			cout << 0 << endl;
//			return;
//		}
//	}
//};
//
//int main() {
//	graph g;
//	int N, M, K;
//	cin >> N >> M >> K;
//
//	for (int i = 0; i < N; i++) {
//		int vertex;
//		cin >> vertex;
//		g.insertVertex(vertex);
//	}
//
//	for (int i = 0; i < M; i++) {
//		int a, b;
//		cin >> a >> b;
//		g.insertEdge(a, b);
//	}
//
//	cout << g.vertexList->size << " " << g.edgeList->size << endl;
//
//	for (int i = 0; i < K; i++) {
//		int a, b;
//		cin >> a >> b;
//		g.adjacency(a, b);
//	}
//	return 0;
//}
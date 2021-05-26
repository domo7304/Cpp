//#include <iostream>
//#include <string>
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
//	string str;
//
//	edge(vertex* source, vertex* destination, string str) {
//		this->source = source;
//		this->destination = destination;
//		prev = NULL;
//		next = NULL;
//		this->str = str;
//	}
//
//	string getstring() {
//		return str;
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
//	void remove(vertex* v) {
//		if (v == head || v == tail) {
//			if (v == head && v != tail) {
//				vertex* tmp = head;
//				head = head->next;
//				head->prev = NULL;
//				delete tmp;
//			}
//			else if (v != head && v == tail) {
//				vertex* tmp = tail;
//				tail = tail->prev;
//				tail->next = NULL;
//				delete tmp;
//			}
//			else head = tail = NULL;
//		}
//		else {
//			v->prev->next = v->next;
//			v->next->prev = v->prev;
//			delete v;
//		}
//		size--;
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
//	void remove(edge* e) {
//		if (e == head || e == tail) {
//			if (e == head && e != tail) {
//				edge* tmp = head;
//				head = head->next;
//				head->prev = NULL;
//				delete tmp;
//			}
//			else if (e != head && e == tail) {
//				edge* tmp = tail;
//				tail = tail->prev;
//				tail->next = NULL;
//				delete tmp;
//			}
//			else head = tail = NULL;
//		}
//		else {
//			e->prev->next = e->next;
//			e->next->prev = e->prev;
//			delete e;
//		}
//		size--;
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
//	void insertvertex(int data) {
//		if (isfindvertex(data)) return;
//
//		edge*** tmpMatrix = new edge * *[vertexList->size + 1];
//		for (int i = 0; i < vertexList->size + 1; i++) {
//			tmpMatrix[i] = new edge * [vertexList->size + 1];
//			for (int j = 0; j < vertexList->size + 1; j++) tmpMatrix[i][j] = NULL;
//		}
//
//		for (int i = 0; i < vertexList->size; i++) {
//			for (int j = 0; j < vertexList->size; j++) tmpMatrix[i][j] = edgeMatrix[i][j];
//		}
//
//		edgeMatrix = tmpMatrix;
//
//		vertex* v = new vertex(data);
//		vertexList->insert(v);
//	}
//
//	void erasevertex(int data) {
//		if (!isfindvertex(data) || vertexList->size == 0) {
//			cout << -1 << endl;
//			return;
//		}
//
//		edge*** tmpMatrix = new edge * *[vertexList->size - 1];
//		for (int i = 0; i < vertexList->size - 1; i++) {
//			tmpMatrix[i] = new edge * [vertexList->size - 1];
//			for (int j = 0; j < vertexList->size - 1; j++) tmpMatrix[i][j] = NULL;
//		}
//		
//		int vertex_idx = findvertexidx(data);
//
//		for (int i = 0; i < vertexList->size; i++) {
//			if (edgeMatrix[vertex_idx][i] != NULL) edgeList->remove(edgeMatrix[vertex_idx][i]);
//		}
//
//		for (int i = 0; i < vertexList->size; i++) {
//			for (int j = 0; j < vertexList->size; j++) {
//				if (i < vertex_idx && j < vertex_idx) tmpMatrix[i][j] = edgeMatrix[i][j];
//				else if (i > vertex_idx && j > vertex_idx) tmpMatrix[i - 1][j - 1] = edgeMatrix[i][j];
//				else if (j > vertex_idx) tmpMatrix[i][j - 1] = edgeMatrix[i][j];
//				else if (i > vertex_idx) tmpMatrix[i - 1][j] = edgeMatrix[i][j];
//			}
//		}
//
//		edgeMatrix = tmpMatrix;
//		vertexList->remove(findvertex(data));
//
//		cout << edgeList->size << " ";
//		edge* cur = edgeList->head;
//		for (int i = 0; i < edgeList->size; i++) {
//			cout << cur->getstring() << " ";
//			cur = cur->next;
//		}
//		cout << endl;
//	}
//
//	void insertedge(int source, int destination, string str) {
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
//		edge* e = new edge(findvertex(source), findvertex(destination), str);
//		edgeMatrix[source_idx][destination_idx] = e;
//		edgeMatrix[destination_idx][source_idx] = e;
//		edgeList->insert(e);
//	}
//};
//
//int main() {
//	graph g;
//	int N, M, K;
//	cin >> N >> M >> K;
//
//	for (int i = 0; i < N; i++) {
//		int data;
//		cin >> data;
//		g.insertvertex(data);
//	}
//	
//	for (int i = 0; i < M; i++) {
//		int a, b;
//		string str;
//		cin >> a >> b >> str;
//		g.insertedge(a, b, str);
//	}
//
//	cout << g.vertexList->size << " " << g.edgeList->size << endl;
//
//	for (int i = 0; i < K; i++) {
//		int data;
//		cin >> data;
//		g.erasevertex(data);
//	}
//	return 0;
//}
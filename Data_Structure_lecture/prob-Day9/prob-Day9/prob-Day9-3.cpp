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
//	string data;
//
//	edge(vertex* source, vertex* destination, string data) {
//		prev = NULL;
//		next = NULL;
//		this->source = source;
//		this->destination = destination;
//		this->data = data;
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
//		edgeMatrix = new edge * *[1];
//		edgeMatrix[0] = new edge * [1];
//		edgeMatrix[0][0] = NULL;
//		VertexList = new DoublyVertexLinkedList();
//		EdgeList = new DoublyEdgeLinkedList();
//	}
//
//	// �Էµ� vertex �� �����ϴ��� bool type return
//	bool isfindVertex(int data) {
//		vertex* cur = VertexList->head;
//		while (cur != NULL) {
//			if (cur->data == data) return true;
//			cur = cur->next;
//		}
//		return false;
//	}
//
//	// �Էµ� vertex data�� ������ vertex return
//	vertex* findvertex(int data) {
//		vertex* cur = VertexList->head;
//		while (cur != NULL) {
//			if (cur->data == data) return cur;
//			cur = cur->next;
//		}
//	}
//
//	// �Էµ� vertex�� idx return
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
//		// ������ matrix ���� 1��ŭ �� ū matrix ����
//		edge*** tmp_Matrix = new edge * *[VertexList->size + 1];
//		for (int i = 0; i < VertexList->size + 1; i++) {
//			tmp_Matrix[i] = new edge * [VertexList->size + 1]; {
//				for (int j = 0; j < VertexList->size + 1; j++) tmp_Matrix[i][j] = NULL;
//			}
//		}
//
//		// ������ �� �������ֱ�
//		for (int i = 0; i < VertexList->size; i++) {
//			for (int j = 0; j < VertexList->size; j++) {
//				tmp_Matrix[i][j] = edgeMatrix[i][j];
//			}
//		}
//
//		// �ּ� �Ű��ֱ�
//		edgeMatrix = tmp_Matrix;
//
//		// vertexList �� ���ο� vertex�� ����
//		vertex* v = new vertex(data);
//		VertexList->insert(v);
//	}
//
//	void eraseVertex(int data) {
//		// �������� �ʴ� vertex�� �Է����� ���
//		if (isfindVertex(data) == false || VertexList->size == 0) {
//			cout << -1 << endl;
//			return;
//		}
//
//		// ������ matrix ���� 1��ŭ �� ���� matrix ����
//		edge*** tmp_Matrix = new edge * *[VertexList->size - 1];
//		for (int i = 0; i < VertexList->size - 1; i++) {
//			tmp_Matrix[i] = new edge * [VertexList->size - 1]; {
//				for (int j = 0; j < VertexList->size - 1; j++) tmp_Matrix[i][j] = NULL;
//			}
//		}
//				
//		// vertex�� ����� idxŽ��
//		int data_idx = findVertexIdx(data);
//
//		// edge matrix�� Ž���Ͽ� ���Ұ� �����Ѵٸ� ��Ī�Ǵ� ���� ��� ����
//		for (int i = 0; i < VertexList->size; i++) {
//			if (edgeMatrix[data_idx][i] != NULL) {
//				EdgeList->remove(edgeMatrix[data_idx][i]);
//			}
//		}
//
//		// ������ vertex �� ����Ͽ� matrix�� ������ �ٽ� ������ ����
//		for (int i = 0; i < VertexList->size; i++) {
//			for (int j = 0; j < VertexList->size; j++) {
//				if (i < data_idx && j < data_idx) tmp_Matrix[i][j] = edgeMatrix[i][j];
//				else if (i > data_idx && j > data_idx ) tmp_Matrix[i - 1][j - 1] = edgeMatrix[i][j];
//				else if (j > data_idx) tmp_Matrix[i][j - 1] = edgeMatrix[i][j];
//				else if (i > data_idx) tmp_Matrix[i - 1][j] = edgeMatrix[i][j];
//			}
//		}
//
//		// �ּ� �Ű��ֱ�, ���������� vertex �����ϱ�
//		edgeMatrix = tmp_Matrix;
//		VertexList->remove(findvertex(data));
//
//		// ������ �������� ��� �����ִ� vertex�� data ���� ���
//		cout << EdgeList->getEdgesize() << " ";
//		edge* cur = EdgeList->head;
//		while (cur != NULL) {
//			cout << cur->data << " ";
//			cur = cur->next;
//		}
//		cout << endl;
//	}
//
//	void insertEdge(int source, int destination, string data) {
//		// �������� �ʴ� vertex�� �Է����� ���
//		if (isfindVertex(source) == false || isfindVertex(destination) == false) {
//			cout << -1 << endl;
//			return;
//		}
//
//		// vertex�� ����� idxŽ��
//		int source_idx = findVertexIdx(source);
//		int destination_idx = findVertexIdx(destination);
//
//		// �̹� �����ϴ� edge�� �Է����� ���
//		if (edgeMatrix[source_idx][destination_idx] != NULL || edgeMatrix[destination_idx][source_idx] != NULL) {
//			cout << -1 << endl;
//			return;
//		}
//
//		// edgeList, matrix�� ���ο� edge�� ����
//		edge* e = new edge(findvertex(source), findvertex(destination), data);
//		edgeMatrix[source_idx][destination_idx] = e;
//		edgeMatrix[destination_idx][source_idx] = e;
//		EdgeList->insert(e);
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
//		int source, destination;
//		string data;
//		cin >> source >> destination >> data;
//		g.insertEdge(source, destination, data);
//	}
//
//	cout << g.VertexList->getVertexsize() << " " << g.EdgeList->getEdgesize() << endl;
//
//	for (int i = 0; i < K; i++) {
//		int data;
//		cin >> data;
//		g.eraseVertex(data);
//	}
//	return 0;
//}
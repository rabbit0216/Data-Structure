#include <iostream>
using namespace std;
#define MappingSize 501

class vertex {
public:
	vertex* prev;
	vertex* next;
	int degree;
	int data;

	vertex(int data) {
		this->data = data;
		degree = 0;
		prev = nullptr;
		next = nullptr;
	}
	void increase_degree() {
		degree++;
	}
	void decrease_degree() {
		degree--;
	}
};

class edge {
public:
	edge* prev;
	edge* next;
	vertex* source;
	vertex* destination;
	string data;
	edge(vertex* a, vertex* b, string data) {
		this->source = a;
		this->destination = b;
		this->data = data;
		prev = nullptr;
		next = nullptr;
	}
	edge() {
		this->source = new vertex(-1);
		this->destination = new vertex(-1);
		this->data = -1;
		prev = nullptr;
		next = nullptr;

	}
};

class DoublyVertexLinkedList {
public:
	vertex* header;
	vertex* trailer;
	
	DoublyVertexLinkedList() {
		header = new vertex(-1);
		trailer = new vertex(-1);
		header->next = trailer;
		trailer->prev = header;
	}
	void insert(vertex* x) {
		x->prev = trailer->prev;
		trailer->prev->next = x;

		trailer->prev = x;
		x->next = trailer;
	}
	void remove(vertex* x) {
		vertex* p = x->prev;
		vertex* n = x->next;
		p->next = n;
		n->prev = p;
		delete x;
	}
};

class DoublyEdgeLinkedList {
public:
	edge* header;
	edge* trailer;

	DoublyEdgeLinkedList() {
		header = new edge();
		trailer = new edge();
		header->next = trailer;
		trailer->prev = header;
	}
	void insert(edge* x) {
		x->prev = trailer->prev;
		trailer->prev->next = x;

		trailer->prev = x;
		x->next = trailer;
	}
	void remove(edge* x) {
		edge* p = x->prev;
		edge* n = x->next;
		p->next = n;
		n->prev = p;
		delete x;
	}
};

class graph {
public:
	edge*** edgeMatrix;
	DoublyEdgeLinkedList* eList;
	DoublyVertexLinkedList* vList;
	int vertexSize;
	int edgeSize;
	int mappingTable[MappingSize];

	graph() {
		this->vList = new DoublyVertexLinkedList();
		this->eList = new DoublyEdgeLinkedList();
		this->vertexSize = 0;
		this->edgeSize = 0;
		for (int i = 0;i < MappingSize;i++)
			mappingTable[i] = 1;
		this->edgeMatrix = new edge * *[1];
		this->edgeMatrix[0] = new edge * [1];
		this->edgeMatrix[0][0] = nullptr;
	}
	bool isfindVertex(int n) {
		bool flag = false;
		
		vertex* tmp = vList->header->next;
		while (tmp != nullptr) {
			if (tmp->data == n) {
				flag = true;
				return flag;
			}
			tmp = tmp->next;
		}
		return flag;
	}
	vertex* findVertex(int n) {
		vertex* tmp = vList->header->next;
		while (tmp != nullptr) {
			if (tmp->data == n) 
				break;
			tmp = tmp->next;
		}
		return tmp;
	}
	void insert_vertex(int n) {
		if (isfindVertex(n) == true) {
			return;
		}
		else { 
			edge*** tmpMatrix = new edge * *[vertexSize + 1];
			for (int i = 0;i < vertexSize + 1;i++) { //tmpMatrix 초기화
				tmpMatrix[i] = new edge * [vertexSize + 1];
				for (int j = 0;j < vertexSize + 1;j++)
					tmpMatrix[i][j] = nullptr;
			}
			for (int i = 0;i < vertexSize;i++) {
				for (int j = 0;j < vertexSize;j++)
					tmpMatrix[i][j] = this->edgeMatrix[i][j]; //copy
			}
			this->edgeMatrix = tmpMatrix;

			vertex* newVertex = new vertex(n);
			vList->insert(newVertex);
			this->vertexSize++;
			mappingTable[vertexSize - 1] = n; //mappingTable에 해당 vertex의 matrix 인덱스 저장
		}
	}
	void insert_edge(int s, int d, string data) {
		if (isfindVertex(s) == false || isfindVertex(d) == false) {
			cout << -1 << endl;
			return;
		}
		
		int destination = -1;
		int source = -1;
		for (int i = 0;i <= vertexSize;i++) {
			if (mappingTable[i] == s) source = i;
			if (mappingTable[i] == d) destination = i;
			if (source != -1 && destination != -1) break;
		}

		if (edgeMatrix[source][destination] != nullptr ||
			edgeMatrix[destination][source] != nullptr) {
			cout << -1 << endl; // 이미 간선 존재
			return;
		}
		edge* newEdge = new edge(findVertex(s), findVertex(d), data);
		edgeMatrix[source][destination] = newEdge;
		edgeMatrix[destination][source] = newEdge;

		findVertex(s)->increase_degree();
		findVertex(d)->increase_degree();
		eList->insert(newEdge);
		this->edgeSize++;
	}

	void printVertexEdgeSize() {
		cout << this->vertexSize << ' ' << this->edgeSize << endl;
	}
};

int main() {
	int n, m;
	int x;
	int s, d;
	graph g;
	cin >> n >> m;
	for (int i = 0;i < n;i++) {
		cin >> x;
		g.insert_vertex(x);
	}
	for (int i = 0;i < m;i++) {
		cin >> s >> d;
		g.insert_edge(s, d, "1");
	}
	g.printVertexEdgeSize();

	return 0;
}

/*
5 9
5 20 952 1 45
5 20
5 952
20 952
952 5
20 1
20 45
20 478
45 1
1 45

*/
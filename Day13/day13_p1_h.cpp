#include <iostream>
using namespace std;
#define MappingSize 501

class vertex {
public:
	vertex* prev;
	vertex* next;
	int data;
	int degree;

	vertex(int data) {
		this->data = data;
		this->prev = nullptr;
		this->next = nullptr;
		this->degree = 0;
	}
	vertex() {
		this->data = -1;
		this->prev = nullptr;
		this->next = nullptr;
		this->degree = 0;
	}

	void increaseDegree() {
		degree++;
	}
	void edcreaseDegree() {
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

	edge(vertex* s, vertex* d, string data) {
		this->prev = nullptr;
		this->next = nullptr;
		this->source = s;
		this->destination = d;
		this->data = data;
	}
	edge() {
		this->prev = nullptr;
		this->next = nullptr;
		this->source = new vertex();
		this->destination = new vertex();
		this->data = "-1";
	}
};

class vertexList {
public:
	vertex* header;
	vertex* trailer;

	vertexList() {
		this->header = new vertex();
		this->trailer = new vertex();
		header->next = trailer;
		trailer->prev = header;
	}

	void insert(vertex* x) {
		x->next = trailer;
		trailer->prev->next = x;
		x->prev = trailer->prev;
		trailer->prev = x;
	}

	void remove(vertex* v) {
		vertex* p = v->prev;
		vertex* n = v->next;

		p->next = n;
		n->prev = p;
		delete v;
	}
};

class edgeList {
public:
	edge* header;
	edge* trailer;

	edgeList() {
		this->header = new edge();
		this->trailer = new edge();
		header->next = trailer;
		trailer->prev = header;
	}

	void insert(edge* x) {
		x->prev = trailer->prev;
		x->next = trailer;
		trailer->prev->next = x;
		trailer->prev = x;
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
	edge*** matrix;
	vertexList* vlist;
	edgeList* elist;
	int vSize;
	int eSize;
	int mappingTable[MappingSize];

	graph() {
		this->vlist = new vertexList();
		this->elist = new edgeList();
		this->vSize = 0;
		this->eSize = 0;
		for (int i = 0;i < MappingSize;i++) {
			mappingTable[i] = 1;
		}
		this->matrix = new edge * *[1];
		this->matrix[0] = new edge * [1];
		this->matrix[0][0] = nullptr;
	}
	bool isfindVertex(int n) {
		bool flag = false;
		vertex* tmp = vlist->header->next;
		while (tmp != nullptr) {
			if (tmp->data == n) {
				flag = true;
				break;
			}
			tmp = tmp->next;
		}
		return flag;
	}
	vertex* findVertex(int n) {
		vertex* tmp = vlist->header->next;
		while (tmp != nullptr) {
			if (tmp->data == n)
				break;
			tmp = tmp->next;
		} 
		return tmp;
	}
	void insertV(int n) {
		if (isfindVertex(n) == true)
			return;
		else {
			edge*** tmp = new edge * *[vSize + 1];
			for (int i = 0;i < vSize + 1;i++) {
				tmp[i] = new edge * [vSize + 1];
				for (int j = 0;j < vSize + 1;j++)
					tmp[i][j] = nullptr;
			}
			for (int i = 0;i < vSize;i++) {
				for (int j = 0;j < vSize;j++) {
					tmp[i][j] = matrix[i][j];
				}
			}
			this->matrix = tmp;

			vertex* newVertex = new vertex(n);
			vlist->insert(newVertex);
			this->vSize++;
			mappingTable[vSize - 1] = n;
		}
	}
	void insertE(int s, int d, string data) {
		if (isfindVertex(s) == false || isfindVertex(d) == false) {
			cout << -1 << endl;
			return;
		}

		int destin = -1;
		int source = -1;
		for (int i = 0;i <= vSize;i++) {
			if (mappingTable[i] == s) source = i;
			if (mappingTable[i] == d) destin = i;
			if (source != -1 && destin != -1) break;
		}

		if (matrix[source][destin] != nullptr ||
			matrix[destin][source] != nullptr) {
			cout << -1 << endl;
			return;
		}
		
		edge* newEdge = new edge(findVertex(s), findVertex(d), data);
		matrix[source][destin] = newEdge;
		matrix[destin][source] = newEdge;
		findVertex(s)->increaseDegree();
		findVertex(d)->increaseDegree();
		elist->insert(newEdge);
		this->eSize++;
	}
	void printSize() {
		cout << vSize << ' ' << eSize << endl;
	}
	void isAdjacent(int v1, int v2) {
		if (isfindVertex(v1) == false || isfindVertex(v2) == false) {
			cout << -1 << endl;
			return;
		}
		else {
			int source = -1;
			int destin = -1;
			for (int i = 0;i <= vSize;i++) {
				if (mappingTable[i] == v1) source = i;
				if (mappingTable[i] == v2) destin = i;
				if (source != -1 && destin != -1) break;
			}

			if (matrix[source][destin] != nullptr ||
				matrix[destin][source] != nullptr) {
				cout << 1 << endl;
				return;
			}
			else {
				cout << 0 << endl;
				return;
			}
		}
	}
};

int main() {
	int n, m, k, x, s, d;
	cin >> n >> m >> k;
	graph g;
	for (int i = 0;i < n;i++) {
		cin >> x;
		g.insertV(x);
	}
	for (int i = 0;i < m;i++) {
		cin >> s >> d;
		g.insertE(s, d, "");
	}
	g.printSize();
	for (int i = 0;i < k;i++) {
		cin >> s >> d;
		g.isAdjacent(s, d);
	}
	return 0;
}

/*
5 9 3
5 20 952 1 45
5 20
5 952
20 952
952 5
20 1
20 45
20 5
45 1
1 45
20 500 
45 1
5 45

*/
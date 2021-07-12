#include <iostream>
using namespace std;
#define MappingSize 501
class vertex {
public:
	vertex* prev;
	vertex* next;
	int degree;
	int data;

	vertex() {
		prev = nullptr;
		next = nullptr;
		degree = 0;
		data = -1;
	}

	vertex(int data) {
		prev = nullptr;
		next = nullptr;
		degree = 0;
		this->data = data;
	}

	void increaseDegree() {
		degree++;
	}
	void decreaseDegree() {
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

	edge() {
		prev = nullptr;
		next = nullptr;
		source = new vertex();
		destination = new vertex();
		data = "";
	}
	edge(vertex* s, vertex* d, string data) {
		prev = nullptr;
		next = nullptr;
		source = s;
		destination = d;
		this->data = data;
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

	void insert(vertex* v) {
		v->prev = trailer->prev;
		v->next = trailer;
		trailer->prev->next = v;
		trailer->prev = v;
	}

	void remove(vertex* v) {
		vertex* p = v->prev;
		vertex* n = v->next;
		p->next = n;
		n->prev = p;
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

	void insert(edge* e) {
		e->next = trailer;
		e->prev = trailer->prev;
		trailer->prev->next = e;
		trailer->prev = e;
	}

	void remove(edge* e) {
		edge* p = e->prev;
		edge* n = e->next;
		p->next = n;
		n->prev = p;
	}
};

class graph {
public:
	edge*** edgeMatrix;
	vertexList* vlist;
	edgeList* elist;
	int esize;
	int vsize;
	int mappingTable[MappingSize];

	graph() {
		vlist = new vertexList();
		elist = new edgeList();
		esize = 0;
		vsize = 0;
		for (int i = 0;i < MappingSize;i++) {
			mappingTable[i] = 1;
		}
		edgeMatrix = new edge * *[1];
		edgeMatrix[0] = new edge * [1];
		edgeMatrix[0][0] = nullptr;
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
			edge*** tmp = new edge * *[vsize + 1];
			for (int i = 0;i < vsize + 1;i++) {
				tmp[i] = new edge * [vsize + 1];
				for (int j = 0;j < vsize + 1;j++)
					tmp[i][j] = nullptr;
			}
			for (int i = 0;i < vsize;i++) {
				for (int j = 0;j < vsize;j++)
					tmp[i][j] = edgeMatrix[i][j];
			}
			this->edgeMatrix = tmp;
			vertex* newVertex = new vertex(n);
			vlist->insert(newVertex);
			vsize++;
			mappingTable[vsize - 1] = n;
		}
	}
	void insertE(int s, int d, string data) {
		if (isfindVertex(s) == false || isfindVertex(d) == false) {
			cout << -1 << endl;
			return;
		}

		int source = -1;
		int destin = -1;
		for (int i = 0;i <= vsize;i++) {
			if (mappingTable[i] == s) source = i;
			if (mappingTable[i] == d) destin = i;
			if (source != -1 && destin != -1) break;
		}

		if (edgeMatrix[source][destin] != nullptr ||
			edgeMatrix[destin][source] != nullptr) {
			cout << -1 << endl;
			return;
		}

		edge* newEdge = new edge(findVertex(s), findVertex(d), data);
		elist->insert(newEdge);
		esize++;
		findVertex(s)->increaseDegree();
		findVertex(d)->increaseDegree();
		edgeMatrix[source][destin] = newEdge;
		edgeMatrix[destin][source] = newEdge;
	}

	void eraseV(int n) {
		if (isfindVertex(n) == false || vsize == 0) {
			cout << -1 << endl;
		}
		else {
			edge*** tmp = new edge * *[vsize - 1];
			for (int i = 0;i < vsize - 1;i++) {
				tmp[i] = new edge * [vsize - 1];
				for (int j = 0;j < vsize - 1;j++)
					tmp[i][j] = nullptr;
			}
			int idx = 0;
			for (int i = 0;i < vsize;i++) {
				if (mappingTable[i] == n) {
					idx = i;
					break;
				}
			}
			for (int i = idx;i < vsize;i++) {
				mappingTable[i] = mappingTable[i + 1]; //shift
			}
			for (int i = 0;i < vsize;i++) {
				if (this->edgeMatrix[idx][i] != nullptr) {
					elist->remove(this->edgeMatrix[idx][i]);
					esize--;
				}
			}
			for (int i = 0;i < vsize;i++) {
				for (int j = 0;j < vsize;j++) {
					if (i < idx && j < idx)
						tmp[i][j] = this->edgeMatrix[i][j];
					else if (i > idx && j > idx)
						tmp[i - 1][j - 1] = this->edgeMatrix[i][j];
					else if (j > idx)
						tmp[i][j - 1] = this->edgeMatrix[i][j];
					else if (i > idx)
						tmp[i - 1][j] = this->edgeMatrix[i][j];
				}
			}
			this->edgeMatrix = tmp;
			vlist->remove(findVertex(n));
			this->vsize--;
			
			cout << esize << ' ';
			edge* cur = elist->header->next;
			while (cur != nullptr) {
				cout << cur->data << ' ';
				cur = cur->next;
			}
			cout << '\n';
		}
	}
	void printSize() {
		cout << vsize << ' ' << esize << endl;
	}
};

int main() {
	int n, m, k;
	int x, s, d;
	string data;
	graph g;
	cin >> n >> m >> k;
	for (int i = 0;i < n;i++) {
		cin >> x;
		g.insertV(x);
	}
	for (int i = 0;i < m;i++) {
		cin >> s >> d >> data;
		g.insertE(s, d, data);
	}
	g.printSize();
	for (int i = 0;i < k;i++) {
		cin >> x;
		g.eraseV(x);
	}
	return 0;
}

/*
5 8 4
5 20 952 1 45
5 20 Cheat
20 952 Do
952 1 You
20 5 Love
20 1 To
952 45 Like
5 45 I
45 1 What
6
20
1
20


*/
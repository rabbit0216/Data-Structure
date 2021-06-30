#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
	int data;
	Node* parent;
	vector<Node*> child;

	Node() {
		this->data = NULL;
		this->parent = nullptr;
	}
	Node(int data) {
		this->data = data;
		this->parent = nullptr;
	}

	void insert(Node* p, Node* c) {
		p->child.push_back(c);
		c->parent = p;
	}

	void printChild(Node* p) {
		for (auto i : p->child) {
			cout << i->data << ' ';
		}
		cout << '\n';
	}
};

class gTree {
private:
	Node* root;
	vector<Node*> node_list; //모든 노드
public:
	gTree() {
		this->root = nullptr;
	}
	gTree(int data) {
		this->root = new Node(data);
		node_list.push_back(root);
	}
	void setRoot(int data) {
		root = new Node(data);
		node_list.push_back(root);
	}
	Node* getRoot() {
		return root;
	}
	void insertNode(int p, int c) {
		Node* newNode = new Node(c);
		node_list.push_back(newNode);
		for (auto i : node_list) {
			if (i->data == p) {
				i->insert(i, newNode);
			}
		}
	}
	void printChild(int p) {
		for (auto i : node_list) {
			if (i->data == p) {
				i->printChild(i);
			}
		}
	}
};

int main() {
	gTree gt(1);
	int n;
	cin >> n;

	for (int i = 0;i < n;i++) {
		string menu;
		cin >> menu;
		int p, c;
		if (menu == "insert") {
			cin >> p >> c;
			gt.insertNode(p, c);
		}
		else if (menu == "printChild") {
			cin >> p;
			gt.printChild(p);
		}
	}
	return 0;
}

/*
6
insert 1 3
insert 1 5
insert 1 6
insert 5 2
insert 1 7
printChild 1
*/
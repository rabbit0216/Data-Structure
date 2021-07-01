#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Node {
public:
	int data;
	Node* parent;
	vector<Node*> child;

	Node(int data) {
		this->data = data;
		this->parent = nullptr;
	}

	void insert(Node* c) {
		this->child.push_back(c);
		c->parent = this;
	}

};

class gTree {
public:
	Node* root;
	vector<Node*> node_list;

	gTree(int data) {
		this->root = new Node(data);
		this->node_list.push_back(root);
	}

	void insertChild(int p, int c) {
		Node* newNode = new Node(c);
		for (auto i : node_list) {
			if (i->data == p) {
				i->insert(newNode);
				node_list.push_back(newNode);
				return;
			}
		}
	}
	
	void preOrder(Node* x) {
		for (auto i : node_list) {
			if (i == x) {
				cout << i->data << ' ';
				break;
			}
		}
		for (auto i : x->child) {
			preOrder(i);
		}
	}

	void postOrder(Node* x) {
		for (auto i : x->child) {
			postOrder(i);
		}
		cout << x->data << ' ';
	}
};

int main() {
	int n;
	cin >> n;

	for (int i = 0;i < n;i++) {
		gTree gt(1);
		int m;
		cin >> m;
		for (int j = 0;j < m;j++) {
			int p, c;
			cin >> p >> c;
			gt.insertChild(p, c);
		}
		gt.preOrder(gt.root);
		cout << '\n';
		gt.postOrder(gt.root);
		cout << '\n';
	}
	return 0;
}

/*
2
9
1 2
1 3
1 4
2 5
3 6
3 7
6 8
6 9
6 10
2
1 2
1 3
*/
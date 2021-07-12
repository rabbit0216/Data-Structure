#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* p;
	Node* l;
	Node* r;

	Node(int data) {
		this->data = data;
		p = nullptr;
		l = nullptr;
		r = nullptr;
	}

	void insertL(Node* left) {
		left->p = this;
		this->l = left;
	}

	void insertR(Node* right) {
		right->p = this;
		this->r = right;
	}

	int degree(Node* x) {
		int deg = 0;
		if (x->l != nullptr)
			deg++;
		if (x->r != nullptr)
			deg++;
		return deg;
	}
	
	int depth(Node* x) {
		int dep = 0;
		Node* tmp = x;
		while (tmp->p != nullptr) {
			tmp = tmp->p;
			dep++;
		}
		return dep;
	}
};

class BST {
public:
	Node* root;

	BST() {
		root = nullptr;
	}
	~BST() {
		destroy(this->root);
	}
	void destroy(Node* root) {
		if (root == nullptr)
			return;
		if (root->l != nullptr)
			destroy(root->l);
		if (root->r != nullptr)
			destroy(root->r);
		delete root;
	}

	void insert(int data) {
		Node* newNode = new Node(data);
		Node* tmp = root;
		if (root == nullptr)
			root = newNode;
		else {
			while (tmp != nullptr) {
				if (tmp->data == data)
					return;
				else {
					if (tmp->data < data) { // ¿À¸¥ÂÊ
						if (tmp->r == nullptr) {
							tmp->insertR(newNode);
							break;
						}
						tmp = tmp->r;
					}
					else {
						if (tmp->l == nullptr) {
							tmp->insertL(newNode);
							break;
						}
						tmp = tmp->l;
					}
				}
			}
		}
	}

	Node* find(int data) {
		Node* tmp = root;
		while (tmp != nullptr) {
			if (tmp->data == data)
				return tmp;
			else {
				if (tmp->data < data)
					tmp = tmp->r;
				else 
					tmp = tmp->l;
			}
		}
		return nullptr;
	}

	void print(int data) {
		Node* x = find(data);
		if (x == nullptr)
			cout << 0 << '\n';
		else {
			cout << x->degree(x) << ' ' << x->depth(x) << '\n';
		}
	}
};

int main() {
	int t;
	cin >> t;
	for (int i = 0;i < t;i++) {
		BST tree;
		int n, m;
		int x;

		cin >> n;
		for (int j = 0;j < n;j++) {
			cin >> x;
			tree.insert(x);
		}
		cin >> m;
		for (int j = 0;j < m;j++) {
			cin >> x;
			tree.print(x);
		}
	}
	return 0;
}
#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
	int data;
	Node* p;
	Node* left;
	Node* right;

	Node(int data) {
		this->data = data;
		p = nullptr;
		left = nullptr;
		right = nullptr;
	}

	void insertLeft(Node* left) {
		this->left = left;
		left->p = this;
	}
	void insertRight(Node* right) {
		this->right = right;
		right->p = this;
	}
	int height(Node* x) {
		if (x == nullptr)
			return 0;
		else {
			int l = height(x->left);
			int r = height(x->right);

			if (l > r)
				return l + 1;
			else
				return r + 1;
		}
	}
};

class BST {
public:
	Node* root;
	int height;

	BST() {
		root = nullptr;
		height = 0;
	}
	~BST() {
		treeDestructor(this->root);
	}

	void insertNode(int data) {
		Node* newNode = new Node(data);
		if (root == nullptr) {
			root = newNode;
		}
		else {
			Node* tmp = root;
			Node* p = tmp->p;
			while (tmp != nullptr) {
				if (tmp->data == data)
					return;
				else {
					if (tmp->data < data) {
						if (tmp->right == nullptr) {
							p = tmp;
							if (p->data < data)
								p->insertRight(newNode);
							else
								p->insertLeft(newNode);
							break;
						}
						tmp = tmp->right;
					}
					else {
						if (tmp->left == nullptr) {
							p = tmp;
							if (p->data < data)
								p->insertRight(newNode);
							else
								p->insertLeft(newNode);
							break;
						}
						tmp = tmp->left;
					}
					
				}
			}
		}
	}

	void printHeight() {
		cout << root->height(root) - 1 << endl;
	}

	void treeDestructor(Node* root) {
		if (root == nullptr)
			return;
		if (root->left != nullptr)
			treeDestructor(root->left);
		if (root->right != nullptr)
			treeDestructor(root->right);
		delete root;
	}
};


int main() {
	int t;
	cin >> t;
	for (int i = 0;i < t;i++) {
		int n;
		cin >> n;
		BST bst;
		for (int j = 0;j < n;j++) {
			int x;
			cin >> x;
			bst.insertNode(x);
		}
		bst.printHeight();
	}
	return 0;
}


/*
3 
7 
4 2 6 1 3 5 7
7
7 6 5 4 3 2 1
4 
1 2 3 4
*/
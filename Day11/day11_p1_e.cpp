#include <iostream>
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

	void printDegree(Node* x) {
		int degree = 0;
		if (x->left != nullptr)
			degree++;
		if (x->right != nullptr)
			degree++;

		cout << degree;
	}

	void printDepth(Node* x) {
		Node* tmp = x;
		int depth = 0;
		while (tmp->p != nullptr) {
			tmp = tmp->p;
			depth++;
		}
		cout << depth;
	}
};

class Bst {
public:
	Node* root;
	int height;

	Bst() {
		root = nullptr;
		height = 0;
	}
	~Bst() {
		treeDestructor(this->root);
	}
	void treeDestructor(Node* root) {
		if (root == nullptr)
			return;
		if (root->left != nullptr)
			treeDestructor(root->left);
		if (root->right != nullptr)
			treeDestructor(root->right);
		delete(root);
	}

	void insertNode(int data) {
		Node* newNode = new Node(data);
		if (root == nullptr) {
			root = newNode;
		}
		else {
			Node* tmp = root;
			Node* p = root;
			while (tmp != nullptr) { 
				if (tmp->data == data)
					return;
				else {
					if (tmp->data < data) { //Ž������ ����� ���� ������ ��庸�� ���� ��� ������ �ڽ� nullptr ���������� Ž�� �� ����
						if (tmp->right == nullptr) { //nullptr �������
							p = tmp;
							if (p->data < data)  //������ ����� �θ� ��� ���� ���� ��� ������ ���� ��� ������ �ڽ����� ����
								p->insertRight(newNode);
							else				//������ ����� �θ� ��� ���� ���� ��� ������ ũ�ų� ���� ��� ���� �ڽ����� ����
								p->insertLeft(newNode);
							break;
						}
						tmp = tmp->right;
					}
					else { //Ž������ ����� ���� ������ ��庸�� ���� ��� ���� �ڽ� nullptr ���������� Ž�� �� ����
						if (tmp->left == nullptr) { //nullptr �������
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
		height += 1;
	}

	Node* findNode(int data) {
		Node* tmp = root;
		while (tmp != nullptr) {
			if (tmp->data == data)
				return tmp;
			else {
				if (tmp->data < data)
					tmp = tmp->right;
				else
					tmp = tmp->left;
			}
		}
		return nullptr;
	}

	void printFind(int data) {
		if (findNode(data) == nullptr)
			cout << "0" << endl;
		else {
			Node* x = findNode(data);
			x->printDegree(x);
			cout << ' ';
			x->printDepth(x);
			cout << '\n';
		}
	}
};

int main() {
	int t;
	cin >> t;
	
	for (int i = 0;i < t;i++) {
		int n, m;
		int x;
		cin >> n;
		Bst bst;
		for (int j = 0;j < n;j++) {
			cin >> x;
			bst.insertNode(x);
		}
		cin >> m;
		for (int j = 0;j < m;j++) {
			cin >> x;
			bst.printFind(x);
		}
	}
	return 0;
}

/*
2 
7
15 10 5 12 11 14 17
3 
12 10 20 
6 
92 80 24 18 38 87
6 
24 87 92 18 80 38
*/
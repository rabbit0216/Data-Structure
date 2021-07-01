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

	void insertChild(Node* child) {
		this->child.push_back(child);
		child->parent = this; //������ �ڽĳ���� �θ��� ���� ���� ����
	}

	void delChild(Node* child) {
		int size = this->child.size();
		for (int i = 0;i < size;i++) {
			if (this->child[i] == child) {
				this->child.erase(this->child.begin() + i);
			}
		}
	}

	
	int Depth(Node* x) { 
		Node* tmp = x;
		int pCnt = 0;
		while (tmp->parent != nullptr) { //�θ��尡 null�� �� ���� (root)
			pCnt++;
			tmp = tmp->parent;
		}
		return pCnt;
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
	
	void setRoot(int data) {
		this->root->data = data;
		node_list.push_back(root);
	}

	void insert(int p, int c) {
		Node* newNode = new Node(c);
		for (auto i : node_list) {
			if (i->data == p) {
				i->insertChild(newNode);
				node_list.push_back(newNode);
				return;
			}
		}
		cout << "-1" << endl;
	}

	void printChild(int p) {
		for (auto i : node_list) {
			if (i->data == p) { //�Է¹��� �θ���� ��ġ�ϴ� ��尡 ���� ���
				if (i->child.size() == 0) { //�ڽĳ�尡 ���� ���
					cout << "0" << endl;
					return;
				}
				else {
					for (auto j : i->child)
						cout << j->data << ' ';
					cout << '\n';
					return;
				}
			}
		}
		cout << "-1" << endl;
	}

	void printParent(int c) {
		for (auto i : node_list) {
			if (i->data == c) {
				cout << i->parent->data << endl;
				return;
			}
		}
		cout << "-1" << endl;
	}

	void printDepth(int x) {
		int depth;
		for (auto i : node_list) {
			if (i->data == x) {
				depth = i->Depth(i);
				cout << depth << endl;
				return;
			}
		}
		cout << "-1" << endl;
	}

};

int main() {
	gTree gt(1);
	string menu;
	int n;
	cin >> n;

	for (int i = 0;i < n;i++) {
		cin >> menu;
		int p, c, x;
		if (menu == "insert") {
			cin >> p >> c;
			gt.insert(p, c);
		}
		else if (menu == "printChild") {
			cin >> p;
			gt.printChild(p);
		}
		else if (menu == "printParent") {
			cin >> c;
			gt.printParent(c);
		}
		else if (menu == "printDepth") {
			cin >> x;
			gt.printDepth(x);
		}
	}
	return 0;
}

/*
9
insert 1 3
insert 1 5
insert 1 6
insert 5 2
insert 1 7
insert 2 9
printChild 1
printDepth 1
printDepth 9

*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Node {
public:
	int data;
	Node* parent;
	vector<Node*> child;
	int pCnt;

	Node(int data) {
		this->data = data;
		this->parent = nullptr;
		this->pCnt = 0;
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
	vector<Node*> parent_list;

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

	int treeHeight(Node* x) {
		int max = root->pCnt;
		for (auto i : parent_list) {
			Node* tmp = i;
			while (tmp->parent != nullptr) {
				i->pCnt++; //�θ��� ���� ī��Ʈ
				tmp = tmp->parent;
				/*
				*Worng answer : tmp->pCnt++ �̾���
				*tmp�� �θ���� Ÿ�� Ÿ�� �ö󰡴� �������� ���� ī��Ʈ���� �����Ű�°� �ƴ϶�
				*��� ���� ī��Ʈ �� ����� "i"�� ī��Ʈ���� �������Ѿ� ��
				*/
			}
		}
		for (auto i : parent_list) {
			if (i->pCnt > max) //�θ��� ���� ���� ���� ����� ī��Ʈ���� max�� ����
				max = i->pCnt;
		}
		
		if (node_list.size() == 1) { //��Ʈ��常 ���� �� ���
			max = 0;
			return max;
		}
		
		return max + 1;
	}

	void parentNode() {
		for (auto i : node_list) {
			if (i->child.size() != 0)
				this->parent_list.push_back(i);
		}
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
		gt.parentNode();
		cout << gt.treeHeight(gt.root) << endl;
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
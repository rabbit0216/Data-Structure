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
				i->pCnt++; //부모노드 개수 카운트
				tmp = tmp->parent;
				/*
				*Worng answer : tmp->pCnt++ 이었음
				*tmp는 부모노드로 타고 타고 올라가는 변수여서 얘의 카운트값을 변경시키는게 아니라
				*노드 개수 카운트 할 노드인 "i"의 카운트값을 증가시켜야 함
				*/
			}
		}
		for (auto i : parent_list) {
			if (i->pCnt > max) //부모노드 개수 가장 많은 노드의 카운트값을 max로 설정
				max = i->pCnt;
		}
		
		if (node_list.size() == 1) { //루트노드만 존재 할 경우
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
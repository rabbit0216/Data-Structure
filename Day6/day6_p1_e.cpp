#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int data;
	Node* next;

	Node(int x) {
		this->data = x;
		this->next = nullptr;
	}
};

class slList {
public:
	Node* head;
	Node* tail;

	slList() {
		this->head = nullptr;
		this->tail = nullptr;
	}

	void addBack(int x) {
		Node* newNode = new Node(x);
		if (head == nullptr) {
			head = tail = newNode;
		}
		else {
			tail->next = newNode;
			tail = newNode;
		}
	}

};

class lQueue {
public:
	slList* q;
	int n;

	lQueue() {
		this->q = new slList();
		this->n = 0;
	}

	void enqueue(int x, int capacity) {
		if (n == capacity) {
			cout << "Full" << endl;
		}
		else {
			q->addBack(x);
			n += 1;
		}
	
	}
	int size() {
		return n;
	}
	bool isEmpty() {
		if (n == 0)
			return true;
		else
			return false;
	}
};

int main() {
	lQueue lq;
	int s, n, x;
	cin >> s;
	cin >> n;

	for (int i = 0;i < n;i++) {
		string menu;
		cin >> menu;

		if (menu == "enqueue") {
			cin >> x;
			lq.enqueue(x, s);
		}
		else if (menu == "isEmpty") {
			cout << lq.isEmpty() << endl;
		}
		else if (menu == "size") {
			cout << lq.size() << endl;
		}

	}
	return 0;
}

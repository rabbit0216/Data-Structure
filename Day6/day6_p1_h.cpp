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

	void rmFront() {
		if (head == nullptr) {
			cout << "Empty" << endl;
		}
		else {
			Node* tmp = head;
			int tmpData = tmp->data;
			cout << tmpData << endl;
			head = head->next;
			delete tmp;
		}
	}

	void front() {
		if (head == nullptr) {
			cout << "Empty" << endl;
		}
		else {
			cout << head->data << endl;
		}
	}

	void rear() {
		if (head == nullptr) {
			cout << "Empty" << endl;
		}
		else {
			cout << tail->data << endl;
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

	void dequeue() {
		if (n == 0) {
			q->rmFront();
		}
		else {
			n -= 1;
			q->rmFront();
		}
	}

	void front() {
		q->front();
	}
	void rear() {
		q->rear();
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
		else if (menu == "dequeue") {
			lq.dequeue();
		}
		else if (menu == "front") {
			lq.front();
		}
		else if (menu == "rear") {
			lq.rear();
		}
	}
	return 0;
}

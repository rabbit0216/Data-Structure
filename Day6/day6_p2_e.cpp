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
	Node* f;
	Node* r;

	slList() {
		this->f = nullptr;
		this->r = nullptr;
	}

	void addBack(int x) {
		Node* newNode = new Node(x);
		if (f == nullptr) {
			f = r = newNode;
		}
		else {
			r->next = newNode;
			r = newNode;
		}
	}

	int rmFront() {
		Node* tmp = f;
		tmp = f->next;
		int rmData = f->data;
		delete f;
		f = tmp;
		return rmData;
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

	void enqueue(int x) {
		q->addBack(x);
		n += 1;
	}

	int dequeue() {
		n -= 1;
		return q->rmFront();
	}

	bool isEmpty() {
		if (n == 0)
			return true;
		else
			return false;
	}

	int size() {
		return n;
	}
};

int compare(lQueue p1, lQueue p2) { //p1 p2 승률 계산
	int x, y;
	int xCnt = 0, yCnt = 0;
	int size = p1.size();
	for (int i = 0; i < size;i++) {
		x = p1.dequeue();
		y = p2.dequeue();

		if (x > y) {
			xCnt++;
		}
		else if (x < y) {
			yCnt++;
		}
	}
	/*
	while (!p1.isEmpty() && !p2.isEmpty()) { //큐에 원소 남아있지않을 때 까지
		x = p1.dequeue();
		y = p2.dequeue();

		if (x > y) {
			xCnt++;
		}
		else if (x < y) {
			yCnt++;
		}
	}
	*/
	if (xCnt > yCnt) { //p1이 이긴경우
		return 1;
	}
	else if (xCnt < yCnt) { //p2가 이긴경우
		return 2;
	}
	else { //비긴경우
		return 0;
	}
}

int main() {
	int t;
	cin >> t;
	for (int i = 0;i < t;i++) {
		lQueue p1, p2;
		int n;
		int stamina;
		cin >> n;
		for (int k = 0;k < n;k++) {
			cin >> stamina;
			p1.enqueue(stamina);
		}
		for (int j = 0;j < n;j++) {
			cin >> stamina;
			p2.enqueue(stamina);
		}

		cout << compare(p1, p2) << endl;
		delete p1.q;
		delete p2.q;
	}
	return 0;
}

/*
2
6
12 11 7 5 3 1
10 9 8 6 4 2
3
4 3 2
3 2 1

*/
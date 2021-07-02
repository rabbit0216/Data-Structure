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
	~Node() {
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

	~slList() {

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
		int tmpData = tmp->data;
		f = f->next;
		delete tmp;
		return tmpData;
	}

	void setFront(int x) {
		f->data = x;
	}

	int front() {
		return f->data;
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

	~lQueue() {
	}

	void enqueue(int x) {
		q->addBack(x);
		n += 1;
	}

	int dequeue() {
		n -= 1;
		int data = q->rmFront();
		return data;
	}

	bool isEmpty() {
		if (n == 0)
			return true;
		else
			return false;
	}

	void setFront(int x) {
		q->setFront(x);
	}

	int front() {
		return q->front();
	}

	int size() {
		return n;
	}
};

int compare(lQueue p1, lQueue p2) { //p1 p2 승률 계산
	int x, y;
	int xCnt = 0, yCnt = 0;
	int rem;
	while (!p1.isEmpty() && !p2.isEmpty()) { //큐에 원소 남아있지않을 때 까지
		x = p1.dequeue();
		y = p2.dequeue();

		if (x > y) {
			if (p1.size() == 0 && p2.size() == 0) {
				xCnt++;
			}
			else {
				rem = x - y - 1;
				xCnt++;
				x = p1.front();
				x += rem;
				p1.setFront(x);
			}
		}
		else if (x < y) {
			if (p1.size() == 0 && p2.size() == 0) {
				yCnt++;
			}
			else {
				rem = y - x - 1;
				yCnt++;
				y = p2.front();
				y += rem;
				p2.setFront(y);
			}
		}
	} 
	
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

		/*소멸자 통해서 delete 시켜주면 자꾸
		Invalid address specified to RtlValidateHeap
		오류 떴음 해당 오류는 내부에서 지정한 메모리를 외부에서 풀려고 하면 발생
		*/
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
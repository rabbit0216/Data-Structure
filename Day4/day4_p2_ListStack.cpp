#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int data;
	Node* next;

	Node(int X) {
		this->data = X;
		this->next = nullptr;
	}
};

class SLinkedList {
public:
	Node* head;
	Node* tail;

	SLinkedList() {
		this->head = nullptr;
		this->tail = nullptr;
	}

	int front() {
		if (head == nullptr)
			return -1;
		else
			return head->data;
	}

	void addFront(int X) {
		Node* newNode = new Node(X);
		if (head == nullptr)
			head = tail = newNode;
		else {
			newNode->next = head;
			head = newNode;
		}
	}

	int removeFront() {
		Node* tmp = head;
		if (head == nullptr)
			return -1;
		else {
			head = head->next;
			return tmp->data;
		}
	}
};

class linkedStack {
public:
	int n;
	SLinkedList* sl;

	linkedStack() {
		this->sl = new SLinkedList();
		this->n = 0;
	}

	int top() {
		if (n == 0)
			return -1;
		else
			return sl->front();
	}

	void push(int x) {
		sl->addFront(x);
		n += 1;
	}

	int pop() {
		if (n == 0)
			return -1;
		else {
			n -= 1;
			return sl->removeFront();
		}
	}
	
	int size() {
		return n;
	}
};

int calPostfix(string exp) {
	linkedStack ls;
	string postfix = exp;
	int n = postfix.size();
	int ans;
	char testch; //탐색하고 있는 문자

	for (int i = 0;i < n;i++) { //나중에 pop된 숫자가 앞으로?
		testch = postfix.at(i);
		if (testch == '+') { //연산자 만날 경우 스택에서 숫자 pop 시키고 계산 후 스택에 결과 push
			int a = ls.pop();
			int b = ls.pop();
			ans = b + a;
			ls.push(ans);
		}
		else if (testch == '-') {
			int a = ls.pop();
			int b = ls.pop();
			ans = b - a;
			ls.push(ans);
		}
		else if (testch == '*') {
			int a = ls.pop();
			int b = ls.pop();
			ans = b * a;
			ls.push(ans);
		}
		else { //문자열이 숫자일 경우 int형으로 변환 시킨 후 스택에 push
			int x = testch - '0';
			ls.push(x);
		}
	}

	return ls.pop(); //최종 결과 리턴
}

int main() {
	int q;
	cin >> q;
	string exp;
	for (int i = 0;i < q;i++) {
		cin >> exp;
		cout << calPostfix(exp) << endl;
	}
	return 0;
}
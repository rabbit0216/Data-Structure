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
		head = nullptr;
		tail = nullptr;
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
		head = head->next;
		return tmp->data;
	}
};

class linkedStack {
public:
	int n; //스택 원소 개수
	SLinkedList* S;

	linkedStack() {
		this->S = new SLinkedList();
		this->n = 0;
	}

	int empty() {
		if (n == 0)
			return 1;
		else
			return 0;
	}

	int top() {
		if (n == 0)
			return -1;
		else 
			return S->front();
	}

	void push(int X) {
		S->addFront(X);
		n += 1;
	}

	int pop() {
		if (n == 0)
			return -1;
		else {
			n -= 1;
			return S->removeFront();
		}
	}

	int size() {
		return n;
	}
};

int main() {
	int q;
	string menu;
	int x;
	linkedStack ls;
	cin >> q;
	for (int i = 0;i < q;i++) {
		cin >> menu;
		if (menu == "empty")
			cout << ls.empty() << endl;
		else if (menu == "top")
			cout << ls.top() << endl;
		else if (menu == "push") {
			cin >> x;
			ls.push(x);
		}
		else if (menu == "pop")
			cout << ls.pop() << endl;
		else if (menu == "size")
			cout << ls.size() << endl;
	}
	return 0;
}
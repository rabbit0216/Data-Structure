#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int data;
	Node* next;

	Node(int e) {
		this->data = e;
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

	void addFront(int X) {
		Node* newNode = new Node(X);

		if (head == nullptr) { //리스트 비어있을 경우
			head = tail = newNode;
		}
		else {
			newNode->next = head;
			head = newNode;
		}
	}

	int removeFront() {
		if (head == nullptr) {
			return -1;
		}
		else {
			Node* delNode = head; //삭제할 노드 따로 저장
			int delData = delNode->data;
			head = head->next;
			delete delNode;
			return delData;
		}
	}

	int front() {
		if (head == nullptr) {
			return -1;
		}
		else {
			int frontData = head->data;
			return frontData;
		}
	}

	int empty() {
		if (head == nullptr)
			return 1;
		else
			return 0;
	}
};


int main() {
	int q;
	SLinkedList sll;
	string menu;
	cin >> q;

	for (int i = 0;i < q;i++) {
		int x;
		cin >> menu;
		if (menu == "addFront") {
			cin >> x;
			sll.addFront(x);
		}
		else if (menu == "removeFront")
			cout << sll.removeFront() << endl;
		else if (menu == "front")
			cout << sll.front() << endl;
		else if (menu == "empty")
			cout << sll.empty() << endl;
	}
	return 0;
}
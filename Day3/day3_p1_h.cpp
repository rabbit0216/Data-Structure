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

	void showList() {
		if (head == nullptr)
			cout << "-1" << endl;
		else {
			Node* cur = head; //출력할 현재 노드 head로 설정
			while (cur != nullptr) { //현재 노드의 다음 노드가 null일 때 while문 탈출
				cout << cur->data << ' '; 
				cur = cur->next;
			}
			cout << endl;
		}
	}

	void addBack(int X) {
		Node* newNode = new Node(X);
		if (head == nullptr) { //리스트 비어있을 경우
			head = tail = newNode;
		}
		else {
			tail->next = newNode;
			tail = newNode;
		}
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
		else if (menu == "showList")
			sll.showList();
		else if (menu == "addBack") {
			cin >> x;
			sll.addBack(x);
		}
	}
	return 0;
}
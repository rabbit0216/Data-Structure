//원형연결리스트
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

class CLinkedList {
public:
	Node* head;
	Node* tail;
	int n; // 노드 개수

	CLinkedList() {
		this->n = 0;
		this->head = nullptr;
		this->tail = nullptr;
	}

	void add(int X) { 
		Node* newNode = new Node(X);
		Node* pre = tail; //삽입해 줄 위치
		if (n == 0) { //리스트 비어있을 때
			newNode->next = newNode; //자기 자신 가리킴
			tail = newNode;
		}
		else {
			for (int i = 0;i < n;i++)
				pre = pre->next; 
			newNode->next = pre->next; //새로운 노드와 마지막 노드 연결
			pre->next = newNode;
			tail = newNode;
		}
		n += 1;
	}

	void del(int place) {
		Node* pre = tail; //삭제할 노드의 이전 노드
		Node* tmp = pre->next; //삭제할 노드
		for (int i = 0;i < place;i++) //삭제 할 위치 만큼 이동
			pre = pre->next;
		tmp = pre->next; //삭제할 노드
		pre->next = tmp->next;  //삭제할 노드 앞의 노드와 삭제할 노드 뒤의 노드 연결
		n -= 1;

		//내가 오류가 계속 났던 이유가 굳이 메모리 해제 해서임. 메모리 해제하지말고 그냥 다음 노드랑 이어버리면 어차피 해제하지 않아도 해당 노드는 무시됨
	}

	void showList() { 
		if (tail == nullptr)
			cout << "-1" << endl;
		else {
			Node* cur = tail;
			for (int i = 0;i < n;i++) {
				cur = cur->next; //tail다음 노드인 첫번째 노드부터
				cout << cur->data << ' ';
			}
			cout << endl;
		}
	}
};

int main() {
	int bundle;
	int x;
	string menu;
	int place;
	cin >> bundle;

	for (int i = 0;i < bundle;i++) {
		CLinkedList cll;

		for (int i = 0;i < 10;i++) {
			cin >> x;
			cll.add(x);
		}

		for (int i = 0;i < 3;i++) {
			cin >> menu;
			if (menu == "Delete") {
				cin >> place;
				cll.del(place);
			}
		}
		cll.showList();
	}
	return 0;
}
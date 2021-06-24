//�������Ḯ��Ʈ
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
	int n; // ��� ����

	CLinkedList() {
		this->n = 0;
		this->head = nullptr;
		this->tail = nullptr;
	}

	void add(int X) { 
		Node* newNode = new Node(X);
		Node* pre = tail; //������ �� ��ġ
		if (n == 0) { //����Ʈ ������� ��
			newNode->next = newNode; //�ڱ� �ڽ� ����Ŵ
			tail = newNode;
		}
		else {
			for (int i = 0;i < n;i++)
				pre = pre->next; 
			newNode->next = pre->next; //���ο� ���� ������ ��� ����
			pre->next = newNode;
			tail = newNode;
		}
		n += 1;
	}

	void del(int place) {
		Node* pre = tail; //������ ����� ���� ���
		Node* tmp = pre->next; //������ ���
		for (int i = 0;i < place;i++) //���� �� ��ġ ��ŭ �̵�
			pre = pre->next;
		tmp = pre->next; //������ ���
		pre->next = tmp->next;  //������ ��� ���� ���� ������ ��� ���� ��� ����
		n -= 1;

		//���� ������ ��� ���� ������ ���� �޸� ���� �ؼ���. �޸� ������������ �׳� ���� ���� �̾������ ������ �������� �ʾƵ� �ش� ���� ���õ�
	}

	void showList() { 
		if (tail == nullptr)
			cout << "-1" << endl;
		else {
			Node* cur = tail;
			for (int i = 0;i < n;i++) {
				cur = cur->next; //tail���� ����� ù��° ������
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
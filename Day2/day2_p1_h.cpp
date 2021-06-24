#include <iostream>
#include <string>
using namespace std;
#define MAX 10000

class Array {
public:
	int n;
	int* arr;

	Array(int size) {
		this->n = 0;
		this->arr = new int[size];
		for (int i = 0;i < size;i++)
			arr[i] = 0;
	}

	int at(int idx) {
		if (arr[idx] == 0) {
			return 0;
		}
		else {
			return arr[idx];
		}
	}

	void set(int idx, int x) {
		if (arr[idx] == 0) {
			cout << "0" << endl;
		}
		else {
			arr[idx] = x;
		}
	}

	void add(int idx, int num) {
		if (arr[idx] == 0) { //���� ���� ���
			for (int i = idx;i >= 0;) {
				if (arr[i] == 0) {
					if (i == 0) { //�迭�� ����ִ� ��� �ε��� 0���� ����
						idx = 0;
					}
					i--;
				}
				else {
					idx = i + 1;
					break;
				}
			}

			arr[idx] = num;
		}
		else {
			for (int i = MAX - 2;i >= idx;i--) { // ��ĭ�� ���������� �̵�
				arr[i + 1] = arr[i];
			}
			arr[idx] = num;
		}
	}

	void remove(int idx) {
		if (arr[idx] == 0) //�迭�� ����ִ� ���
			cout << "0" << endl;

		else {
			cout << arr[idx] << endl; //���� �� ���
			arr[idx] = 0; //�ش� �ε����� ����
			for (int i = idx;i < MAX - 1;i++) { //��ĭ�� �������� �̵�
				arr[i] = arr[i + 1];
			}
			arr[MAX - 1] = 0; //������ ���� �ִ� �ε����� 0 ����
		}
	}

	void printArray() {
		for (int i = 0;i < MAX;i++) {
			if (arr[i] == 0) { //�迭 ���� �������� �ʴ� ��� ���x
				if (i == 0) //�迭�� ����ִ� ��� 0���
					cout << "0";
				break;
			}
			cout << arr[i] << ' ';
		}
		cout << '\n';
	}
};

int main() {
	Array array(MAX);
	string menu;
	int menuNum, idx, num;

	cin >> menuNum;
	for (int i = 0;i < menuNum;i++) {
		cin >> menu;
		if (menu == "at") {
			cin >> idx;
			cout << array.at(idx) << endl;
		}
		else if (menu == "set") {
			cin >> idx >> num;
			array.set(idx, num);
		}
		else if (menu == "add") {
			cin >> idx >> num;
			array.add(idx, num);
		}
		else if (menu == "remove") {
			cin >> idx;
			array.remove(idx);
		}
		else if (menu == "printArray") {
			array.printArray();
		}
	}

	return 0;
}
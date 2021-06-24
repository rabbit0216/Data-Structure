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
		if (arr[idx] == 0) { //원소 없을 경우
			for (int i = idx;i >= 0;) {
				if (arr[i] == 0) {
					if (i == 0) { //배열이 비어있는 경우 인덱스 0으로 변경
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
			for (int i = MAX - 2;i >= idx;i--) { // 한칸씩 오른쪽으로 이동
				arr[i + 1] = arr[i];
			}
			arr[idx] = num;
		}
	}

	void remove(int idx) {
		if (arr[idx] == 0) //배열이 비어있는 경우
			cout << "0" << endl;

		else {
			cout << arr[idx] << endl; //지울 값 출력
			arr[idx] = 0; //해당 인덱스값 삭제
			for (int i = idx;i < MAX - 1;i++) { //한칸씩 왼쪽으로 이동
				arr[i] = arr[i + 1];
			}
			arr[MAX - 1] = 0; //마지막 원소 있던 인덱스에 0 삽입
		}
	}

	void printArray() {
		for (int i = 0;i < MAX;i++) {
			if (arr[i] == 0) { //배열 값이 존재하지 않는 경우 출력x
				if (i == 0) //배열이 비어있는 경우 0출력
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
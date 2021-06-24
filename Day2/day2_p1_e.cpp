//배열 구현
#include <iostream>
#include <string>
using namespace std;
#define MAX 10000

class Array {
public:
	int n;
	int* arr;

	Array(int size) { //생성자
		this->n = 0;
		this->arr = new int[size];
		for (int i = 0;i < size;i++)
			arr[i] = 0;
	}

	int at(int idx) { //배열에 저장 된 값 리턴
		if (arr[idx] == 0) {
			return 0;
		}
		else {
			return arr[idx];
		}
	}

	void set(int idx, int x) { //배열에 값 저장
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
	}

	return 0;
}

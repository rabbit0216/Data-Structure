#include <iostream>
using namespace std;

class Safe {
public:
	int n;
	int* arr;

	Safe(int size) {
		this->n = 0;
		this->arr = new int[size];
		for (int i = 0;i < size;i++)
			arr[i] = 0;
	}

	int kr(int size) {
		int* temp = new int[size];
		for (int i = 0;i < size;i++)
			temp[i] = 0;

		int sum = 0;
		for (int i = 0;i < size;i++) { //나머지 0인 인덱스 임시배열에 저장
			if (i % 3 == 0) {
				temp[i] = arr[i];
			}
		}
		for (int i = 0;i < size;i++) {
			sum += temp[i];
		}
		return sum;
	}

	int jp(int size) {
		int* temp = new int[size];
		for (int i = 0;i < size;i++)
			temp[i] = 0;

		int sum = 0;
		for (int i = 0;i < size;i++) { //나머지 1인 인덱스 임시배열에 저장
			if (i % 3 == 1) {
				temp[i] = arr[i];
			}
		}
		for (int i = 0;i < size;i++) {
			sum += temp[i];
		}
		return sum;
	}

	int cn(int size) {
		int* temp = new int[size];
		for (int i = 0;i < size;i++)
			temp[i] = 0;

		int sum = 0;
		for (int i = 0;i < size;i++) { //나머지 2인 인덱스 임시배열에 저장
			if (i % 3 == 2) {
				temp[i] = arr[i];
			}
		}
		for (int i = 0;i < size;i++) {
			sum += temp[i];
		}
		return sum;
	}

	void add(int idx, int num) {
		arr[idx] = num;
	}

	~Safe() {
		delete[] arr;
	}
};

int main() {
	int size, q, num;
	cin >> q;

	for (int i = 0;i < q;i++) {
		cin >> size;
		Safe safe(size);
		for (int i = 0;i < size;i++) {
			cin >> num;
			safe.add(i, num);
		}
		cout << safe.kr(size) << ' ' << safe.jp(size) << ' ' << safe.cn(size) << endl;
	}

	return 0;
}
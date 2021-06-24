#include <iostream>
#include <cmath>
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

	int sum(int size, int rem) {
		int* temp = new int[size];
		for (int i = 0;i < size;i++)
			temp[i] = 0;

		int sum = 0;
		for (int i = 0;i < size;i++) { //나라에 따라 다른 나머지값 갖는 인덱스의 값 임시배열에 저장
			if (i % 3 == rem) {
				temp[i] = arr[i];
			}
		}
		for (int i = 0;i < size;i++) { 
			sum += temp[i];
		}
		return sum;
	}

	int avg(int size, int rem) {
		int* temp = new int[size];
		for (int i = 0;i < size;i++)
			temp[i] = 0;
		double count = 0;
		double avg = 0;
		double sum = 0;
		for (int i = 0;i < size;i++) { //나라에 따라 다른 나머지값 갖는 인덱스의 값 임시배열에 저장
			if (i % 3 == rem) {
				temp[i] = arr[i];
				if (arr[i] == 0)
					continue;
				count++;
			}
		}
		for (int i = 0;i < size;i++) {
			sum += temp[i];
		}
		if (sum == 0)
			avg = 0;
		else {
			avg = sum / count;
		}
		return floor(avg);
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
	int kr = 0;
	int jp = 1;
	int cn = 2;

	for (int i = 0;i < q;i++) {
		cin >> size;
		Safe safe(size);
		for (int i = 0;i < size;i++) {
			cin >> num;
			safe.add(i, num);
		}
		cout << safe.sum(size,kr) << ' ' << safe.sum(size,jp) << ' ' << safe.sum(size,cn) << endl;
		cout << safe.avg(size,kr) << ' ' << safe.avg(size,jp) << ' ' << safe.avg(size,cn) << endl;
	}

	return 0;
}
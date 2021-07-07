#include <iostream>
using namespace std;
#define MAX 10000
class Heap {
private:
	int* arr;
	int heap_size;
	int last_idx;
public:
	Heap() {
		arr = new int[MAX];
		arr[0] = { -1 };
		heap_size = 0;
		last_idx = 0;
		for (int i = 0;i < MAX;i++)
			arr[i] = 0;
	}
	void swap(int* idx1, int* idx2) {
		int tmp = *idx1;
		*idx1 = *idx2;
		*idx2 = tmp;
	}
	void insert(int e) {
		if (heap_size == 0) {
			arr[1] = e;
			last_idx += 1;
			heap_size += 1;
		}
		else {
			if (last_idx == MAX)
				doubling();

			last_idx += 1;
			heap_size += 1;
			arr[last_idx] = e;

			int child = last_idx;
			int parent = child / 2;

			while (child > 1 && arr[parent] > arr[child]) {
				swap(&arr[parent], &arr[child]);
				child = parent;
				parent = child / 2;
			}
		}
	}
	void doubling() {
		int* tmp = new int[MAX * 2];
		for (int i = 0;i <= heap_size;i++) {
			tmp[i] = arr[i];
		}
		delete[] arr;
		arr = tmp;
	}
	void printMin(int idx) {
		cout << arr[idx] << endl;
	}
	void printAsc(int idx) {
		int last = heap_size;
		for (int i = 0;i <= heap_size; i++) { //선택정렬
			int max = -1;
			int m_idx = 0;
			for (int j = 0;j <= last;j++) {
				if (max < arr[j]) {
					max = arr[j];
					m_idx = j;
				}
			}
			swap(&arr[last], &arr[m_idx]);
			last = last - 1;
		}

		cout << arr[idx] << endl;
	}
};

int main() {
	int t;
	cin >> t;
	for (int i = 0;i < t;i++) {
		int n, p;
		cin >> n >> p;
		Heap h;
		for (int j = 0;j < n;j++) {
			int x;
			cin >> x;
			h.insert(x);
		}
		h.printMin(p);
		h.printAsc(p);
	}
	return 0;
}

/*
1
6 4
8 4 6 2 3 10

*/
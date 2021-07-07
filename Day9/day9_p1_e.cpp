//배열기반 우선순위 큐_최소힙
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define max 1000

class Heap {
private:
	int* arr;
	int heap_size;
	int root_index;
	int last_index;
public:
	Heap() {
		arr = new int[max];
		arr[0] = { -1 };//dummy
		this->heap_size = 0;
		this->root_index = 1;
		this->last_index = 0;
		for (int i = 1;i < max;i++) {
			arr[i] = 0;
		}
	}
	void swap(int* idx1, int* idx2) {
		int tmp = *idx1;
		*idx1 = *idx2;
		*idx2 = tmp;
	}
	void insert(int e) {
		if (heap_size == 0) {
			last_index += 1;
			heap_size += 1;
			arr[last_index] = e;
			
		}
		else {
			if (last_index == max) { //배열사이즈가 최대에 도달 했을 경우
				doubling();
			}
			last_index += 1;
			heap_size += 1;
			arr[last_index] = e;
			
			int child = last_index; //삽입된 인덱스를 자식으로 설정
			int parent = child / 2;
			while (child > 1 && arr[parent] > arr[child]) { //인덱스가 1보다 크고 부모가 자식보다 클 경우 upHeap 수행
				swap(&arr[parent], &arr[child]);
				child = parent;
				parent = child / 2;
			}
		}
		
	}
	
	void doubling() { //array doubling
		int size = max * 2;
		int* tmp = new int[size];
		for (int i = 0;i <= heap_size;i++) {
			tmp[i] = arr[i];
		}
		delete[] arr;
		arr = tmp;
	}
	int size() {
		return heap_size;
	}
	bool isEmpty() {
		if (heap_size == 0)
			return true;
		else
			return false;
	}
	void print() {
		for (int i = 1;i <= heap_size;i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
	}
	
};


int main() {
	int n, e;
	string menu;
	Heap h;
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> menu;
		if (menu == "insert") {
			cin >> e;
			h.insert(e);
		}
		else if (menu == "size") {
			cout << h.size() << endl;
		}
		else if (menu == "isEmpty") {
			cout << h.isEmpty() << endl;
		}
		else if (menu == "print") {
			h.print();
		}
	}
	return 0;
}

/*
10
isEmpty
insert 2
print
insert 5
insert 3
size
insert 10
insert 3
print
isEmpty

*/
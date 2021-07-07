#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Heap {
private:
	vector<int> v;
	int heap_size;
	int last_index;
	int root_index;
public:
	Heap() {
		v.push_back(-1);
		this->heap_size = 0;
		this->root_index = 1;
		this->last_index = 0;
	}
	void swap(int* idx1, int* idx2) {
		int tmp = *idx1;
		*idx1 = *idx2;
		*idx2 = tmp;
	}
	void insert(int e) {
		if (heap_size == 0) {
			v.push_back(e);
			last_index += 1;
			heap_size += 1;
		}
		else {
			last_index += 1;
			heap_size += 1;
			v.push_back(e);
			int child = last_index;
			int parent = child / 2;
			
			while (child > 1 && v[parent] > v[child]) {
				swap(&v[parent], &v[child]);
				child = parent;
				parent = child / 2;
			}
		}
			
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
	int pop() {
		if (heap_size == 0) {
			return -1;
		}
		else {
			int tmp = v[1];
			swap(&v[1], &v[last_index]);
			v.pop_back();
			last_index -= 1;
			heap_size -= 1;

			int parent = 1;
			int child = parent * 2;
			
			if (child + 1 <= heap_size) {
				if (v[child] > v[child + 1])
					child = child + 1;
			}
			
	
			while (child <= heap_size && v[parent] > v[child]) { //부모 값이 더 작으면 stop
				swap(&v[parent], &v[child]);
				parent = child;
				child = child * 2;
				if (child + 1 <= heap_size) { //오른쪽 자식이 더 크면 오른쪽 자식으로 인덱스 설정
					if (v[child] > v[child + 1])
						child = child + 1;
				}
			}
			return tmp;
		}
	}
	int top() {
		if (heap_size == 0)
			return -1;
		else
			return v[1];
	}
	void print() {
		if (heap_size == 0)
			cout << "-1" << endl;
		else {
			for (int i = 1;i <= heap_size;i++) {
				cout << v[i] << ' ';
			}
			cout << '\n';
		}
	}
};

int main() {
	int n, x;
	Heap h;
	cin >> n;
	string menu;
	for (int i = 0;i < n;i++) {
		cin >> menu;
		if (menu == "insert") {
			cin >> x;
			h.insert(x);
		}
		else if (menu == "size") {
			cout << h.size() << endl;
		}
		else if (menu == "isEmpty") {
			cout << h.isEmpty() << endl;
		}
		else if (menu == "pop") {
			cout << h.pop() << endl;
		}
		else if (menu == "top") {
			cout << h.top() << endl;
		}
		else if (menu == "print") {
			h.print();
		}
	}
	return 0;
}

/*
17
isEmpty
insert 10
insert 5
size
insert 6
insert 9
pop
insert 10
insert 2
insert 4
top
insert 8
insert 11
pop
insert 15
insert 3
print
*/
//Array Stack
#include <iostream>
#include <string>
using namespace std;
#define max 10000

class aStack {
public:
	int capacity; //사이즈
	int* s; //배열
	int t; //top 위치
	
	aStack(int capacity) {
		this->s = new int[capacity];
		this->t = -1;
		this->capacity = capacity;
	}
	int empty() {
		if (t == -1)
			return 1;
		else
			return 0;
	}
	int top() {
		if (t == -1)
			return -1;
		else {
			return s[t];
		}
	}
	void push(int x) {
		t += 1;
		s[t] = x;
	}
	int pop() {
		if (t == -1)
			return -1;
		int tmp = s[t];
		t -= 1;
		return tmp;
	}
	int size() {
		return t + 1;
	}
};

int main() {
	int q;
	cin >> q;
	aStack as(max);
	for (int i = 0;i < q;i++) {
		string menu;
		cin >> menu;
		if (menu == "empty")
			cout << as.empty() << endl;
		else if (menu == "top")
			cout << as.top() << endl;
		else if (menu == "push") {
			int x;
			cin >> x;
			as.push(x);
		}
		else if (menu == "pop")
			cout << as.pop() << endl;
		else if (menu == "size")
			cout << as.size() << endl;
	}
	return 0;
}
#include <iostream>
#include <string>
using namespace std;
#define MAX 10000
class arrayStack {
public:
	int* S;
	int capacity;
	int t;

	arrayStack(int capacity) {
		this->capacity = capacity;
		this->S = new int[capacity];
		this->t = -1;
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
		else
			return S[t];
	}

	void push(int X) {
		t += 1;
		S[t] = X;
	}
};

int main() {
	string menu;
	arrayStack as(MAX);
	int q;
	int x;
	cin >> q;
	for (int i = 0;i < q;i++) {
		cin >> menu;
		if (menu == "empty")
			cout << as.empty() << endl;
		else if (menu == "top")
			cout << as.top() << endl;
		else if (menu == "push") {
			cin >> x;
			as.push(x);
		}
	}
	return 0;
}
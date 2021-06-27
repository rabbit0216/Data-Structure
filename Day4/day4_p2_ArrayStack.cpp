//arrayStack PostFix
#include <iostream>
#include <string>
using namespace std;
#define max 10000

class aStack {
public:
	int* s;
	int capacity;
	int t; //»çÀÌÁî

	aStack(int capacity) {
		this->s = new int[capacity];
		this->capacity = capacity;
		this->t = -1;
	}

	int pop() {
		int tmp = s[t];
		t -= 1;
		return tmp;
	}

	void push(int x) {
		t += 1;
		s[t] = x;
	}
};

int calPostfix(string exp) {
	aStack as(max);
	for (int i = 0;i < exp.size();i++) {
		char cal = exp.at(i);
		int x, y;
		int ans = 0;
		if (cal == '+') {
			x = as.pop();
			y = as.pop();
			ans = y + x;
			as.push(ans);
		}
		else if (cal == '-') {
			x = as.pop();
			y = as.pop();
			ans = y - x;
			as.push(ans);
		}
		else if (cal == '*') {
			x = as.pop();
			y = as.pop();
			ans = y * x;
			as.push(ans);
		}
		else {
			int num = cal - '0';
			as.push(num);
		}
	}
	return as.pop();
}

int main() {
	int q;
	cin >> q;
	for (int i = 0;i < q;i++) {
		string exp;
		cin >> exp;
		cout << calPostfix(exp) << endl;
	}
	return 0;
}

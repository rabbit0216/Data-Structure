#include <iostream>
using namespace std;
#define MAX 353333

class cell {
public:
	int key, value, prob;
	bool flag;

	cell() {
		key = -1;
		value = -1;
		prob = 1;
		flag = false;
	}
};
cell* ha = new cell[MAX];

int hfun1(int idx) {
	return idx % MAX;
}
int hfunc2(int idx) {
	return (17 - (idx % 17));
}

void insertTable(int value) {
	int idx = hfun1(value);
	int hx = hfunc2(value);
	int prob = 1;
	while (1) {
		if (ha[idx].value == value)
			return;
		if (ha[idx].flag == false) {
			break;
		}
		else { // h1 true
			if (ha[idx].value == value)
				return;
			if (ha[idx].flag == false) {
				break;
			}
			idx = (idx + hx) % MAX;
			prob++;
		}
	}
	ha[idx].key = idx;
	ha[idx].value = value;
	ha[idx].prob = prob;
	ha[idx].flag = true;
}

void searchTable(int value) {
	int idx = hfun1(value);
	int hx = hfunc2(value);
	int prob = 1;
	
	while (1) {
		if (ha[idx].value == value) {
			cout << 1 << ' ' << ha[idx].prob << endl;
			return;
		}
		if (ha[idx].flag == false) {
			break;
		}
		idx = (idx + hx) % MAX;
		prob++;
	}
	cout << 0 << ' ' << prob << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0;i < t;i++) {
		int n, m;
		cin >> n;
		int x;
		for (int i = 0;i < n;i++) {
			cin >> x;
			insertTable(x);
		}
		cin >> m;
		for (int i = 0;i < m;i++) {
			cin >> x;
			searchTable(x);
		}
		for (int i = 0;i < MAX;i++) {
			ha[i].key = -1;
			ha[i].value = -1;
			ha[i].prob = 1;
			ha[i].flag = false;
		}
	}
	return 0;
}

/*
2
5
4 1 5 2 3
5
1 3 7 9 5
5
1 12 23 353334 706667
5
1 353334 706667 5 23

*/
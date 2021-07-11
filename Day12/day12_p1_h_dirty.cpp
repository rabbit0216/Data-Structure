#include <iostream>
#define MAX 353333
using namespace std;

class cell {
public:
	int key;
	int value;
	int prob;
	bool flag;

	cell() {
		key = -1;
		value = -1;
		prob = 1;
		flag = false;
	}
};

cell* hashArr = new cell[MAX];


int sz = 0;

int hashFunc(int idx) {
	return idx % MAX;
}

void insertTable(int value) {
	int hx = hashFunc(value);

	if (hashArr[hx].flag == false) {
		hashArr[hx].flag = true;
		hashArr[hx].key = hx;
		hashArr[hx].value = value;
		hashArr[hx].prob = 1;
	}
	else {
		int idx = hx;
		int prob = 1;

		for (int i = 0;i < MAX;i++) {
			if (hashArr[idx].flag == false)
				break;
			idx = (idx + 1) % MAX;
			prob += 1;
		}
		hashArr[idx].flag = true;
		hashArr[idx].key = idx;
		hashArr[idx].value = value;
		hashArr[idx].prob = prob;
	}
}

void searchTable(int value) {
	int prob = 1;
	int hx = hashFunc(value);
	int idx = hx;
	while (1) {
		/*
		찾으려는 값이 존재하지 않을 경우 prob 횟수 계산을 안해서
		time limit 계속 뜸
		*/
		if (hashArr[idx].flag == false)
			break;
		if (hashArr[idx].value == value) {
			cout << "1" << ' ' << hashArr[idx].prob << '\n';
			return;
		}
		prob += 1;
		idx = (idx + 1) % MAX;
	}
	cout << "0 " << prob << endl;
}

void deleteTable(int value) {
	int hx = hashFunc(value);
	int prob = 1;
	int idx = hx;
	while (1) {
		if (hashArr[idx].flag == false)
			break;
		if (hashArr[idx].value == value) {
			cout << "1" << ' ' << prob << '\n';
			hashArr[idx].key = -1;
			hashArr[idx].prob = 1;
			hashArr[idx].value = -1;
			return;
		}
		prob += 1;
		idx = (idx + 1) % MAX;
	}
	cout << "0 " << prob << endl;
}

int main() {
	int t;
	cin >> t;



	for (int i = 0;i < t;i++) {
		for (int i = 0;i < MAX;i++) {
			hashArr[i].flag = false;
			hashArr[i].key = -1;
			hashArr[i].prob = 1;
			hashArr[i].value = -1;
		}
		int n, m;
		cin >> n;
		for (int j = 0;j < n;j++) {
			int x;
			cin >> x;
			insertTable(x);
		}

		cin >> m;
		for (int k = 0;k < m;k++) {
			int x;
			cin >> x;
			deleteTable(x);

		}

	}

	return 0;
}


/*
windows 64bit 에서 4094 byte 이상은 cmd.exe에서 입력 못받음.
*/


/*
2
5
1 353334 706667 1060000 1413333
5
1 353334 706667 1413333 353334
6
1 353334 706667 2 353335 3
6
3 1 706667 2 353334 353335

*/
#include<iostream>
#include<queue>
using namespace std;

bool check[20001];
int test_case, N;
int link[20001] = { 0,-1 }, cursor[20001] = { 0,1 };
void Print(int val) {
	if (val == -1) {
		return;
	}
	else {
		Print(link[val]);
		cout << cursor[val];
	}
}
bool BFS() {
	queue<int> q;
	if (N == 1) {
		link[0] = -1;
		cursor[0] = 1;
		return true;
	}
	fill(check, check + 20001, false);
	check[1] = true;
	q.push(1);
	while (q.size()) {
		int cur = q.front();
		q.pop();
		if (!cur) return true;
		for (int i = 0; i < 2; i++) {
			int next = (cur * 10 + i) % N;
			if (!check[next]) {
				check[next] = true;
				link[next] = cur;
				cursor[next] = i;
				q.push(next);
			}
		}
	}
	return false;
}
int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> test_case;
	while (test_case--) {
		cin >> N;
		if (BFS()) {
			Print(0);
		}
		else {
			cout << "BRAK";
		}
		cout << "\n";
	}

	return 0;
}
#include<iostream>
#include<set>
#include<queue>
using namespace std;

int F, S, G, U, D;
set<int> check;
void BFS() {
	queue<pair<int, int>> q;
	q.push({ S,0 });
	check.insert(S);
	while (q.size()) {
		int cur = q.front().first;
		int cur_cnt = q.front().second;
		if (cur == G) {
			cout << cur_cnt;
			return;
		}
		q.pop();
		int dir[2] = { U,-D };
		for (int i = 0; i < 2; i++) {
			int next = cur + dir[i];
			int next_cnt = cur_cnt + 1;
			if (next >= 1 && next <= F
				&& check.find(next) == check.end()) {
				q.push({ next,next_cnt });
				check.insert(next);
			}
		}
	}
	cout << "use the stairs";
	return;
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> F >> S >> G >> U >> D;
	BFS();
	return 0;
}
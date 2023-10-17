#include<iostream>
#include<queue>
using namespace std;

int N, K;
bool check[2][500001];
void BFS(int start) {
	queue<pair<int, int>> q;
	q.push({ start,0 });
	check[0][start] = true;
	while (q.size()) {
		int cur = q.front().first;
		int cur_time = q.front().second;
		int cur_K = K + cur_time * (cur_time + 1) / 2;
		q.pop();
		if (cur_K > 500000) {
			cout << -1;
			return;
		}
		if (cur == cur_K || check[cur_time % 2][cur_K]) {
			cout << cur_time;
			return;
		}
		int dir[3] = { 1,-1,cur };
		for (int i = 0; i < 3; i++) {
			int next = cur + dir[i];
			if (next >= 0 && next <= 500000
				&& !check[(cur_time + 1) % 2][next]) {
				check[(cur_time + 1) % 2][next] = true;
				q.push({ next,cur_time + 1 });
			}
		}
	}
}
int main() {

	cin.tie(NULL);	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> K;
	if (N == K) {
		cout << 0;
		return 0;
	}
	fill(check[0], check[0] + 500001, false);
	fill(check[1], check[1] + 500001, false);
	BFS(N);
	return 0;
}
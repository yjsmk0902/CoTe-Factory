#include<iostream>
#include<queue>
#include<vector>
#include<set>
using namespace std;

int n, m, k;
vector<pair<int, int>> info[1001];
priority_queue<pair<int, int>> q;
priority_queue<int> ans[1001];
set<pair<int, int>> check;
void Dijkstra(int start) {
	ans[start].push(0);
	q.push({ 0,start });
	while (q.size()) {
		int cur = q.top().second;
		int cur_val = -q.top().first;
		q.pop();
		for (int i = 0; i < info[cur].size(); i++) {
			int next = info[cur][i].first;
			int next_val = cur_val + info[cur][i].second;
			if (ans[next].size() < k) {
				ans[next].push(next_val);
				q.push({ -next_val,next });
			}
			else if (ans[next].top() > next_val) {
				ans[next].pop();
				ans[next].push(next_val);
				q.push({ -next_val,next });
			}
		}
	}
}
int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m >> k;
	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		info[a].push_back({ b,c });
	}
	Dijkstra(1);
	for (int i = 1; i <= n; i++) {
		if (ans[i].size() < k) {
			cout << -1 << "\n";
		}
		else {
			cout << ans[i].top() << "\n";
		}
	}
	return 0;
}
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N, M;
int cnt[32001];
vector<int> graph[32001];

void topological_sort() {
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (!cnt[i]) {
			q.push(i);
		}
	}
	while (q.size()) {
		int cur = q.front();
		q.pop();
		cout << cur << " ";
		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i];
			cnt[next]--;
			if (!cnt[next]) {
				q.push(next);
			}
		}
	}
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cnt[i] = 0;
	}
	while (M--) {
		cin >> a >> b;
		graph[a].emplace_back(b);
		cnt[b]++;
	}
	topological_sort();
	return 0;
}
#include<iostream>
#include<vector>
using namespace std;

int T, N, K;
int build_time[100001];
int ans = 0;
vector<int> graph[1001];
int running_time[1001];
void topological_sort(int goal) {
	if (graph[goal].empty()) {
		running_time[goal] = build_time[goal];
		return;
	}
	for (auto it : graph[goal]) {
		int time = 0;
		if (running_time[it] == -1) {
			topological_sort(it);
		}
		time = running_time[it];
		running_time[goal] = running_time[goal] > build_time[goal] + time ? running_time[goal] : time + build_time[goal];
	}
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> T;
	while (T--) {
		cin >> N >> K;
		for (int i = 1; i <= N; i++) {
			cin >> build_time[i];
			running_time[i] = -1;
		}
		int goal, pre;
		for (int i = 1; i <= K; i++) {
			cin >> pre >> goal;
			graph[goal].emplace_back(pre);
		}
		cin >> goal;
		topological_sort(goal);
		cout << running_time[goal] << "\n";
		for (int i = 1; i <= N; i++) {
			graph[i].clear();
		}
	}
	return 0;
}
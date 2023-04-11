#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int space[1001][1001];
bool check[1001][1001];

int BFS(vector<pair<int, int>> done, int M, int N) {
	int answer;
	queue<pair<pair<int, int>, int>> q;
	pair<int, int> dir[] = { {0,-1},{-1,0},{0,1},{1,0} };
	for (int i = 0; i < done.size(); i++) {
		q.push({ {done[i].first,done[i].second},0 });
		check[done[i].first][done[i].second] = true;
	}
	while (q.size()) {
		int cur_x = q.front().first.first;
		int cur_y = q.front().first.second;
		int cur_count = q.front().second;
		answer = cur_count;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int next_x = cur_x + dir[i].first;
			int next_y = cur_y + dir[i].second;
			int next_count = cur_count + 1;
			if (next_x >= 1 && next_x <= N
				&& next_y >= 1 && next_y <= M
				&& !check[next_x][next_y]
				&& space[next_x][next_y] == 0) {
				q.push({ {next_x,next_y},next_count });
				check[next_x][next_y] = true;
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (!check[i][j] && space[i][j] == 0) {
				return -1;
			}
		}
	}
	return answer;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int M, N;
	vector<pair<int, int>> done;
	cin >> M >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> space[i][j];
			if (space[i][j] == 1) {
				done.push_back({ i,j });
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		fill(check[i], check[i] + M, false);
	}
	cout << BFS(done, M, N);
	return 0;
}
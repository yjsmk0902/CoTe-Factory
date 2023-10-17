#include<iostream>
#include<set>
#include<queue>
#define DAY true
#define NIGHT false
#define INF 987654321
using namespace std;
int N, M, K;
char maze[1001][1001];
bool check[1001][1001][11];
int ans = INF;
void BFS() {
	queue<pair<pair<pair<int, int>, pair<int, int>>, bool>> q;
	q.push({ {{1,1},{1,0} },DAY });
	check[1][1][0] = true;
	while (q.size()) {
		int cur_x = q.front().first.first.first;
		int cur_y = q.front().first.first.second;
		int cur_count = q.front().first.second.first;
		int cur_crash = q.front().first.second.second;
		bool cur_time = q.front().second;
		if (cur_x == N && cur_y == M) {
			ans = (ans > cur_count ? cur_count : ans);
		}
		q.pop();
		pair<int, int> dir[5] = {
			{1,0},{0,1},{-1,0},{0,-1},{0,0}
		};
		for (int i = 0; i < 5; i++) {
			int next_x = cur_x + dir[i].first;
			int next_y = cur_y + dir[i].second;
			int next_count = cur_count + 1;
			bool next_time = (cur_time == DAY ? NIGHT : DAY);
			if (next_x == cur_x && next_y == cur_y && cur_time == NIGHT) {
				q.push({ {{next_x,next_y},{next_count,cur_crash}},next_time });
				continue;
			}
			if (next_x <= N && next_y <= M
				&& next_x >= 1 && next_y >= 1) {
				int next_crash = (maze[next_x][next_y] == '1' ? cur_crash + 1 : cur_crash);
				if (cur_time == DAY) {
					if (!check[next_x][next_y][next_crash]
						&& next_crash <= K) {
						q.push({ {{next_x,next_y},{next_count,next_crash}},next_time });
						check[next_x][next_y][next_crash] = true;
					}
				}
				else if (next_crash == cur_crash) {
					if (!check[next_x][next_y][next_crash]) {
						q.push({ {{next_x,next_y},{next_count,next_crash} },next_time });
						check[next_x][next_y][next_crash] = true;
					}
				}
			}
		}
	}
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			fill(check[i][j], check[i][j] + 11, false);
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> maze[i][j];
		}
	}
	BFS();
	if (ans == INF) {
		cout << -1;
	}
	else {
		cout << ans;
	}
	return 0;
}
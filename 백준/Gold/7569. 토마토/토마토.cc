#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int space[101][101][101];
bool check[101][101][101];

int BFS(vector<pair<pair<int, int>, int>> done, int M, int N, int H) {
	queue < pair<pair<int, int>, pair<int, int>>> q;
	int answer;
	for (int i = 0; i < done.size(); i++) {
		q.push({ {done[i].first.first,done[i].first.second},{done[i].second, 0} });
		check[done[i].first.first][done[i].first.second][done[i].second] = true;
	}
	pair<pair<int, int>, int> dir[] = { {{0,0},-1},{{0,0},1},{{0,-1},0},{{-1,0},0},{{0,1},0},{{1,0},0} };
	while (q.size()) {
		int cur_x = q.front().first.first;
		int cur_y = q.front().first.second;
		int cur_z = q.front().second.first;
		int cur_count = q.front().second.second;
		q.pop();
		answer = cur_count;
		for (int i = 0; i < 6; i++) {
			int next_x = cur_x + dir[i].first.first;
			int next_y = cur_y + dir[i].first.second;
			int next_z = cur_z + dir[i].second;
			int next_count = cur_count + 1;
			if (next_x >= 1 && next_x <= N
				&& next_y >= 1 && next_y <= M
				&& next_z >= 1 && next_z <= H
				&& !check[next_x][next_y][next_z] && space[next_x][next_y][next_z] == 0) {
				q.push({ {next_x,next_y},{next_z,next_count} });
				check[next_x][next_y][next_z] = true;
			}
		}
	}
	for (int h = 1; h <= H; h++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (!check[i][j][h] && space[i][j][h] == 0) {
					return -1;
				}
			}
		}
	}
	return answer;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int M, N, H;
	vector < pair<pair<int, int>, int>> done;
	cin >> M >> N >> H;
	for (int h = 1; h <= H; h++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				cin >> space[i][j][h];
				if (space[i][j][h] == 1) {
					done.push_back({ {i,j},h });
				}
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			fill(check[i][j], check[i][j] + H + 1, false);
		}
	}
	cout << BFS(done, M, N, H);
	return 0;
}
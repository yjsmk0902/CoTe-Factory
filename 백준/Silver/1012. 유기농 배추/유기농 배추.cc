#include<iostream>
#include<queue>
using namespace std;

bool space[50][50];
queue<pair<int, int>> q;

void insect_Location(int x, int y, int m, int n) {
	int count = 0;
	q.push({ x,y });
	while (q.size()) {
		space[x][y] = false;
		pair<int, int> dir[] = { {0,-1},{-1,0},{1,0},{0,1} };
		for (int i = 0; i < 4; i++) {
			int next_x = q.front().first + dir[i].first;
			int next_y = q.front().second + dir[i].second;
			if (next_x >= 0 && next_x < m && next_y >= 0 && next_y < n && space[next_x][next_y]) {
				q.push({ next_x,next_y });
				space[next_x][next_y] = false;
			}
		}
		q.pop();
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T, M, N, K, x, y, answer = 0;
	cin >> T;
	while (T--) {
		cin >> M >> N >> K;
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				space[i][j] = false;
			}
		}
		while (K--) {
			cin >> x >> y;
			space[x][y] = true;
		}
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (space[i][j]) {
					insect_Location(i, j, M, N);
					answer++;
				}
			}
		}
		cout << answer << "\n";
		answer = 0;
	}

	return 0;
}
#include<iostream>
#include<queue>
#define Left {0,-1}
#define Right {0,1}
#define Up {-1,0}
#define Down {1,0}
#define Point pair<int,int>
using namespace std;

int N, M;
char board[11][11];
bool check[11][11][11][11];
Point R, B, Hole;
Point dir[4] = { Left,Right,Up,Down };
pair<Point, int> move(Point ball, Point direction) {
	Point New = ball;
	int distance = 0;
	while (board[New.first][New.second] != '#' && board[New.first][New.second] != 'O') {
		New.first += direction.first;
		New.second += direction.second;
		distance++;
	}
	return { New,distance };
}
void BFS() {
	queue<pair<pair<Point, Point>, int>> q;
	check[R.first][R.second][B.first][B.second] = true;
	q.push({ {R,B},0 });
	while (q.size()) {
		Point cur_R = q.front().first.first;
		Point cur_B = q.front().first.second;
		int cur_cnt = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			pair<Point, int> next_R = move(cur_R, dir[i]);
			pair<Point, int> next_B = move(cur_B, dir[i]);
			if (next_B.first == Hole)	continue;
			if (next_R.first == Hole) {
				cout << cur_cnt + 1;
				return;
			}
			next_R.first.first -= dir[i].first;
			next_R.first.second -= dir[i].second;
			next_B.first.first -= dir[i].first;
			next_B.first.second -= dir[i].second;
			if (next_R.first == next_B.first) {
				if (next_R.second > next_B.second) {
					next_R.first.first -= dir[i].first;
					next_R.first.second -= dir[i].second;
				}
				else {
					next_B.first.first -= dir[i].first;
					next_B.first.second -= dir[i].second;
				}
			}
			if (!check[next_R.first.first][next_R.first.second][next_B.first.first][next_B.first.second]) {
				q.push({ {next_R.first,next_B.first},cur_cnt + 1 });
				check[next_R.first.first][next_R.first.second][next_B.first.first][next_B.first.second] = true;
			}
		}
	}
	cout << -1;
	return;
}
int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'R') {
				R = { i,j };
				board[i][j] = '.';
			}
			else if (board[i][j] == 'B') {
				B = { i,j };
				board[i][j] = '.';
			}
			else if (board[i][j] == 'O') {
				Hole = { i,j };
			}
		}
	}
	for (int a = 1; a <= N; a++) {
		for (int b = 1; b <= M; b++) {
			for (int c = 1; c <= N; c++) {
				fill(check[a][b][c], check[a][b][c] + N + 1, false);
			}
		}
	}
	BFS();
	return 0;
}
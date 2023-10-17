#include<iostream>
#include<vector>
#include<queue>

#define UP {0,-1}
#define DOWN {0,1}
#define LEFT {-1,0}
#define RIGHT {1,0}
#define INF 987654321
using namespace std;

int test_case, w, h;
char prison[102][102];
int save[3][102][102];
vector<pair<int, int>> prisoner;
void BFS(pair<int, int> start, int index) {
	priority_queue<pair<int, pair<int, int>>> q;
	for (int i = 0; i <= w + 1; i++) {
		for (int j = 0; j <= h + 1; j++) {
			save[index][i][j] = INF;
		}
	}
	q.push({ 0,start });
	save[index][start.first][start.second] = 0;
	while (q.size()) {
		pair<int, int> cur = q.top().second;
		int cur_val = -q.top().first;
		q.pop();
		if (save[index][cur.first][cur.second] < cur_val) {
			continue;
		}
		pair<int, int> dir[4] = { UP,DOWN,RIGHT,LEFT };
		for (int i = 0; i < 4; i++) {
			pair<int, int> next = { cur.first + dir[i].first,cur.second + dir[i].second };
			if (next.first >= 0 && next.second >= 0
				&& next.first <= w + 1 && next.second <= h + 1) {
				int next_val = prison[next.first][next.second] != '#' ? cur_val : cur_val + 1;
				if (prison[next.first][next.second] != '*'
					&& save[index][next.first][next.second] > next_val) {
					save[index][next.first][next.second] = next_val;
					q.push({ -next_val,next });
				}
			}
		}
	}
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> test_case;
	while (test_case--) {
		cin >> w >> h;
		for (int i = 0; i <= w + 1; i++) {
			prison[i][0] = '.';
			prison[i][h + 1] = '.';
		}
		for (int i = 0; i <= h + 1; i++) {
			prison[0][i] = '.';
			prison[w + 1][i] = '.';
		}
		for (int i = 1; i <= w; i++) {
			for (int j = 1; j <= h; j++) {
				cin >> prison[i][j];
				if (prison[i][j] == '$') {
					prisoner.push_back({ i,j });
				}
			}
		}
		int index = 0;
		BFS(prisoner[0], index++);
		BFS(prisoner[1], index++);
		BFS({ 0,0 }, index);
		
		int ans = INF;
		for (int i = 1; i <= w; i++) {
			for (int j = 1; j <= h; j++) {
				int sum = save[0][i][j] + save[1][i][j] + save[2][i][j];
				sum = prison[i][j] != '#' ? sum : sum - 2;
				ans = (sum < 0 || sum >= INF) || ans < sum ? ans : sum;
			}
		}
		cout << ans << "\n";
		prisoner.clear();
	}
	return 0;
}
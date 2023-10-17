/* #3197 - 백조의 호수
* 사용 알고리즘 - BFS
*/
#include<bits/stdc++.h>
#define point pair<int,int>
using namespace std;

int R, C;
char Map[1501][1501];
bool swan_visited[1501][1501];
bool water_visited[1501][1501];
queue<point> next_swan;
queue<point> next_ice;
vector<point> swan;
queue<point> clear;
point dir[] = { {0,1},{1,0},{0,-1},{-1,0} };
bool check_valid_swan(point next) {
	return next.first >= 1 && next.first <= R && next.second >= 1 && next.second <= C
		&& !swan_visited[next.first][next.second];
}
bool check_valid_water(point next) {
	return next.first >= 1 && next.first <= R && next.second >= 1 && next.second <= C
		&& !water_visited[next.first][next.second];
}
bool swan_BFS() {
	queue<point> q = next_swan;
	next_swan = clear;
	while (q.size()) {
		point cur = q.front();
		q.pop();
		for (auto it : dir) {
			point next = { cur.first + it.first,cur.second + it.second };
			if (check_valid_swan(next)) {
				if (Map[next.first][next.second] == 'X') {
					next_swan.push(next);
					swan_visited[next.first][next.second] = true;
					continue;
				}
				else if (Map[next.first][next.second] == '.') {
					q.push(next);
					swan_visited[next.first][next.second] = true;
				}
				else {
					return true;
				}
			}
		}
	}
	return false;
}
void ice_BFS() {
	queue<point> q = next_ice;
	next_ice = clear;
	while (q.size()) {
		point cur = q.front();
		q.pop();
		for (auto it : dir) {
			point next = { cur.first + it.first,cur.second + it.second };
			if (check_valid_water(next)) {
				if (Map[next.first][next.second] == 'X') {
					next_ice.push(next);
					Map[next.first][next.second] = '.';
					water_visited[next.first][next.second] = true;
					continue;
				}
				else if (Map[next.first][next.second] == '.') {
					q.push(next);
					water_visited[next.first][next.second] = true;
				}
			}
		}
	}
}
int solve() {
	int ans = 0;
	bool flag = false;
	next_swan.push(swan[0]);
	swan_visited[swan[0].first][swan[0].second] = true;
	while (!flag) {
		flag = swan_BFS();
		ice_BFS();
		if (flag)	break;
		ans++;
	}
	return ans;
}
int main() {
	cin.tie(NULL);	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(swan_visited, false, sizeof(swan_visited));
	memset(water_visited, false, sizeof(water_visited));
	cin >> R >> C;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> Map[i][j];
			if (Map[i][j] == 'L') {
				swan.push_back({ i,j });
				next_ice.push({ i,j });
				water_visited[i][j] = true;
			}
			else if (Map[i][j] == '.') {
				next_ice.push({ i,j });
				water_visited[i][j] = true;
			}
		}
	}
 	cout << solve();
	return 0;
}
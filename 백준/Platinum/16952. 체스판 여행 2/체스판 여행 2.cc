#include<iostream>
#include<queue>
#include<map>
#include<set>
#define Rook 0
#define Bishop 1
#define Knight 2
#define Point pair<int,int>
using namespace std;

int N;
int board[51][51];
Point start;
map<pair<Point, int>, pair<int, int>> check[3];
Point knight_dir[] = { {1,2},{2,1},{-1,2},{2,-1},{1,-2},{-2,1},{-1,-2},{-2,-1} };
Point bishop_dir[] = { {1,1},{-1,1},{1,-1},{-1,-1} };
Point rook_dir[] = { {0,1},{0,-1},{1,0},{-1,0} };
bool check_valid(Point p) {
	return p.first >= 1 && p.second >= 1 && p.first <= N && p.second <= N;
}
pair<int, int> BFS() {
	pair<int, int> ans = { -1,-1 };
	queue<pair<Point, pair<pair<int, int>, pair<int, int>>>> q;
	for (int i = 0; i < 3; i++) {
		check[i][{start, 1}] = { 0,0 };
		q.push({ start,{{i,1},{0,0}} });
	}
	while (q.size()) {
		Point cur = q.front().first;
		int cur_stat = q.front().second.first.first;
		int cur_end = q.front().second.first.second;
		pair<int, int> cur_progress
			= { q.front().second.second.first ,q.front().second.second.second };
		q.pop();
		if (cur_end == N * N) if (ans.first == -1 || ans > cur_progress)	ans = cur_progress;
		if (cur_stat == Rook) {
			for (auto it : rook_dir) {
				for (int k = 1;; k++) {
					Point next = { cur.first + it.first * k,cur.second + it.second * k };
					if (!check_valid(next))	break;
					int next_end = cur_end;
					pair<int, int> cur_compare = { cur_progress.first + 1,cur_progress.second };
					if (board[next.first][next.second] == cur_end + 1)	next_end++;
					if (check[Rook].find({ next,next_end }) == check[Rook].end()
						|| check[Rook][{next, next_end}] > cur_compare) {
						q.push({ next,{{Rook,next_end},cur_compare} });
						check[Rook][{next, next_end}] = cur_compare;
					}
				}
			}
		}
		else if (cur_stat == Bishop) {
			for (auto it : bishop_dir) {
				for (int k = 1;; k++) {
					Point next = { cur.first + it.first * k,cur.second + it.second * k };
					if (!check_valid(next))	break;
					int next_end = cur_end;
					pair<int, int> cur_compare = { cur_progress.first + 1,cur_progress.second };
					if (board[next.first][next.second] == cur_end + 1)	next_end++;
					if (check[Bishop].find({ next,next_end }) == check[Bishop].end()
						|| check[Bishop][{next, next_end}] > cur_compare) {
						q.push({ next,{{Bishop,next_end},cur_compare} });
						check[Bishop][{next, next_end}] = cur_compare;
					}
				}
			}
		}
		else if (cur_stat == Knight) {
			for (auto it : knight_dir) {
				Point next = { cur.first + it.first,cur.second + it.second };
				if (!check_valid(next))	continue;
				int next_end = cur_end;
				pair<int, int> cur_compare = { cur_progress.first + 1,cur_progress.second };
				if (board[next.first][next.second] == cur_end + 1)	next_end++;
				if (check[Knight].find({ next,next_end }) == check[Knight].end()
					|| check[Knight][{next, next_end}] > cur_compare) {
					q.push({ next,{{Knight,next_end},cur_compare} });
					check[Knight][{next, next_end}] = cur_compare;
				}
			}
		}
		for (int i = 0; i < 3; i++) {
			if (cur_stat != i) {
				pair<int, int> cur_compare = { cur_progress.first + 1,cur_progress.second + 1 };
				if (check[i].find({ cur, cur_end }) == check[i].end()
					|| check[i][{cur, cur_end}] > cur_compare) {
					check[i][{cur, cur_end}] = cur_compare;
					q.push({ cur,{{i,cur_end},cur_compare} });
				}
			}
		}
	}

	return ans;
}
int main() {
	cin.tie(NULL);	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) {
				start = { i,j };
			}
		}
	}
	pair<int, int> answer = BFS();
	cout << answer.first << " " << answer.second;
	return 0;
}
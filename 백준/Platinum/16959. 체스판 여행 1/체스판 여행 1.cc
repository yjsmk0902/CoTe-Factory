#include<iostream>
#include<queue>
#include<set>
#define Rook 0
#define Bishop 1
#define Knight 2
#define Point pair<int,int>
using namespace std;

int N;
int board[51][51];
Point start;
set<pair<Point, int>> check[3];
Point knight_dir[] = { {1,2},{2,1},{-1,2},{2,-1},{1,-2},{-2,1},{-1,-2},{-2,-1} };
Point bishop_dir[] = { {1,1},{-1,1},{1,-1},{-1,-1} };
Point rook_dir[] = { {0,1},{0,-1},{1,0},{-1,0} };
bool check_valid(Point p) {
	return p.first >= 1 && p.second >= 1 && p.first <= N && p.second <= N;
}
void BFS() {
	queue<pair<Point, pair<pair<int, int>, int>>> q;
	check[Rook].insert({ start,1 });
	check[Bishop].insert({ start,1 });
	check[Knight].insert({ start,1 });
	q.push({ start,{{Rook,2},0} });
	q.push({ start,{{Bishop,2},0} });
	q.push({ start,{{Knight,2},0} });
	while (q.size()) {
		Point cur = q.front().first;
		int cur_stat = q.front().second.first.first;
		int cur_end = q.front().second.first.second;
		int cur_cnt = q.front().second.second;
		q.pop();
		if (cur_end == N * N + 1) {
			cout << cur_cnt;
			return;
		}
		if (cur_stat == Rook) {
			if (check[Bishop].find({ cur, cur_end - 1 }) == check[Bishop].end()) {
				q.push({ cur,{{Bishop,cur_end},cur_cnt + 1} });
			}
			if (check[Knight].find({ cur,cur_end - 1 }) == check[Knight].end()) {
				q.push({ cur,{{Knight,cur_end},cur_cnt + 1} });
			}
			for (auto it : rook_dir) {
				for (int k = 1;; k++) {
					Point next = { cur.first + it.first * k,cur.second + it.second * k };
					if (check_valid(next)) {
						if (board[next.first][next.second] == cur_end) {
							int next_end = cur_end + 1;
							if (check[Rook].find({ next,cur_end - 1 }) == check[Rook].end()) {
								q.push({ next,{{Rook,next_end},cur_cnt + 1} });
								check[Rook].insert({ next,cur_end - 1 });
								check[Rook].insert({ next,next_end - 1 });
							}
						}
						else {
							if (check[Rook].find({ next,cur_end - 1 }) == check[Rook].end()) {
								q.push({ next,{{Rook,cur_end},cur_cnt + 1} });
								check[Rook].insert({ next,cur_end - 1 });
							}
						}
					}
					else {
						break;
					}
				}
			}
		}
		else if (cur_stat == Bishop) {
			if (check[Rook].find({ cur, cur_end - 1 }) == check[Rook].end()) {
				q.push({ cur,{{Rook,cur_end},cur_cnt + 1} });
			}
			if (check[Knight].find({ cur,cur_end - 1 }) == check[Knight].end()) {
				q.push({ cur,{{Knight,cur_end},cur_cnt + 1} });
			}
			for (auto it : bishop_dir) {
				for (int k = 1;; k++) {
					Point next = { cur.first + it.first * k,cur.second + it.second * k };
					if (check_valid(next)) {
						if (board[next.first][next.second] == cur_end) {
							int next_end = cur_end + 1;
							if (check[Bishop].find({ next,cur_end - 1 }) == check[Bishop].end()) {
								q.push({ next,{{Bishop,next_end},cur_cnt + 1} });
								check[Bishop].insert({ next,cur_end - 1 });
								check[Bishop].insert({ next,next_end - 1 });
							}
						}
						else {
							if (check[Bishop].find({ next,cur_end - 1 }) == check[Bishop].end()) {
								q.push({ next,{{Bishop,cur_end},cur_cnt + 1} });
								check[Bishop].insert({ next,cur_end - 1 });
							}
						}
					}
					else {
						break;
					}
				}
			}
		}
		else if (cur_stat == Knight) {
			if (check[Rook].find({ cur, cur_end - 1 }) == check[Rook].end()) {
				q.push({ cur,{{Rook,cur_end},cur_cnt + 1} });
			}
			if (check[Bishop].find({ cur,cur_end - 1 }) == check[Bishop].end()) {
				q.push({ cur,{{Bishop,cur_end},cur_cnt + 1} });
			}
			for (auto it : knight_dir) {
				Point next = { cur.first + it.first,cur.second + it.second };
				if (check_valid(next)) {
					if (board[next.first][next.second] == cur_end) {
						int next_end = cur_end + 1;
						if (check[Knight].find({ next,cur_end - 1 }) == check[Knight].end()) {
							q.push({ next,{{Knight,next_end},cur_cnt + 1} });
							check[Knight].insert({ next,cur_end - 1 });
							check[Knight].insert({ next,next_end - 1 });
						}
					}
					else {
						if (check[Knight].find({ next,cur_end - 1 }) == check[Knight].end()) {
							q.push({ next,{{Knight,cur_end},cur_cnt + 1} });
							check[Knight].insert({ next,cur_end - 1 });
						}
					}
				}
			}
		}
	}
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
	BFS();
	return 0;
}
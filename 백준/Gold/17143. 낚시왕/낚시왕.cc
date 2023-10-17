/* #17143 - 낚시왕
* 사용 알고리즘 - 브루트 포스
*/
#include<bits/stdc++.h>
#define Point pair<int,int>
using namespace std;
enum direction { NO_DIR, UP, DOWN, RIGHT, LEFT };

class shark {
public:
	Point p;
	int vel = 0;
	int dir = NO_DIR;
	int size = 0;
	shark() = default;
	shark(Point p, int vel, int dir, int size) :
		p(p), vel(vel), dir(dir), size(size) {}
	bool operator < (const shark& t) {
		if (p.first != t.p.first)	return p.first < t.p.first;
		return p.second < t.p.second;
	}
};

int R, C, M;
vector<shark> sharks;
int ans = 0;

pair<Point, int> move_shark(int x, int y, int dir, int vel) {
	pair<Point, int> next;
	int rest_vel, temp;

	switch (dir) {
	case UP:
		rest_vel = vel - (y - 1);
		if (rest_vel <= 0) {
			next = { {x,y - vel},dir };
			break;
		}
		temp = rest_vel / (R - 1);
		if (temp % 2)	next = { {x,R - rest_vel % (R - 1)},UP };
		else			next = { {x,1 + rest_vel % (R - 1)},DOWN };
		break;
	case DOWN:
		rest_vel = vel - (R - y);
		if (rest_vel <= 0) {
			next = { {x,y + vel},dir };
			break;
		}
		temp = rest_vel / (R - 1);
		if (temp % 2)	next = { {x,1 + rest_vel % (R - 1)},DOWN };
		else			next = { {x,R - rest_vel % (R - 1)},UP };
		break;
	case LEFT:
		rest_vel = vel - (x - 1);
		if (rest_vel <= 0) {
			next = { {x - vel,y},dir };
			break;
		}
		temp = rest_vel / (C - 1);
		if (temp % 2)	next = { {C - rest_vel % (C - 1),y},LEFT };
		else			next = { {1 + rest_vel % (C - 1),y},RIGHT };
		break;
	case RIGHT:
		rest_vel = vel - (C - x);
		if (rest_vel <= 0) {
			next = { { x + vel,y},dir };
			break;
		}
		temp = rest_vel / (C - 1);
		if (temp % 2)	next = { {1 + rest_vel % (C - 1),y},RIGHT };
		else			next = { {C - rest_vel % (C - 1),y},LEFT };
		break;
	}
	return next;
}

void fishing_king() {
	for (int fishman = 1; fishman <= C; fishman++) {
		for (vector<shark>::iterator it = sharks.begin(); it != sharks.end(); it++) {
			if (it->p.first == fishman) {
				ans += it->size;
				sharks.erase(it);
				break;
			}
		}
		vector<shark> temp;
		for (auto it : sharks) {
			temp.push_back(it);
		}
		sharks.clear();
		for (auto it : temp) {
			pair<Point, int> next = move_shark(it.p.first, it.p.second, it.dir, it.vel);
			sharks.push_back(shark(next.first, it.vel, next.second, it.size));
		}
		sort(sharks.begin(), sharks.end());
		temp.clear();
		int idx = 0;
		while (sharks.size() > 1 && idx < sharks.size() && idx != sharks.size() - 1) {
			if (sharks[idx].p == sharks[idx + 1].p) {
				auto cursor = sharks[idx].size < sharks[idx + 1].size
					? sharks.begin() + idx : sharks.begin() + idx + 1;
				sharks.erase(cursor);
				continue;
			}
			idx++;
		}
	}
}

int main() {
	cin.tie(NULL);	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> R >> C >> M;
	if (M == 0) {
		cout << 0;
		return 0;
	}
	pair<int, int> point;
	int vel, dir, size;
	for (int i = 1; i <= M; i++) {
		cin >> point.second >> point.first >> vel >> dir >> size;
		sharks.push_back(shark(point, vel, dir, size));
	}
	sort(sharks.begin(), sharks.end());
	fishing_king();
	cout << ans;
	return 0;
}
#include<iostream>
#define LL long long
#define Point pair<LL,LL>
using namespace std;
class Line {
public:
	Point a, b;
};

int line_num;
Line L[3001];
int parent[3001], group_cnt[3001];

int getParent(int a) {
	if (parent[a] == a)	return a;
	else	return parent[a] = getParent(parent[a]);
}
void Union(int a, int b) {
	parent[getParent(a)] = getParent(b);
}
LL CCW(Point a, Point b, Point c) {
	LL First = a.first * b.second + b.first * c.second + c.first * a.second;
	LL Second = a.second * b.first + b.second * c.first + c.second * a.first;
	if (First - Second > 0)			return 1;
	else if (First - Second == 0)	return 0;
	else							return -1;
}
bool is_Intersect(Line L1, Line L2) {
	Point P[5] = { {},L1.a,L1.b,L2.a,L2.b };
	LL ABC = CCW(P[1], P[2], P[3]);
	LL ABD = CCW(P[1], P[2], P[4]);
	LL CDA = CCW(P[3], P[4], P[1]);
	LL CDB = CCW(P[3], P[4], P[2]);
	if (ABC * ABD == 0 && CDA * CDB == 0) {
		if (P[1] > P[2])	swap(P[1], P[2]);
		if (P[3] > P[4])	swap(P[3], P[4]);
		if (P[1] <= P[4] && P[3] <= P[2]) {
			return true;
		}
		return false;
	}
	if (ABC * ABD <= 0 && CDA * CDB <= 0) {
		return true;
	}
	else	return false;
}

int main() {
	cin.tie(NULL);	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> line_num;
	for (int i = 1; i <= line_num; i++) cin >> L[i].a.first >> L[i].a.second >> L[i].b.first >> L[i].b.second;
	for (int i = 1; i <= line_num; i++)	parent[i] = i;
	for (int i = 1; i <= line_num; i++) {
		for (int j = 1; j < i; j++) {
			if (is_Intersect(L[i], L[j]))	Union(i, j);
		}
	}
	for (int i = 1; i <= line_num; i++)	group_cnt[getParent(i)]++;
	int ans_group_num = 0, ans_max = 0;
	for (int i = 1; i <= line_num; i++) {
		if (group_cnt[i] > 0)	ans_group_num++;
		ans_max = max(ans_max, group_cnt[i]);
	}
	cout << ans_group_num << "\n" << ans_max;
	return 0;
}
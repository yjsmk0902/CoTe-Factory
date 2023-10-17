/* #2887 - 행성 터널
* 사용 알고리즘 - 최소 스패닝 트리, 크루스칼
*/
#include<bits/stdc++.h>
#define LL long long
#define info pair<int,pair<int,int>>
using namespace std;

int N;
int parent[100001];
vector<pair<int, int>> X;
vector<pair<int, int>> Y;
vector<pair<int, int>> Z;
vector<info> graph;
int Find(int x) {
	if (parent[x] < 0)	return x;
	else {
		int temp = Find(parent[x]);
		parent[x] = temp;
		return temp;
	}
}
void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	if (x == y)	return;
	if (parent[x] < parent[y]) {
		parent[x] += parent[y];
		parent[y] = x;
	}
	else {
		parent[y] += parent[x];
		parent[x] = y;
	}
}
int main() {
	cin.tie(NULL);	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(parent, -1, sizeof(parent));
	cin >> N;
	int x, y, z;
	for (int i = 0; i < N; i++) {
		cin >> x >> y >> z;
		X.push_back({ x,i });
		Y.push_back({ y,i });
		Z.push_back({ z,i });
	}
	sort(X.begin(), X.end());
	sort(Y.begin(), Y.end());
	sort(Z.begin(), Z.end());
	for (int i = 0; i < N-1; i++) {
		graph.push_back({ X[i + 1].first - X[i].first,{X[i].second,X[i + 1].second} });
		graph.push_back({ Y[i + 1].first - Y[i].first,{Y[i].second,Y[i + 1].second} });
		graph.push_back({ Z[i + 1].first - Z[i].first,{Z[i].second,Z[i + 1].second} });
	}
	sort(graph.begin(), graph.end());
	int sum = 0;
	for (auto it : graph) {
		int a = it.second.first;
		int b = it.second.second;
		if (Find(a) != Find(b)) {
			sum += it.first;
			Union(a, b);
		}
	}
	cout << sum;
	return 0;
}
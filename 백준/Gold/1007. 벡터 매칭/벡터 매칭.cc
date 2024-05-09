/* #1007 - 벡터 매칭
* 사용 알고리즘 - DFS, 벡터
*/
#include<bits/stdc++.h>
#define point pair<int,int>
#define MAX 987654321
using namespace std;

int test_case;
int N;
vector<point> vec;
bool visited[20];
double ans;
double calc() {
	point result = { 0,0 };
	for (int i = 0; i < N; i++) {
		if (visited[i]) {
			result.first += vec[i].first;
			result.second += vec[i].second;
		}
		else {
			result.first -= vec[i].first;
			result.second -= vec[i].second;
		}
	}
	return sqrt(pow(result.first, 2) + pow(result.second, 2));
}
void DFS(int cur, int cnt) {
	if (cnt == N / 2) {
		ans = min(ans, calc());
		return;
	}
	else {
		for (int i = cur; i < N; i++) {
			visited[i] = true;
			DFS(i + 1, cnt + 1);
			visited[i] = false;
		}
	}
}
int main() {
	cin.tie(NULL);	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cout << fixed;
	cout.precision(7);

	cin >> test_case;
	while (test_case--) {
		vec.clear();
		ans = MAX;
		memset(visited, false, sizeof(visited));
		cin >> N;
		int a, b;
		for (int i = 0; i < N; i++) {
			cin >> a >> b;
			vec.push_back({ a,b });
		}
		DFS(0, 0);
		cout << ans << "\n";
	}
	return 0;
}
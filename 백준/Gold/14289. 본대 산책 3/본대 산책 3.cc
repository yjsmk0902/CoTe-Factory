/* #12850 - 본대 산책3
* 사용 알고리즘 - 수학(인접 행렬의 제곱), 분할정복
*/
#include<bits/stdc++.h>
#define MOD 1000000007
#define LL long long
#define Matrix vector<vector<LL>>
using namespace std;

int n, m;
LL D;
Matrix operator*(Matrix& a, Matrix& b) {
	Matrix ret(n, vector<LL>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				ret[i][j] += a[i][k] * b[k][j];
				ret[i][j] %= MOD;
			}
		}
	}
	return ret;
}
int main() {
	cin.tie(NULL);	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	Matrix graph(n, vector<LL>(n));
	Matrix ans(n, vector<LL>(n));
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		graph[a - 1][b - 1] = 1;
		graph[b - 1][a - 1] = 1;
	}
	for (int i = 0; i < n; i++) {
		ans[i][i] = 1;
	}
	cin >> D;
	while (D > 0) {
		if (D & 1) {
			ans = ans * graph;
		}
		graph = graph * graph;
		D = D >> 1;
	}
	cout << ans[0][0];
	return 0;
}
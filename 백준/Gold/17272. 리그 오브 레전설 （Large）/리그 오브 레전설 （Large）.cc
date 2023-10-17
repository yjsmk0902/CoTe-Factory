/* #17272 - 리그 오브 레전설 (Large)
* 사용 알고리즘 - 수학(인접 행렬의 제곱), 분할정복
*/
#include<bits/stdc++.h>
#define MOD 1000000007
#define LL long long
#define Matrix vector<vector<LL>>
using namespace std;

LL N;
int M;
Matrix operator*(Matrix& a, Matrix& b) {
	Matrix ret(M, vector<LL>(M));
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < M; k++) {
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

	cin >> N >> M;
	Matrix graph(M, vector<LL>(M));
	Matrix ans(M, vector<LL>(M));
	for (int i = 0; i < M; i++)	ans[i][i] = 1;
	for (int i = 0; i < M - 1; i++) graph[i][i + 1] = 1;
	graph[M - 1][0] = 1;
	graph[M - 1][M - 1] = 1;
	while (N > 0) {
		if (N & 1) {
			ans = ans * graph;
		}
		graph = graph * graph;
		N = N >> 1;
	}
	cout << ans[M - 1][M - 1];
	return 0;
}
/* #13430 - 합 구하기
* 사용 알고리즘 - 수학(인접 행렬의 제곱), 분할정복
*/
#include<bits/stdc++.h>
#define MOD 1000000007
#define LL long long
#define Matrix vector<vector<LL>>
using namespace std;

int k;
LL n;
Matrix operator*(Matrix& a, Matrix& b) {
	Matrix ret(k + 2, vector<LL>(k + 2));
	for (int i = 0; i < k + 2; i++) {
		for (int j = 0; j < k + 2; j++) {
			for (int x = 0; x < k + 2; x++) {
				ret[i][j] += a[i][x] * b[x][j];
				ret[i][j] %= MOD;
			}
		}
	}
	return ret;
}
int main() {
	cin.tie(NULL);	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> k >> n;
	Matrix graph(k + 2, vector<LL>(k + 2));
	Matrix ans(k + 2, vector<LL>(k + 2));
	for (int i = 0; i < k + 2; i++)	ans[i][i] = 1;
	for (int i = 0; i < k + 2; i++) {
		for (int j = 0; j <= i; j++) {
			graph[i][j] = 1;
		}
	}
	while (n > 0) {
		if (n & 1)	ans = ans * graph;
		graph = graph * graph;
		n = n >> 1;
	}
	cout << ans[k + 1][0];
	return 0;
}
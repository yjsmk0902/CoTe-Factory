/* #2086 - 피보나치 수의 합
* 사용 알고리즘 - 수학(인접행렬의 제곱), 분할정복
*/
#include<bits/stdc++.h>
#define MOD 1000000000
#define LL long long
#define Matrix vector<vector<LL>>
using namespace std;

LL a, b;
Matrix operator*(Matrix& a, Matrix& b) {
	Matrix ret(2, vector<LL>(2));
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				ret[i][j] += a[i][k] * b[k][j];
				ret[i][j] %= MOD;
			}
		}
	}
	return ret;
}
LL calc(LL x) {
	Matrix base = {
		{0,1},
		{1,1}
	};
	Matrix ans = {
		{1,0},
		{0,1}
	};
	while (x > 0) {
		if (x & 1)	ans = ans * base;
		base = base * base;
		x = x >> 1;
	}
	return ans[0][1];
}
int main() {
	cin.tie(NULL);	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> a >> b;
	cout << (calc(b + 2) - calc(a + 1) + MOD) % MOD;

	return 0;
}
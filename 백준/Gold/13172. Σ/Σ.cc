#include<iostream>
#include<map>
#define MOD 1000000007
using namespace std;
int M, N, S;
long long ans = 0;
map<long long, long long> DP;
long long Ferma(long long a, long long b) {
	if (DP[b]) {
		return DP[b];
	}
	if (b == 1) {
		return a;
	}
	return DP[b] = (Ferma(a, b / 2) * Ferma(a, b - b / 2)) % MOD;
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> M;
	while (M--) {
		cin >> N >> S;
		ans = (ans + S * Ferma(N, MOD - 2)) % MOD;
		DP.clear();
	}
	cout << ans;
	return 0;
}
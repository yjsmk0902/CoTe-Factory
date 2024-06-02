#include<iostream>
using namespace std;
string s1 = " ", s2 = " ", str;
int DP[1001][1001];
int ans = 0;
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	for (int i = 0; i <= s1.length(); i++) {
		DP[i][0] = 0;
	}
	for (int j = 0; j <= s2.length(); j++) {
		DP[0][j] = 0;
	}
	cin >> str;
	s1 += str;
	cin >> str;
	s2 += str;
	for (int i = 1; i <= s1.length()-1; i++) {
		for (int j = 1; j <= s2.length()-1; j++) {
			if (s1[i] == s2[j]) {
				DP[i][j] = DP[i - 1][j - 1] + 1;
			}
			else {
				DP[i][j] = max(DP[i][j - 1], DP[i - 1][j]);
			}
			ans = max(ans, DP[i][j]);
		}
	}
	cout << ans;
	return 0;
}
/* #14939 - 불 끄기
* 사용 알고리즘 - 비트마스킹, 브루트포스
*/
#include<bits/stdc++.h>
#define INF 987654321
using namespace std;

int line[11] = { 0 };
int temp_line[11];
int ans = INF;

void Switch_control(int i, int j) {
	if (i != 1)			temp_line[i - 1] ^= (1 << j);
	if (i != 10)		temp_line[i + 1] ^= (1 << j);
	if (j != 0)			temp_line[i] ^= (1 << (j - 1));
	if (j != 9)			temp_line[i] ^= (1 << (j + 1));
	temp_line[i] ^= (1 << j);
}
int bitCount(int x) {
	if (x == 0)	return 0;
	return x % 2 + bitCount(x / 2);
}
void brute_force() {
	for (int x = 0; x < 1024; x++) {
		int temp = 0;
		for (int i = 1; i <= 10; i++) {
			temp_line[i] = line[i];
		}
		for (int i = 0; i < 10; i++) {
			if (x & (1 << i)) {
				temp++;
				Switch_control(1, i);
			}
		}
		for (int i = 2; i <= 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (temp_line[i - 1] & (1 << j)) {
					Switch_control(i, j);
					temp++;
				}
			}
		}
		if(!temp_line[10])	ans = min(ans, temp);
	}
}
int main() {
	cin.tie(NULL);	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	char c;
	for (int i = 1; i <= 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> c;
			if (c == 'O') {
				line[i] += (1 << j);
			}
		}
	}
	brute_force();
	if (ans == INF)	cout << -1;
	else			cout << ans;
	return 0;
}
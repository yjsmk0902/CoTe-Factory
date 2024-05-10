#include<iostream>
using namespace std;

int N, K;
string str[50];
int str_value[50];
int check = 0, answer = 0;;
void Init() {
	check |= (1 << ('a' - 'a'));
	check |= (1 << ('n' - 'a'));
	check |= (1 << ('t' - 'a'));
	check |= (1 << ('i' - 'a'));
	check |= (1 << ('c' - 'a'));
}
void Back_Tracking(int cnt, int index) {
	if (cnt == K - 5) {
		int possible = 0;
		for (int i = 0; i < N; i++) {
			if ((str_value[i] & check) == str_value[i]) {
				possible++;
			}
		}
		answer = answer > possible ? answer : possible;
		return;
	}
	for (int i = index; i < 26; i++) {
		if (!(check & (1 << i))) {
			check |= (1 << i);
			Back_Tracking(cnt + 1, i + 1);
			check &= ~(1 << i);
		}
	}
}
int main() {
	cin.tie(NULL);	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> str[i];
		str_value[i] = 0;
		for (int j = 0; j < str[i].length(); j++) {
			str_value[i] |= (1 << (str[i][j] - 'a'));
		}
	}
	if (K < 5) {
		cout << 0;
		return 0;
	}
	Init();
	Back_Tracking(0, 0);
	cout << answer;
	return 0;
}
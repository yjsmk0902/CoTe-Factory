#include<iostream>
#include<vector>
using namespace std;

bool paper[129][129];
int blue = 0;
int white = 0;
void color_Paper(int N, int x, int y) {
	bool check = paper[x][y];
	for (int i = x; i < x + N; i++) {
		for (int j = y; j < y + N; j++) {
			if (paper[i][j] != check) {
				pair<int, int> dir[] = { {x,y},{x + N / 2,y},{x,y + N / 2},{x + N / 2,y + N / 2} };
				for (int k = 0; k < 4; k++) {
					color_Paper(N / 2, dir[k].first, dir[k].second);
				}
				return;
			}
			if (i == x + N - 1 && j == y + N - 1) {
				if (check) {
					blue++;
				}
				else {
					white++;
				}
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, temp;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> temp;
			if (temp == 1) {
				paper[i][j] = true;
			}
			else {
				paper[i][j] = false;
			}
		}
	}
	color_Paper(N, 1, 1);
	cout << white << "\n" << blue;
	return 0;
}
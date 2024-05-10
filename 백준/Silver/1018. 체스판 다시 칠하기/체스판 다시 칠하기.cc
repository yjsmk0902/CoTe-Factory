#include<iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;
	char color;
	char board[51][51];
	int answer = 32;
	int countB = 0,countW=0;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> color;
			board[i][j] = color;
		}
	}
	for (int Boardx = 0; Boardx <= N - 8; Boardx++) {
		for (int Boardy = 0; Boardy <= M - 8; Boardy++) {
			for (int i = Boardx; i < Boardx + 8; i++) {
				for (int j = Boardy; j < Boardy + 8; j++) {
					if ((board[i][j] == 'B' && (i + j) % 2 != 0) || (board[i][j] == 'W' && (i + j) % 2 != 1)) {
						countB++;
					}
					if ((board[i][j] == 'W' && (i + j) % 2 != 0) || (board[i][j] == 'B' && (i + j) % 2 != 1)) {
						countW++;
					}
				}
			}
			countB < countW ? (countB < answer ? answer = countB : answer) : (countW < answer ? answer = countW : answer);
			countB = 0;
			countW = 0;
		}
	}
	cout << answer;

	return 0;
}
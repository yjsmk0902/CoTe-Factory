#include<iostream>
#include<cmath>
using namespace std;

long long Visit(long long a, long long b, long long N) {
	if (N == 0) {
		return 0;
	}
	else {
		long long x = pow(2, N - 1);
		long long y = pow(2, N - 1);
		if (a < x && b < y) {
			return Visit(a, b, N - 1);
		}
		else if (a >= x && b < y) {
			return pow(2, N * 2 - 2) + Visit(a - x, b, N - 1);
		}
		else if (a < x && b >= y) {
			return pow(2, N * 2 - 2) * 2 + Visit(a, b - y, N - 1);
		}
		else if (a >= x && b >= y) {
			return pow(2, N * 2 - 2) * 3 + Visit(a - x, b - y, N - 1);
		}
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, r, c;
	cin >> N >> r >> c;
	cout << Visit(c, r, N);
	return 0;
}
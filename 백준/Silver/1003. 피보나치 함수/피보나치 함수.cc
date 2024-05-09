#include<iostream>
#include<cmath>
using namespace std;
int count_0 = 0, count_1 = 0;
pair<int, int> fib[41];
int fibonacci(int n) {
	if (n == 0) {
		fib[0].first = 1;
		fib[0].second = 0;
		count_0++;
		return 0;
	}
	else if (n == 1) {
		fib[1].first = 0;
		fib[1].second = 1;
		count_1++;
		return 0;
	}
	else {
		if (fib[n - 2].first == -1 && fib[n - 1].first == -1) {
			return fibonacci(n - 1) + fibonacci(n - 2);
		}
		else if (fib[n - 2].first != -1 && fib[n - 1].first != -1) {
			fib[n].first = fib[n - 1].first + fib[n - 2].first;
			fib[n].second = fib[n - 1].second + fib[n - 2].second;
			count_0 += fib[n].first;
			count_1 += fib[n].second;
			return 0;
		}
		else {
			if (fib[n - 2].first != -1) {
				count_0 += fib[n - 2].first;
				count_1 += fib[n - 2].second;
				return fibonacci(n - 1);
			}
			if (fib[n - 1].first != -1) {
				count_0 += fib[n - 1].first;
				count_1 += fib[n - 1].second;
				return fibonacci(n - 2);
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T, N;
	cin >> T;
	for (int i = 0; i <= 40; i++) {
		fib[i].first = -1;
	}
	while (T--) {
		cin >> N;
		fibonacci(N);
		cout << count_0 << " " << count_1 << "\n";
		count_0 = 0;
		count_1 = 0;
	}
	return 0;
}
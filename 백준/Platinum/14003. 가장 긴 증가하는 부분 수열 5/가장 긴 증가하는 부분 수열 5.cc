#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
vector<int> DP;
vector<int> tracking;
vector<int> answer;
int ans;
int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;
	vector<int> arr(N, 0);
	vector<int> tracking(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < N; i++) {
		int it = lower_bound(DP.begin(), DP.end(), arr[i]) - DP.begin();
		if (it >= DP.size()) {
			DP.emplace_back(arr[i]);
		}
		DP[it] = arr[i];
		tracking[i] = it;
	}
	cout << DP.size() << "\n";
	int DP_size = DP.size() - 1;
	int it = tracking.size() - 1;
	while (it >= 0) {
		if (tracking[it] == DP_size) {
			answer.emplace_back(arr[it]);
			it--;
			DP_size--;
		}
		else {
			it--;
		}
	}
	for (int i = answer.size() - 1; i >= 0; i--) {
		cout << answer[i] << " ";
	}
	return 0;
}
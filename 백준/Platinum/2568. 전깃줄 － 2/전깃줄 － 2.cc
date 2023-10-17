#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

int N;
vector<int> DP;
vector<int> tracking;
set<pair<int, int>> arr;
set<int> answer;
int ans;
int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;
	vector<int> tracking(N, 0);
	int it, temp, index = 0;
	for (int i = 0; i < N; i++) {
		cin >> it >> temp;
		arr.insert({ it,temp });
	}
	for (auto iter = arr.begin(); iter != arr.end(); iter++) {
		int it = lower_bound(DP.begin(), DP.end(), iter->second) - DP.begin();
		if (it >= DP.size()) {
			DP.emplace_back(iter->second);
		}
		DP[it] = iter->second;
		tracking[index] = it;
		index++;
	}
	int DP_size = DP.size() - 1;
	it = tracking.size() - 1;
	for (auto it : arr) {
		answer.insert(it.first);
	}
	auto iter = arr.end();
	iter--;
	while (it >= 0) {
		if (tracking[it] == DP_size) {
			answer.erase(iter->first);
			DP_size--;
		}
		it--;
		iter--;
	}
	cout << answer.size() << "\n";
	for (auto it : answer) {
		cout << it << "\n";
	}
	return 0;
}
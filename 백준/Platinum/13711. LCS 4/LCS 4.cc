#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

int N;
vector<int> DP;
int ans;
int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;
	map<int, int> arrA;
	map<int, int> arrB;
	vector<int> arr;
	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		arrA[i] = temp;
	}
	for (int i = 0; i < N; i++) {
		cin >> temp;
		arrB[temp] = i;
	}
	for (int i = 0; i < N; i++) {
		arr.emplace_back(arrB[arrA[i]]);
	}
	for (int i = 0; i < N; i++) {
		int it = lower_bound(DP.begin(), DP.end(), arr[i]) - DP.begin();
		if (it >= DP.size()) {
			DP.emplace_back(arr[i]);
		}
		DP[it] = arr[i];
	}
	cout << DP.size() << "\n";
	return 0;
}
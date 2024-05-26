#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
int longest_point = 0;
int Max = 0;
vector < pair<int, int>>* graph;
bool* check;
void DFS(int current, int length) {
	if (check[current]) {
		return;
	}
	check[current] = true;
	if (Max < length) {
		Max = length;
		longest_point = current;
	}
	for (int i = 0; i < graph[current].size(); i++) {
		DFS(graph[current][i].first, graph[current][i].second + length);
	}
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	int x, y, l;
	cin >> N;
	graph = new vector<pair<int, int>>[N + 1];
	check = new bool[N + 1];
	for (int i = 0; i < N-1; i++) {
		cin >> x >> y >> l;
		graph[x].push_back({ y,l });
		graph[y].push_back({ x,l });
	}
	fill(check, check + N + 1, false);
	DFS(1, 0);
	Max = 0;
	fill(check, check + N + 1, false);
	DFS(longest_point, 0);
	cout << Max;
	return 0;
}
/* #16566 - 카드 게임
* 사용 알고리즘 - 유니온 파인드
*/
#include<bits/stdc++.h>
using namespace std;

int N, M, K;
int parent[4000001];
vector<int> card;

int Find(int x) {
	if (parent[x] < 0)	return x;
	else {
		int temp = Find(parent[x]);
		x = temp;
		return temp;
	}
}
void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a == b)	return;
	else {
		parent[b] += parent[a];
		parent[a] = b;
	}
}

int main() {
	cin.tie(NULL);	cout.tie(NULL);
	ios_base::sync_with_stdio(false);


	cin >> N >> M >> K;
	int temp;
	while (M--) {
		cin >> temp;
		card.emplace_back(temp);
		parent[M] = -1;
	}
	parent[0] = -1;
	sort(card.begin(), card.end());
	while (K--) {
		cin >> temp;
		int cur = Find(upper_bound(card.begin(), card.end(), temp) - card.begin());
		cout << card[cur] << "\n";
		Union(cur, cur + 1);
	}
	return 0;
}
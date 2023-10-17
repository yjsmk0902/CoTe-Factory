#include<iostream>
#define L long long
#define Point pair<L,L>
using namespace std;

Point P[5];
void Intersection(Point a, Point b, Point c, Point d) {
	double Px = (double)(a.first * b.second - a.second * b.first) * (double)(c.first - d.first)
		- (double)(a.first - b.first) * (double)(c.first * d.second - c.second * d.first);
	double Py = (double)(a.first * b.second - a.second * b.first) * (double)(c.second - d.second)
		- (double)(a.second - b.second) * (double)(c.first * d.second - c.second * d.first);
	double PP = (double)(a.first - b.first) * (double)(c.second - d.second) - (double)(a.second - b.second) * (double)(c.first - d.first);
	if (PP == 0) {
		if (b == c && a <= c)	cout << b.first << " " << b.second;
		else if (a == d && c <= a)	cout << a.first << " " << a.second;
	}
	else {
		cout << fixed;
		cout.precision(9);
		cout << Px / PP << " " << Py / PP;
	}
}
L CCW(Point a, Point b, Point c) {
	L First = a.first * b.second + b.first * c.second + c.first * a.second;
	L Second = a.second * b.first + b.second * c.first + c.second * a.first;
	if (First - Second > 0)			return 1;
	else if (First - Second == 0)	return 0;
	else							return -1;
}
int main() {
	cin.tie(NULL);	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	for (int i = 1; i <= 4; i++) cin >> P[i].first >> P[i].second;

	L ABC = CCW(P[1], P[2], P[3]);
	L ABD = CCW(P[1], P[2], P[4]);
	L CDA = CCW(P[3], P[4], P[1]);
	L CDB = CCW(P[3], P[4], P[2]);
	if (ABC * ABD == 0 && CDA * CDB == 0) {
		if (P[1] > P[2])	swap(P[1], P[2]);
		if (P[3] > P[4])	swap(P[3], P[4]);
		if (P[1] <= P[4] && P[3] <= P[2]) {
			cout << 1 << "\n";
			Intersection(P[1], P[2], P[3], P[4]);
		}
		else	cout << 0;
		return 0;
	}
	if (ABC * ABD <= 0 && CDA * CDB <= 0) {
		cout << 1 << "\n";
		Intersection(P[1], P[2], P[3], P[4]);
	}
	else	cout << 0;
	return 0;
}
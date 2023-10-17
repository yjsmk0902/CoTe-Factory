#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;

typedef long long ll;

struct Line{
    ll x, y, xx, yy;
    Line() = default;
    Line(ll x, ll y, ll xx, ll yy) : x(x), y(y), xx(xx), yy(yy) {}
    bool operator < (const Line &t) const {
        if(tie(x, y) != tie(t.x, t.y)) return tie(x, y) < tie(t.x, t.y);
        return tie(xx, yy) > tie(t.xx, t.yy);
    }
};

struct LineCompare{
    ll a1, a2, b1, b2; // y = (a1/a2)x + (b1/b2)
    int flag; // 0: normal, 1: dx=0, 2: dy=0, 3: dx=dy=0
    LineCompare() = default;
    LineCompare(ll a1, ll a2, ll b1, ll b2, int flag) : a1(a1), a2(a2), b1(b1), b2(b2), flag(flag) {}
    bool operator < (const LineCompare &t) const {
        return tie(a1, a2, b1, b2, flag) < tie(t.a1, t.a2, t.b1, t.b2, t.flag);
    }
};

struct Event{
    ll x, y; int v;
    Event() = default;
    Event(ll x, ll y, int v) : x(x), y(y), v(v) {}
    bool operator < (const Event &t) const {
        return tie(x, y, v) < tie(t.x, t.y, t.v);
    }
};

LineCompare Get(const Line &line){
    ll dx = line.xx - line.x, dy = line.yy - line.y;
    if(dx == 0 && dy == 0) return {0, 0, 0, 0, 3};
    if(dy == 0) return {line.y, 1, 0, 0, 2};
    if(dx == 0) return {line.x, 1, 0, 0, 1};

    ll a1 = dy, a2 = dx;
    ll b1 = line.xx * line.y - line.x * line.yy, b2 = dx;

    ll ga = __gcd(a1, a2), gb = __gcd(b1, b2);
    a1 /= ga; a2 /= ga; b1 /= gb; b2 /= gb;
    return {a1, a2, b1, b2, 0};
}

int N;
Line A[101010];
map<LineCompare, vector<Line>> mp;
ll ans;

void Solve(const vector<Line> &v, const LineCompare &com){
    bool useY = com.flag == 2;
    vector<Event> event;
    for(const auto &i : v){
        event.emplace_back(i.x, i.y, 1);
        event.emplace_back(i.xx, i.yy, -1);
    }
    sort(all(event));
    ll acc = 0;
    for(const auto &i : event){
        if(i.v == 1) ans += acc;
        acc += i.v;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> A[i].x >> A[i].y >> A[i].xx >> A[i].yy;
        if(tie(A[i].x, A[i].y) > tie(A[i].xx, A[i].yy)){
            swap(A[i].x, A[i].xx);
            swap(A[i].y, A[i].yy);
        }
        mp[Get(A[i])].push_back(A[i]);
    }

    for(const auto &v : mp) Solve(v.second, v.first);
    cout << ans;
}
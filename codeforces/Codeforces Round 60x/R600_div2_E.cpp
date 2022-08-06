#include <cstring>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <set>
#include <map>
#include <array>
#include <stack>
#include <queue>
#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp    make_pair
#define pb    push_back
#define F     first
#define S     second
#define ab(x) (((x)<0)?-(x):(x))

int n, m;
vector<pi> v;
vi pos;
int d[85][100005];

int go(int idx, int left) {
    if (left > m) left = m;
    if (idx == n) return m == left ? 0 : 1 << 30;

    int &r = d[idx][left];
    if (r != -1)return r;
    auto [x, y] = v[idx];
    r = 1 << 30;

    vi tt = {left + 1, x};

    auto func = [&, x = x, y = y, left](int p) {
        int t;
        if (p < x - y) t = x - y - p;
        else if (p > x + y) t = p - x - y;
        else t = 0;
        bool cover_l = x - y - t <= left + 1;
        int nxt = cover_l ? max(left, x + y + t) : left;
        return go(idx + 1, nxt) + t;
    };

    for (int p: pos) r = min(r, func(p));
    for (int p: tt) r = min(r, func(p));

    return r;
}

void solve() {
    cin >> n >> m;
    v.resize(n);
    for (auto &[x, y]: v)cin >> x >> y;
    sort(v.begin(), v.end());

    pos.pb(1);
    pos.pb(m);
    for (auto [x, y]: v) {
        pos.pb(min(m, x + y + 1));
    }
    sort(pos.begin(), pos.end()), pos.erase(unique(pos.begin(), pos.end()), pos.end());
    memset(d, -1, sizeof(d));
    int r = go(0, 0);
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}


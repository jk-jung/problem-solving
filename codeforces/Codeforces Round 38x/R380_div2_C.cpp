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

ll n, k, S, t;

void solve() {
    cin >> n >> k >> S >> t;
    vector<pi> v(n);
    for (auto &[x, y]: v)cin >> x >> y;
    vi a(k);
    for (int &x: a)cin >> x;
    sort(a.begin(), a.end());
    a.pb(S);

    ll s = 0, e = S, r = 1 << 30;
    while (s <= e) {
        ll m = (s + e) / 2, pos = 0;
//        m = 8;
        ll tt = 0;
        for (ll x: a) {
            ll d = x - pos;
            if (d > m) {
                tt = 1ll << 50;
                break;
            }
            if (d * 2 <= m) {
                tt += d;
            } else {
                ll fast = m - d;
                ll slow = d - fast;
                tt += fast + slow * 2;
            }
            pos = x;
        }

        if (tt <= t) {
            r = m;
            e = m - 1;
        } else s = m + 1;
    }
    int rr = 1 << 30;
    for (auto [x, y]: v) {
        if (y >= r) rr = min(rr, x);
    }
    if (rr == (1 << 30))rr = -1;
    cout << rr << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}

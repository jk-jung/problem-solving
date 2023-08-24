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

void solve() {
    int n, m, bounty, inc, damage;
    cin >> n >> m >> bounty >> inc >> damage;
    vi max_h(n), start_h(n), regen(n);
    vector<vector<pi>> changes(n);
    for (int i = 0; i < n; i++)cin >> max_h[i] >> start_h[i] >> regen[i];
    for (int i = 0, t, e, h; i < m; i++) {
        cin >> t >> e >> h;
        changes[e - 1].pb({t, h});
    }
    for (int i = 0; i < n; i++)sort(changes[i].begin(), changes[i].end());

    vector<pi> seg;
    for (int i = 0; i < n; i++) {
        ll h = start_h[i], t = 0;
        ll H = max_h[i];
        ll re = regen[i];
        bool in = false;
        if (h <= damage) {
            seg.pb({t, +1});
            in = true;
        }

        for (auto [t2, h2]: changes[i]) {
            ll dif = t2 - t;

            if (in && min(H, h + dif * regen[i]) > damage) {
                int nt = t + (damage - h) / re;
                seg.pb({nt, 0});
                seg.pb({nt + 1, -1});
                in = false;
            }

            h = h2;
            t = t2;
            if (!in && h <= damage) {
                seg.pb({t, +1});
                in = true;
            }
            if (in && h > damage) {
                seg.pb({t - 1, 0});
                seg.pb({t, -1});
                in = false;
            }
        }
        if (in && re && H > damage) {
            int nt = t + (damage - h) / re;
            seg.pb({nt, 0});
            seg.pb({nt + 1, -1});
        }

    }
    ll r = 0, st = 0;
    sort(seg.begin(), seg.end());
    for (int i = 0; i < seg.size();) {
        ll t = seg[i].F;
        while (i < seg.size() && seg[i].F == t)st += seg[i++].S;
        r = max(r, (bounty + inc * t) * st);
    }
    if (st && inc)r = -1;
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}

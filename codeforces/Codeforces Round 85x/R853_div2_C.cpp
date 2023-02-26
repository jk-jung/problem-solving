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
    ll n, m;
    cin >> n >> m;
    vi v(n), w;
    set<int> ss;
    map<int, vector<pi>> ck;
    for (int &x: v)cin >> x, ss.insert(x), ck[x].pb({0, 1});
    w = v;

    for (int i = 0; i < m; i++) {
        int ii, y;
        cin >> ii >> y;
        int x = w[ii - 1];
        w[ii - 1] = y;
        if (x != y) {
            ck[x].pb({i + 1, -1});
            ck[y].pb({i + 1, +1});

        }
        ss.insert(y);
    }

    ll r = 0, base = m * (m + 1) / 2;
    for (int x: ss) {
        vector<pi> &t = ck[x];
        t.pb({m + 1, -(1 << 30)});
        int i = 0, st = 0, last = -1;
        ll cnt = 0;
        while (i < t.size()) {
            int pos = t[i].F;
            if (st > 0 && last != -1)
                cnt += pos - last;
            while (i < t.size() && pos == t[i].F) st += t[i++].S;
            last = pos;
        }
        ll k = m + 1 - cnt;
        r += base - k * (k - 1) / 2;
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
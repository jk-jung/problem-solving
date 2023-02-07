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

int n, t;
vector<pair<pi, pi>> v, vv;
vector<pi> r;
vi rr;

void process() {
    vi rest;
    for (int i = 0; i < vv.size();) {
        int x = vv[i].F.S;
        vi tt;
        while (i < vv.size() && vv[i].F.S == x)
            tt.pb(vv[i++].S.S);

        if (tt.size() % 2) {
            rest.pb(tt.back());
            tt.pop_back();
        }
        for (int j = 0; j < tt.size(); j += 2) {
            r.pb({tt[j], tt[j + 1]});
        }
    }
    if (rest.size() % 2)rr.pb(rest[0]);
    for (int j = rest.size() % 2; j < rest.size(); j += 2) {
        r.pb({rest[j], rest[j + 1]});
    }
}

void solve() {
    cin >> n;
    v.resize(n);
    for (auto &x: v) {
        cin >> x.F.F >> x.F.S >> x.S.F;
        x.S.S = ++t;
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n;) {
        int x = v[i].F.F;

        vv.clear();
        while (i < n && v[i].F.F == x) vv.pb(v[i++]);
        process();
    }
    for (int j = 0; j < rr.size(); j += 2) {
        r.pb({rr[j], rr[j + 1]});
    }
    for (auto [x, y]: r)cout << x << " " << y << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}

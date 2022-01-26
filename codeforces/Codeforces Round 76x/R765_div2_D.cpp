#include <string.h>
#include <stdio.h>
#include <math.h>
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

int n, k;
vi V;
vi r;

vi check(vi &v0, vi &v1, int t) {
    if (v0.empty() && v1.empty()) return {};
    if (v0.empty()) return {v1[0]};
    if (v1.empty()) return {v0[0]};

    if (v0.size() < 10 && v1.size() < 10) {
        for (int x: v0) {
            for (int y: v1) {
                if ((V[x] ^ V[y]) >= k) return {x, y};
            }
        }
        return {v1[0]};
    }

    t--;
    vi v[2][2];
    int q = (k >> t) & 1;
    for (auto &x: v0) v[0][V[x] >> t & 1].pb(x);
    v0.clear();
    for (auto &x: v1) v[1][V[x] >> t & 1].pb(x);
    v1.clear();

    if (q == 0) {
        if (!v[0][0].empty() && !v[1][1].empty()) {
            return {v[0][0][0], v[1][1][0]};
        }
        if (!v[0][1].empty() && !v[1][0].empty()) {
            return {v[0][1][0], v[1][0][0]};
        }
    }
    vi rr;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if ((i ^ j) != q)continue;
            vi r1 = check(v[0][i], v[1][j], t);
            v[0][i].clear();
            v[1][j].clear();
            if (r1.size() > rr.size()) rr = r1;
        }
    }
    return rr;
}

void calc(vi &v, int mask = 0) {
    if (v.empty()) return;
    if (v.size() == 1 || k == 0) {
        for (auto x: v)r.pb(x);
        return;
    }

    int t = 31 - __builtin_clz(k);
    vi w[33];
    for (auto i: v) {
        int x = V[i] ^ mask;
        int t2 = x == 0 ? 0 : 31 - __builtin_clz(x);
        if (t2 >= t) w[t2].pb(i);
        else w[0].pb(i);
    }
    v.clear();

    for (int i = t + 1; i < 32; i++)calc(w[i], mask | (1 << i)), w[i].clear();
    vi temp = check(w[0], w[t], t);
    for (int x: temp)r.pb(x);

}

void solve() {
    cin >> n >> k;
    vi v;
    V.resize(n);
    map<int, int> ck;
    for (int i = 0; i < n; i++) {
        cin >> V[i];
        if (k > 0 && ck.count(V[i]))continue;
        ck[V[i]] = 1;
        v.pb(i);
    }

    calc(v);

    if (r.size() <= 1)cout << -1 << endl;
    else {
        cout << r.size() << endl;
        for (int x: r)cout << x + 1 << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}

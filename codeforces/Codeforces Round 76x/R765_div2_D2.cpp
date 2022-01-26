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
vi r;

vi check(map<int, int> &v0, map<int, int> &v1, int t) {
    if (v0.empty() && v1.empty()) return {};
    if (v0.empty()) return {v1.begin()->S};
    if (v1.empty()) return {v0.begin()->S};

    int mask = (1 << t) - 1;
    t--;

    map<int, int> v[2][2];
    int q = (k >> t) & 1;
    for (auto &x: v0) v[0][x.F >> t & 1][x.F & mask] = x.S;
    for (auto &x: v1) v[1][x.F >> t & 1][x.F & mask] = x.S;
    v0.clear();
    v1.clear();

    if (q == 0) {
        if (!v[0][0].empty() && !v[1][1].empty()) {
            return {v[0][0].begin()->S, v[1][1].begin()->S};
        }
        if (!v[0][1].empty() && !v[1][0].empty()) {
            return {v[0][1].begin()->S, v[1][0].begin()->S};
        }
    }
    vi rr;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if ((i ^ j) != q)continue;
            vi r1 = check(v[0][i], v[1][j], t - 1);
            v[0][i].clear();
            v[1][j].clear();
            if (r1.size() > rr.size()) rr = r1;
        }
    }
    return rr;
}

void calc(map<int, int> &v) {
    if (v.empty()) return;
    if (v.size() == 1) {
        r.pb(v.begin()->S);
        return;
    }

    int t = 31 - (int) __builtin_clz(k);
    map<int, int> w[33];
    for (auto &x: v) {
        int t2 = x.F == 0 ? 0 : 31 - (int) __builtin_clz(x.F);
        if (t2 >= t) {
            w[t2][x.F ^ (1 << t2)] = x.S;
        } else w[0][x.F] = x.S;
    }
    v.clear();

    for (int i = t + 1; i < 32; i++)calc(w[i]), w[i].clear();
    vi temp = check(w[0], w[t], t);
    for (int x: temp)r.pb(x);
}

void solve() {
    cin >> n >> k;
    map<int, int> ck;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        ck[x] = i;
    }

    if (k == 0)for (int i = 0; i < n; i++)r.pb(i);
    else calc(ck);

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

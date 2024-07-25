#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define ab(x) (((x) < 0) ? -(x) : (x))

vi v[100005];
set<pi> c;

int cnt(vi &a, vi &b) {
    int r = 0;
    for (int x: a)for (int y: b)if (x == y) r++;
    return r;
}

bool ck(int x, int y) {
    return c.count(mp(x, y));
}


void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)v[i].pb(i);
    for (int i = 0; i < n * 2; i++) {
        int a, b;
        cin >> a >> b;
        v[a].pb(b);
        v[b].pb(a);
        c.insert(mp(a, b));
        c.insert(mp(b, a));
    }

    if (n < 10) {
        vi r(n);
        for (int i = 0; i < n; i++)r[i] = i + 1;
        do {
            bool ok = true;
            for (int i = 0; i < n; i++) {
                if (!ck(r[i], r[(i + 1) % n]))ok = false;
                if (!ck(r[i], r[(i + 2) % n]))ok = false;
            }
            if (ok) {
                for (int x: r)cout << x << " ";
                return;
            }
        } while (next_permutation(r.begin(), r.end()));
    }

    int x = 1;
    vi r = {x};
    set<int> used;
    used.insert(x);
    for (int i = 0; i < n; i++) {
        if (v[i + 1].size() != 5) {
            cout << -1;
            return;
        }
    }
    for (int i = 0; i < n - 1; i++) {
        bool ok = false;
        for (int y: v[x]) {
            if (used.count(y))continue;
            if (cnt(v[x], v[y]) == 4) {
                x = y;
                ok = true;
                break;
            }
        }
        r.pb(x);
        used.insert(x);
        if (!ok) {
            cout << -1;
            return;
        }
    }
    for (int x: r)cout << x << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}

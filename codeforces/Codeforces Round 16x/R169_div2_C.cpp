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

void solve() {
    int n, q;
    cin >> n >> q;
    vi v(n), c(n);
    vector<pi> b;
    for (int &x: v)cin >> x;
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        b.pb({x, 1});
        b.pb({y + 1, -1});
    }
    sort(b.begin(), b.end());

    int idx = 0, t = 0;
    for (int i = 1; i <= n; i++) {
        while (idx < b.size() && b[idx].F == i) {
            t += b[idx++].S;
        }
        c[i - 1] = t;
    }
    sort(c.rbegin(), c.rend());
    sort(v.rbegin(), v.rend());
    ll r = 0;
    for (int i = 0; i < n; i++) {
        r += (ll) c[i] * v[i];
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}

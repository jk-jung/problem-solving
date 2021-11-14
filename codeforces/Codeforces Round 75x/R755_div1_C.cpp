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


ll MIN = -(1ll << 60);
class IndexTree {
public:
    int n, size;
    vector<ll> d;

    IndexTree(int _n) {
        init(_n);
    }

    void init(int _n) {
        n = _n;
        size = 1 << (32 - __builtin_clz(n));
        d.resize(size * 2 + 5, MIN);
    }

    void up(int x, ll v) {
        x += size;
        while (x) d[x] = max(d[x], v), x >>= 1;
    }

    ll read(int s, int e) {
        s += size, e += size;
        ll r = d[s];
        while (s <= e) {
            if ((s & 1) == 1) r = max(r, d[s++]);
            if ((e & 1) == 0) r = max(r, d[e--]);
            s >>= 1, e >>= 1;
        }
        return r;
    }

    int idx(int s, ll base) {
        int e = n - 1, r = n;
        while (s <= e) {
            int m = (s + e) / 2;
            if (read(s, m) > base)r = m, e = m - 1;
            else s = m + 1;
        }
        return r - 1;
    }

};

void solve() {
    int n;
    map<ll, vi> ck;
    cin >> n;
    vi v(n);
    for (int i = 0; i < n; i++)cin >> v[i];

    IndexTree even(n), odd(n);
    ll s = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) s += v[i];
        else s -= v[i];

        if (i % 2 == 0) even.up(i, -s);
        else odd.up(i, s);

        ck[s].pb(i);
    }
    ll base = 0, r = 0;
    for (int i = 0; i < n; i++) {
        int idx_odd = odd.idx(i, base);
        int idx_even = even.idx(i, -base);
        int idx = min(idx_odd, idx_even);
        vi &t = ck[base];

        if (v.size() > 0) {
            int s = lower_bound(t.begin(), t.end(), i) - t.begin();
            int k = upper_bound(t.begin(), t.end(), idx) - t.begin();
            r += (k - s);
        }

        if (i % 2 == 0) base += v[i];
        else base -= v[i];
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}

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
        d.resize(size * 2 + 5, -(1ll << 60));
    }

    void up(int x, ll v) {
        x += size;
        d[x] = v;
        x /= 2;
        while (x) {
            d[x] = max(d[x * 2], d[x * 2 + 1]);
            x >>= 1;
        }
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
};

ll d[300005];

void solve() {
    int n;
    cin >> n;
    vector<ll> h(n), b(n);
    for (ll &x: h)cin >> x, x--;
    for (ll &x: b)cin >> x;

    IndexTree tre(n), tre2(n);


    d[0] = b[0];
    tre.up(0, b[0]);
    tre2.up(h[0], 0);
    for (int i = 1; i < n; i++) {
        ll x = tre2.read(0, h[i]); // find prev shorter
        if (x < 0)x = -1;
        tre2.up(h[i], i);

        ll t = -(1ll << 60);
        t = max(t, tre.read(max(0ll, x), i - 1) + b[i]);

        if (x >= 0) {
            t = max(t, d[x]);
        }else t = max(t, b[i]);

        d[i] = t;
        tre.up(i, t);
    }
    cout << d[n - 1] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}

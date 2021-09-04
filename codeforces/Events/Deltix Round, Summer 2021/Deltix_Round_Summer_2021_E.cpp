#include <string.h>
#include <stdio.h>
#include <math.h>
#include <cassert>
#include <map>
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
    vector<ll> d1;
    vector<ll> d2;

    IndexTree(int _n) {
        init(_n);
    }

    void init(int _n) {
        n = _n;
        size = 1 << (32 - __builtin_clz(n));
        d1.resize(size * 2 + 5, -(1ll << 62));
        d2.resize(size * 2 + 5, +(1ll << 62));
    }

    void up(int x, ll v) {
        x += size;
        while (x) {
            d1[x] = max(d1[x], v);
            d2[x] = min(d2[x], v);
            x >>= 1;
        }
    }

    pair<ll, ll> read(int s, int e) {
        s += size, e += size;
        ll r1 = d1[s];
        ll r2 = d2[s];
        while (s <= e) {
            if ((s & 1) == 1) r1 = max(r1, d1[s]), r2 = min(r2, d2[s]), s++;
            if ((e & 1) == 0) r1 = max(r1, d1[e]), r2 = min(r2, d2[e]), e--;
            s >>= 1, e >>= 1;
        }
        return {r1, r2};
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vi v(n);
    vector<ll> ss(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        v[i] = k - v[i];
    }
    IndexTree tre(n);

    for (int i = 0; i < n; i++) {
        ss[i] = v[i] + (i > 0 ? ss[i - 1] : 0);
        tre.up(i, ss[i]);
    }

    while (q--) {
        int s, e;
        cin >> s >> e;
        s--, e--;
        ll base = s == 0 ? 0 : ss[s-1];
        auto[a, b] = tre.read(s, e);

        ll r = 0;
        if (b < base || ss[e] - base != 0) r = -1;
        else r = a - base;

        cout << r << '\n';
    }


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

        solve();
}

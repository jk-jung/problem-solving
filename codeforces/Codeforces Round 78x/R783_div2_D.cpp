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
    vector<int> d;

    IndexTree(int _n) {
        init(_n);
    }

    void init(int _n) {
        if (_n <= 0)return;
        n = _n;
        size = 1 << (32 - __builtin_clz(n));
        d.resize(size * 2 + 5, -(1 << 30));
    }

    void up(int x, int v) {
        x += size;
        d[x] = max(d[x], v);
        x /= 2;
        while (x) d[x] = max(d[x * 2], d[x * 2 + 1]), x >>= 1;
    }

    int read(int s, int e) {
        s += size, e += size;
        int r = -(1 << 30);
        while (s <= e) {
            if ((s & 1) == 1) r = max(r, d[s++]);
            if ((e & 1) == 0) r = max(r, d[e--]);
            s >>= 1, e >>= 1;
        }
        return r;
    }
};


void solve() {
    int n;
    cin >> n;
    vi v(n), d(n + 1, -(1 << 30));
    vector<ll> ss;
    for (int &x: v)cin >> x;

    ss.pb(-(1 << 30));
    ss.pb(0);
    for (ll i = 0, s = 0; i < n; i++) {
        s += v[i];
        ss.pb(s);
    }
    sort(ss.begin(), ss.end());
    ss.erase(unique(ss.begin(), ss.end()), ss.end());

    IndexTree tre(ss.size());
    d[0] = 0;
    ll s = 0;

    int idx = lower_bound(ss.begin(), ss.end(), 0) - ss.begin();
    tre.up(idx, 0);
    for (int i = 1; i <= n; i++) {
        s += v[i - 1];

        idx = lower_bound(ss.begin(), ss.end(), s - 1) - ss.begin();
        if (ss[idx] > s - 1)idx--;

        if (v[i - 1] == 0)d[i] = d[i - 1];
        else if (v[i - 1] < 0)d[i] = d[i - 1] - 1;

        d[i] = max(d[i], tre.read(0, idx) + i);

        idx = lower_bound(ss.begin(), ss.end(), s) - ss.begin();
        tre.up(idx, d[i] - i);
    }

    cout << d[n] << endl;
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

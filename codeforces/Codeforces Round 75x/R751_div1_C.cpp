#include <string.h>
#include <stdio.h>
#include <math.h>
#include <cassert>
#include <set>
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

class FenwickTree {
public:
    vector<int> d;

    void init(int n) {
        d.clear(), d.resize(2 * n + 5);
    }

    void up(int x, int v) {
        for (; x < d.size(); x |= x + 1) d[x] += v;
    }

    int read(int x) {
        int r = 0;
        for (; x >= 0; x = (x & (x + 1)) - 1)
            r += d[x];
        return r;
    }
};

class SegmentTree {
public:
    vector<int> vv, vp;
    int max_n;

    SegmentTree(vi &v) {
        max_n = v.size();
        int size = 1;
        for (; size < max_n; size *= 2);
        vv.clear(), vv.resize(size * 2 + 5);
        vp.clear(), vp.resize(size * 2 + 5);

        build(v, 0, 0, max_n);
    }

    void build(vi& v, int k, int l, int r) {
        if(l > r)return;
        if (l == r) {
            vv[k] = v[l];
        } else {
            int m = (l + r) / 2;
            build(v, k * 2 + 1, l, m);
            build(v, k * 2 + 2, m + 1, r);
        }
        update(k, l, r);
    }

    void init(int _max_n) {
        max_n = _max_n;
        int size = 1;
        for (; size < max_n; size *= 2);
        vv.clear(), vv.resize(size * 2 + 5);
        vp.clear(), vp.resize(size * 2 + 5);
    }

    void up(int s, int e, int v) {
        up(s, e, v, 0, 0, max_n);
    }

    void up(int s, int e, int v, int k, int l, int r) {
        push_down(k, l, r);
        if (r < l || r < s || e < l) return;
        if (s <= l && r <= e) {
            vv[k] += v;
            vp[k] += v;
        } else {
            int m = (l + r) / 2;
            up(s, e, v, k * 2 + 1, l, m);
            up(s, e, v, k * 2 + 2, m + 1, r);
        }
        update(k, l, r);
    }

    void update(int k, int l, int r) {
        if (l != r) {
            push_down(k, l, r);
            vv[k] = min(vv[k * 2 + 1], vv[k * 2 + 2]);
        }
    }

    void push_down(int k, int l, int r) {
        if (l != r) {
            int ll = k * 2 + 1, rr = k * 2 + 2;
            vv[ll] += vp[k];
            vv[rr] += vp[k];
            vp[ll] += vp[k];
            vp[rr] += vp[k];
        }
        vp[k] = 0;
    }

    int read(int s, int e) {
        return read(s, e, 0, 0, max_n);
    }

    int read(int s, int e, int k, int l, int r) {
        push_down(k, l, r);
        int rst = 1 << 30;
        if (r < l || r < s || e < l) return rst;
        if (s <= l && r <= e) rst = min(rst, vv[k]);
        else {
            int m = (l + r) / 2;
            rst = min(rst, read(s, e, k * 2 + 1, l, m));
            rst = min(rst, read(s, e, k * 2 + 2, m + 1, r));
        }
        return rst;
    }
};

FenwickTree t1;
void solve() {
    int n, m;
    cin >> n >> m;
    vi a(n), b(m), c(n);

    vector<pi> v(n);
    for (int i = 0; i < n; i++)cin >> a[i], v[i] = {a[i], i}, c[i] = a[i];
    for (int i = 0; i < m; i++)cin >> b[i];


    sort(b.begin(), b.end());
    sort(v.begin(), v.end());

    sort(c.begin(), c.end());
    c.erase(unique(c.begin(), c.end()), c.end());

    t1.init(n);
    ll r = 0;
    for (int x: a) {
        int y = lower_bound(c.begin(), c.end(), x) - c.begin();
        r += t1.read(n);
        r -= t1.read(y);
        t1.up(y, 1);
    }

    vi vv(n+1);
    int cnt = 0;
    for (int x: a) if (x < b[0])cnt++;
    vv[0] = cnt;
    for (int i = 1; i <= n; i++) {
        if (a[i - 1] < b[0])cnt--;
        if (a[i - 1] > b[0])cnt++;
        vv[i] = cnt;
    }
    SegmentTree tre(vv);

    int pos1 = 0;
    int pos2 = 0;
    while (pos1 < v.size() && v[pos1].F < b[0]) pos1++;
    while (pos2 < v.size() && v[pos2].F <= b[0]) pos2++;


    for (int x: b) {
        while (pos1 < v.size() && v[pos1].F < x) {
            tre.up(0, v[pos1++].S, +1);
        }
        while (pos2 < v.size() && v[pos2].F <= x) {
            tre.up(v[pos2++].S + 1, n, -1);
        }

        r += tre.read(0, n); // find min
    }
    cout << r << '\n';
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

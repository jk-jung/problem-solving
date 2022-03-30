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
        if (_n == 0) return;
        n = _n;
        size = 1 << (32 - __builtin_clz(n));
        d.resize(size * 2 + 5);
    }

    void up(int x, int v) {
        x += size;
        d[x] = v;
        x /= 2;
        while (x) d[x] = min(d[x * 2], d[x * 2 + 1]), x >>= 1;
    }

    int read(int s, int e) {
        s += size, e += size;
        int r = 1 << 30;
        while (s <= e) {
            if ((s & 1) == 1) r = min(r, d[s++]);
            if ((e & 1) == 0) r = min(r, d[e--]);
            s >>= 1, e >>= 1;
        }
        return r;
    }
};


void solve() {
    int n, m;
    cin >> n >> m;
    ll s = 0;
    map<ll, int> idx;
    vector<ll> v;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        s += x;
        if (s > 0 && !idx.count(s))idx[s] = i;
    }

    IndexTree tre(idx.size());

    int cnt = 0;
    for (auto[k, i]: idx) {
        v.pb(k);
        tre.up(cnt++, i);
    }

    while (m--) {
        int x;
        cin >> x;
        ll r = 0;
        if (v.empty())r = -1;
        else {
            ll M = v.back();
            ll need = x;
            if (s > 0) {
                ll base = max(0ll, (x - M + s - 1) / s);
                r += base * n;
                need -= base * s;
            }
            int i = lower_bound(v.begin(), v.end(), need) - v.begin();
            while (i < v.size() && v[i] < need)i++;
            if (i == v.size()) r = -1;
            else {
                r += tre.read(i, int(v.size()) - 1);
            }
        }

        cout << r << " ";
    }
    cout << endl;
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

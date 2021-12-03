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


const ll MAX = 1ll << 60;

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
        d.resize(size * 2 + 5, MAX);
    }

    void up(int x, ll v) {
        x += size;
        d[x] = v;
        x >>= 1;
        while (x) d[x] = min(d[x * 2], d[x * 2 + 1]), x >>= 1;
    }

    ll read(int s, int e) {
        s += size, e += size;
        ll r = MAX;
        while (s <= e) {
            if ((s & 1) == 1) r = min(r, d[s++]);
            if ((e & 1) == 0) r = min(r, d[e--]);
            s >>= 1, e >>= 1;
        }
        return r;
    }

    int find(int s, ll ss) {
        int e = n - 1, r = -1;
        while (s <= e) {
            int m = (s + e) / 2;
            if (read(s, m) >= ss) r = m, s = m + 1;
            else e = m - 1;
        }
        return r;
    }
};

void solve() {
    int n;
    ll ss = 0, s;
    cin >> n >> s;
    vi v(n);
    IndexTree tre(n);

    for (int &x: v)cin >> x;
    for (int i = 0; i < n; i++) {
        ss += v[i];
        tre.up(i, ss);
    }
    int l = -1, r = -2;
    s = -s;
    for (int i = 0; i < n; i++) {
        int x = tre.find(i, s);
        if(r - l < x - i) {
            l = i + 1;
            r = x + 1;
        }
        s += v[i];
    }

    cout << l;
    if (l > 0) cout << " " << r;
    cout << '\n';
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

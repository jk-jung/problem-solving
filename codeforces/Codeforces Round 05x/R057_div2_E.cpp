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


class FenwickTree {
public:
    vector<ll> d;

    void init(int n) {
        d.clear(), d.resize(2 * n + 5);
    }

    void up(int x, ll v) {
        for (; x < d.size(); x |= x + 1) d[x] += v;
    }

    ll read(ll x) {
        ll r = 0;
        for (; x >= 0; x = (x & (x + 1)) - 1)
            r += d[x];
        return r;
    }
};

void solve() {
    int n;
    cin >> n;
    vi v(n);
    for (int &x: v)cin >> x, x = -x;
    vi t = v;
    sort(t.begin(), t.end());
    ll r = 0;

    FenwickTree a, b;
    a.init(n), b.init(n);
    for (int x: v) {
        int p = lower_bound(t.begin(), t.end(), x) - t.begin();
        r += b.read(p);
        b.up(p, a.read(p));
        a.up(p, 1);
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}

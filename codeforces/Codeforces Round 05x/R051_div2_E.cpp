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

int n;
vector<pair<ll, ll>> v;
int idx[100005];
ll ss[100005];

bool is_ccw(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c) {
    return (b.F - a.F) * (c.S - a.S) - (b.S - a.S) * (c.F - a.F) > 0;
}

ll range_sum(ll s, ll e) {
    return ss[e] - (s == 0 ? 0 : ss[s - 1]);
}

void process() {
    ll x, y;
    cin >> x >> y;
    for (int i = 0; i < n; i++) {
        int s = i + 1, e = n - 1, r = i;
        while (s <= e) {
            int m = (s + e) / 2;
            if (!is_ccw(v[i], v[m], {x, y})) s = m + 1, r = m;
            else e = m - 1;
        }
        idx[i] = r;
        ss[i] = i == 0 ? r : ss[i - 1] + r;
    }
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        if (is_ccw(v[i], v[j], {x, y})) {
            cout << 0 << endl;
            return;
        }
    }

    ll r = 0;
    for (ll i = 0; i < n; i++) {
        ll j = idx[i];
        r += range_sum(i, j) - (j - i + 1) * idx[i];
    }
    cout << r << endl;
}

void solve() {
    cin >> n;
    v.resize(n);
    for (auto &[x, y]: v) {
        cin >> x >> y;
    }
    int t;
    cin >> t;
    while (t--)
        process();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}

#include <cstring>
#include <cstdio>
#include <cmath>
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

void solve() {
    ll n, t;
    cin >> n >> t;
    vector<ll> a(n), c(n), b(n), b0(n), b1(n, 1ll << 61);
    for (ll &x: a)cin >> x;
    for (ll &x: c)cin >> x, x--;

    set<ll> ck;
    for (ll i = 0; i < n; i++)ck.insert(i);
    for (ll i = n - 1; i >= 0; i--) {
        ll x = c[i];
        if (i > x) {
            cout << "No\n";
            return;
        }
        b0[i] = max(b0[i], a[i] + t);
        if (x + 1 < n) b1[x] = min(b1[x], a[x + 1] + t);
        auto it = ck.lower_bound(i + 1);
        vector<ll> rm;
        while (it != ck.end() && *it <= x) {
            ll j = *it;
            rm.pb(j);
            b0[j - 1] = a[j] + t;
            it++;
        }
        for (ll j: rm)ck.erase(j);
    }

    for (int i = n - 1; i >= 0; i--) {
        if (i + 1 < n)b1[i] = min(b1[i], b[i + 1]);
        if (b0[i] >= b1[i]) {
            cout << "No\n";
            return;
        }
        b[i] = b1[i] - 1;
    }
    cout << "Yes\n";
    for (ll x: b)cout << x << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}

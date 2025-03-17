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
typedef vector<ll> vi;

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define ab(x) (((x) < 0) ? -(x) : (x))

void solve() {
    ll n, m;
    cin >> n >> m;

    vi v(n), r(n);
    for (ll &x: v)cin >> x;
    for (ll &x: r)cin >> x;

    map<ll, ll> ck;
    for (ll i = 0; i < n; i++) {
        ll h = r[i];
        ll s = v[i] - h;
        ll e = v[i] + h;

        for (ll x = s; x <= e; x++) {
            ll a = ab(x - v[i]);
            ll y = ll(sqrt(h * h - a * a) + 1e-9);
            ck[x] = max(ck[x], y);
        }
    }
    ll rst = 0;
    for (auto [x, y]: ck) {
        rst += y * 2 + 1;
    }
    cout << rst << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}

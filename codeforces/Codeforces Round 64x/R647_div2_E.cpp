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


ll n, p;

ll pow_limit(ll x, ll y) {
    if (x == 1) return 1;
    ll r = 1;
    for (ll i = 0; i < y; i++) {
        r *= x;
        if (r > 1000000000ll) {
            r = 1000000000ll;
            break;
        }
    }
    return r;
}

ll mod = 1000000007;

ll pow(ll x, ll y) {
    ll r = 1;
    for (x = x % mod; y; y >>= 1, x = (x * x) % mod)
        if (y & 1) r = (r * x) % mod;
    return r;
}


ll calc(map<ll, ll> &m) {
    ll r = 0;
    for (auto [x, y]: m) {
        r = (r + pow(p, x) * y % mod) % mod;
    }
    return r;
}

void solve() {

    cin >> n >> p;
    vector<ll> v(n);
    map<ll, ll> ck, a, b;
    for (ll &x: v)cin >> x, ck[x]++;

    ll dif = 0, last = ck.rbegin()->F;
    for (auto it = ck.rbegin(); it != ck.rend(); it++) {
        auto [x, cnt] = *it;
        dif = dif * pow_limit(p, last - x);
        if (dif > 1000000000ll)dif = 1000000000ll;

        ll use = min(dif, cnt);

        if (use) {
            b[x] += use;
            dif -= use;
            cnt -= use;
        }

        if (cnt % 2) {
            a[x]++;
            dif++;
        }
        last = x;
    }

    ll r = (calc(a) - calc(b) + mod) % mod;
    cout << r << endl;
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

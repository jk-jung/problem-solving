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

ll mod = 998244353;
ll fac[200005];

class nCrModular {
public:
    ll mod;
    vector<ll> fac, facInv;

    nCrModular(int n, ll _mod) {
        mod = _mod;
        fac.resize(n + 1), facInv.resize(n + 1);

        fac[0] = 1;
        for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % mod;

        facInv[n] = inv(fac[n]);
        for (int i = n; i > 0; i--) facInv[i - 1] = facInv[i] * i % mod;
    }

    ll pow(ll x, ll y) {
        ll r = 1;
        for (x = x % mod; y; y >>= 1, x = (x * x) % mod)
            if (y & 1) r = (r * x) % mod;
        return r;
    }

    ll inv(ll x) { return pow(x, mod - 2); }

    ll nCr(ll n, ll r) {
        if (n < r || n < 0 || r < 0) return 0;
        if (r == 0) return 1;
        return fac[n] * facInv[r] % mod * facInv[n - r] % mod;
    }
} ncr(200000, mod);

void solve() {
    int n;
    cin >> n;
    vi v(n);
    for (int i = 0; i < n; i++)cin >> v[i];
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    if (v[0] > v[1] + 1) {
        cout << "0\n";
    } else if (v[0] == v[1]) {
        cout << fac[n] << '\n';
    } else {
        ll r = 0;
        int cnt = 0;
        for (int i = 1; i < n; i++)if (v[i] == v[1])cnt++;

        for (int i = 0; i + cnt < n; i++) {
            ll k = ncr.nCr(n - cnt - 1, i);
            ll f1 = fac[cnt + i];
            ll f2 = fac[n - cnt - i - 1];
            r = (r + f1 * f2 % mod * k % mod) % mod;
        }
        r = (fac[n] - r + mod) % mod;

        cout << r << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fac[0] = 1;
    for (int i = 1; i <= 200000; i++)fac[i] = fac[i - 1] * i % mod;

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}

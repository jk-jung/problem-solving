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


#define MOD 1000000007

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
} ncr(200000, MOD);


void solve() {
    ll n, k, r = 1;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        ll x = n - (k - 1) * (i - 1);
        ll t = ncr.inv(ncr.nCr(n, i));

        r = (r + ncr.nCr(x, i) * t % MOD) % MOD;
    }
    cout << r << endl;
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

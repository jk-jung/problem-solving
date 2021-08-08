#include <string.h>
#include <stdio.h>
#include <math.h>
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

#define MOD 998244353

class nCrModular {
public:
    vector<ll> fac, facInv;

    nCrModular(int n) {
        fac.resize(n + 1), facInv.resize(n + 1);

        fac[0] = 1;
        for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % MOD;
        facInv[n] = inv(fac[n]);
        for (int i = n; i > 0; i--) facInv[i - 1] = facInv[i] * i % MOD;
    }

    ll pow(ll x, ll y) {
        ll r = 1;
        for (x = x % MOD; y; y >>= 1, x = (x * x) % MOD) if (y & 1) r = (r * x) % MOD;
        return r;
    }

    ll inv(ll x) { return pow(x, MOD - 2); }

    ll nCr(ll n, ll r) {
        if (n < r || n < 0 || r < 0) return 0;
        if (r == 0) return 1;
        return fac[n] * facInv[r] % MOD * facInv[n - r] % MOD;
    }
} ncr(60000);

int n, m;
int a[22][50005];
int v[22];

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> a[i][j];

    ll r = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)v[j] = a[j][i];
        sort(v, v + n);
        ll t = 1;
        for (int j = 0; j < n; j++) {
            t = (t * ncr.nCr(v[j] - j - 1, 1)) % MOD;
        }
        t = (ncr.fac[n] - t + MOD) % MOD;
        r = (r + t) % MOD;
    }
    r = (r * ncr.facInv[n]) % MOD;
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}

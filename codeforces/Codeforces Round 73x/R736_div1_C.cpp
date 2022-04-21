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


#define MOD 1000000007

class Modular {
public:
    ll mod;
    vector<ll> fac, facInv;

    Modular(int n, ll _mod) {
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

    ll nCk(ll n, ll k) {
        if (n < k || n < 0 || k < 0) return 0;
        if (k == 0) return 1;
        return fac[n] * facInv[k] % mod * facInv[n - k] % mod;
    }

    ll nHk(ll n, ll k) {
        return nCk(n + k - 1, k);
    }
} md(3000000, MOD);

ll d[3000005][3];

void solve() {
    int n, q;
    cin >> n >> q;

    d[0][0] = d[0][1] = d[0][2] = n;
    ll t = md.inv(3);
    for (int i = 1; i <= 3 * n; i++) {
        ll tot = md.nCk(n * 3, i + 1) - 2 * d[i - 1][0] - d[i - 1][1];
        while (tot < 0)tot += MOD;

        d[i][0] = tot * t % MOD;
        d[i][1] = (d[i][0] + d[i - 1][0]) % MOD;
        d[i][2] = (d[i][1] + d[i - 1][1]) % MOD;
    }

    while (q--) {
        int x;
        cin >> x;
        cout << (d[x][0] + md.nCk(3 * n, x)) % MOD << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}

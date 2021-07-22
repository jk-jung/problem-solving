#include <string.h>
#include <stdio.h>
#include <math.h>
#include <map>
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
        fac.resize(n + 1);
        facInv.resize(n + 1);

        fac[0] = 1;
        for (int i = 1; i <= n; i++)
            fac[i] = fac[i - 1] * i % mod;

        facInv[n] = inv(fac[n]);
        for (int i = n; i > 0; i--)
            facInv[i - 1] = facInv[i] * i % mod;
    }

    ll pow(ll x, ll y) {
        ll r = 1;
        for (x = x % mod; y; y >>= 1, x = (x * x) % mod)
            if (y & 1) r = (r * x) % mod;
        return r;
    }

    ll inv(ll x) {
        return pow(x, mod - 2);
    }

    ll nCr(ll n, ll r) {
        if (n < r || n < 0 || r < 0) return 0;
        if (r == 0) return 1;
        return fac[n] * facInv[r] % mod * facInv[n - r] % mod;
    }
} ncr(200000, MOD);


void solve() {
    int n, s, e;
    cin >> n >> s >> e;

    int k = min(min(ab(s - 1), ab(e - 1)), min(ab(s - n), ab(e - n)));
    int L = 1, R = n, m1 = n / 2, m2 = (n + 1) / 2;
    ll r = 0;
    for (int i = 0; i <= m2 - m1; i++) {
        int need = m1 + i;
        r = (r + ncr.nCr(n, need) * k % MOD) % MOD;
    }

    for (k = k + 1;; k++) {
        if (!(s - L <= -k && k <= e - L)) L++;
        if (!(s - R <= -k && k <= e - R)) R--;
        if (R - L + 1 < 0) break;
        int plus = L - 1;
        int minus = n - R;
        if (plus > m2 || minus > m2) break;

        for (int i = 0; i <= m2 - m1; i++) {
            int need = m1 + i - plus;
            r = (r + ncr.nCr(R - L + 1, need)) % MOD;
        }
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

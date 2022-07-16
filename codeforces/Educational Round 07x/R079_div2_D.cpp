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

#define MOD 998244353

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
} md(1000000, MOD);


vi v[1000005];
int cnt[1000005];

void solve() {
    int n;
    cin >> n;
    for (int i = 0, m; i < n; i++) {
        cin >> m;
        v[i].resize(m);
        for (int &x: v[i]) {
            cin >> x;
            cnt[x]++;
        }
    }

//    ll f = md.fac[1000000];
//    ll b0 = 0, b1 = md.inv(n * f % MOD * n % MOD);
//    for (int i = 0; i < n; i++) {
//        ll iv = md.inv(v[i].size());
//        for (int x : v[i]) {
//            ll c = cnt[x];
//            b0 = (b0 + c * f % MOD * iv % MOD) % MOD;
//        }
//    }

    ll r = 0, inn = md.inv(n) * md.inv(n) % MOD;
    for (int i = 0; i < n; i++) {
        ll iv = md.inv(v[i].size());
        for (int x : v[i]) {
            ll c = cnt[x];
            r = (r + c * inn % MOD * iv % MOD) % MOD;
        }
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}

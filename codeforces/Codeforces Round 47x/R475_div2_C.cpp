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


#define MOD 1000000009

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
} md(2, MOD);

ll n, a, b, k, m;
string s;

ll calc(ll x, ll y) {
    ll r = 0;
    for (ll i = x; i < y; i++) {
        if (n - 1 - i < 0) return 0;
        ll c = md.pow(a, n - i - 1) * md.pow(b, i) % MOD;
        if (s[i % m] == '+') r = (r + c) % MOD;
        else r = (r - c + MOD) % MOD;
    }
    return r;
}

void solve() {
    cin >> n >> a >> b >> k >> s;
    n++;
    while (s.size() < 100000)s = s + s;
    m = s.size();

    ll r = 0;
    if (n % m != 0) r = calc(n / m * m, n);
    ll t = calc(0, m);
    for (ll i = 0; i < n / m; i++) {
        r = (r + t) % MOD;
        t = t * md.inv(md.pow(a, m)) % MOD * md.pow(b, m) % MOD;
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
